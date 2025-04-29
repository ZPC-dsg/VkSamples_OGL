#define DYNAMIC_CONSTANT_SOURCE_FILE

#include <Dynamic/dynamic_constant.h>

namespace Dynamic {
	namespace Dcb {
		//LayoutElement
		std::string LayoutElement::GetSignature() const noxnd {
			switch (m_type) {
#define X(Type,GLSLType,Code) case Type: return LeafMap<Type>::SysCode;
				TYPE_GENERATOR
#undef X
			case LeafType::Struct:
				return GetSignatureForStruct();
			case LeafType::Array:
				return GetSignatureForArray();
			default:
				assert("Bad type in signature generation!" && false);
				return "???";
			}
		}

		size_t LayoutElement::GetSizeInBytes() const noxnd {
			assert(m_type != LeafType::Empty);

			switch (m_type) {
#define X(Type,GLSLType,Code) case Type: return LeafMap<Type>::SysSize;
				TYPE_GENERATOR
#undef X
			case LeafType::Struct:
			case LeafType::Array:
				return GetOffsetEnd() - m_offset.value();
			default:
				assert("Invalid element type to retrieve size!" && false);
				return 0;
			}
		}

		size_t LayoutElement::GetOffsetEnd() const noxnd {
			assert(m_type != LeafType::Empty);

			switch (m_type) {
#define X(Type,GLSLType,Code) case Type:return m_offset.value() + LeafMap<Type>::SysSize;
				TYPE_GENERATOR;
#undef X
			case LeafType::Struct:
				return static_cast<ExtraData::Struct&>(*m_extradata).m_elements.back().second.GetOffsetEnd();
				return static_cast<ExtraData::Array&>(*m_extradata).m_elements.back().GetOffsetEnd();
				assert("Invalid element type to retrieve offset!" && false);
				return 0;
			}
		}

		bool LayoutElement::Exists() const noexcept {
			return m_type != LeafType::Empty;
		}

		LayoutElement& LayoutElement::operator[](const std::string& key) noxnd {
			assert("Keying into non-struct!" && m_type == LeafType::Struct);
			for (auto& mem : static_cast<ExtraData::Struct&>(*m_extradata).m_elements) {//需要加上引用，因为LayoutElement类具有unique_ptr成员，无法拷贝
				if (mem.first == key) {
					return mem.second;
				}
			}
			return GetEmptyElement();
		}

		const LayoutElement& LayoutElement::operator[](const std::string& key) const noxnd {
			return const_cast<LayoutElement&>(*this)[key];
		}

		LayoutElement& LayoutElement::operator[](size_t index) noxnd {
			assert("Keying into non-array!" && m_type == LeafType::Array);
			auto& p = static_cast<ExtraData::Array&>(*m_extradata);
			return p.m_elements[index];
		}

		const LayoutElement& LayoutElement::operator[](size_t index) const noxnd {
			return const_cast<LayoutElement&>(*this)[index];
		}

		LeafType LayoutElement::GLSLTypeToLeafType(GLenum type) noexcept {
			switch (type) {
#define X(Type,GLSLType,Code) case GLSLType: return Type;
				TYPE_GENERATOR
#undef X
			default:
				return LeafType::Empty;
			}
		}

		LayoutElement::LayoutElement(LeafType type, size_t offset)
			:m_type(type), m_offset(offset)
		{
			assert(type != Empty);
			if (type == LeafType::Struct)
			{
				m_extradata = std::unique_ptr<ExtraData::Struct>{new ExtraData::Struct()};
			}
			else if (type == LeafType::Array)
			{
				m_extradata = std::unique_ptr<ExtraData::Array>{ new ExtraData::Array() };
			}
		}

		void LayoutElement::AppendChild(const Dynamic::Dsr::ConstantTreeNode& root, const Dynamic::Dsr::ConstantEntryPoint& entry) {
			switch (m_type) {
#define X(Type,GLSLType,Code) case Type:
				TYPE_GENERATOR
#undef X
					return;
			case LeafType::Struct: {
				auto& p = static_cast<ExtraData::Struct&>(*m_extradata);
				for (int i = 0; i < root.ChildrenAmount(); i++) {
					const auto& child = root[i];
					if (child.IsLeaf()) {
						const auto& attrib = entry[child.GetRange().first];
						p.m_elements.emplace_back(attrib.name, LayoutElement(GLSLTypeToLeafType(attrib.type), attrib.offset));
					}
					else if (std::string name; child.IsStruct(name)) {//Struct的offset设置为第一个子元素的offset
						size_t offset = entry[child.GetRange().first].offset;
						p.m_elements.emplace_back(name, LayoutElement(LeafType::Struct, offset));
						p.m_elements.back().second.AppendChild(child, entry);
					}
					else {
						size_t offset = entry[child.GetRange().first].offset;
						p.m_elements.emplace_back(name, LayoutElement(LeafType::Array, offset));
						p.m_elements.back().second.AppendChild(child, entry);
					}
				}
				return;
			}
			case LeafType::Array: {
				auto& arr = static_cast<ExtraData::Array&>(*m_extradata);
				for (int i = 0; i < root.ChildrenAmount(); i++) {
					const auto& child = root[i];
					if (child.IsLeaf()) {
						const auto& attrib = entry[child.GetRange().first];
						arr.m_elements.emplace_back(LayoutElement(GLSLTypeToLeafType(attrib.type), attrib.offset));
					}
					else if (std::string name; child.IsStruct(name)) {
						size_t offset = entry[child.GetRange().first].offset;
						arr.m_elements.emplace_back(LayoutElement(LeafType::Struct, offset));
						arr.m_elements.back().AppendChild(child, entry);
					}
					else {
						size_t offset = entry[child.GetRange().first].offset;
						arr.m_elements.emplace_back(LayoutElement(LeafType::Array, offset));
						arr.m_elements.back().AppendChild(child, entry);
					}
				}
				return;
			}
			default:
				assert("Invalid type to append children!" && false);
				return;
			}
		}

		std::string LayoutElement::GetSignatureForStruct() const noxnd
		{
			using namespace std::string_literals;
			auto sig = "St{"s;
			for (const auto& el : static_cast<ExtraData::Struct&>(*m_extradata).m_elements)
			{
				sig += el.first + ":"s + el.second.GetSignature() + ";"s;
			}
			sig += "}"s;
			return sig;
		}

		std::string LayoutElement::GetSignatureForArray() const noxnd
		{
			using namespace std::string_literals;
			const auto& data = static_cast<ExtraData::Array&>(*m_extradata);
			return "Ar:"s + std::to_string(data.m_elements.size()) + "{"s + data.m_elements[0].GetSignature() + "}"s;
		}

		//Layout
		size_t Layout::GetSizeInBytes() const noexcept {
			return m_root->GetSizeInBytes();
		}

		std::string Layout::GetSignature() const noxnd {
			return m_root->GetSignature();
		}

		LayoutElement& Layout::operator[](const std::string& name) noxnd {
			return (*m_root)[name];
		}

		const LayoutElement& Layout::operator[](const std::string& name) const noxnd {
			return const_cast<Layout&>(*this)[name];
		}

		Layout::Layout(const Dynamic::Dsr::ConstantEntryPoint& entry) 
			:m_root(std::shared_ptr<LayoutElement>(new LayoutElement(LeafType::Struct, 0u)))//Layout构造函数私有，无法使用make_shared
		{
			m_root->AppendChild(*(entry.RootNode()), entry);
		}

		//ConstElementRef
		bool ConstElementRef::Exists() const noexcept
		{
			return m_layout->Exists();
		}

		ConstElementRef ConstElementRef::operator[](const std::string& key) const noxnd {
			return { &(*m_layout)[key],m_data };
		}

		ConstElementRef ConstElementRef::operator[](size_t index) const noxnd{
			return { &(*m_layout)[index],m_data };
		}

		ConstElementRef::Ptr ConstElementRef::operator&() const noxnd {
			return Ptr{ this };
		}

		ConstElementRef::ConstElementRef(const LayoutElement* layout, const char* data) 
			:m_layout(layout), m_data(data)
		{
		}

		ConstElementRef::Ptr::Ptr(const ConstElementRef* ref) noexcept :m_ref(ref){}

		//ElementRef
		bool ElementRef::Exists() const noexcept {
			return m_layout->Exists();
		}

		ElementRef::operator ConstElementRef() const noxnd {
			return { m_layout,m_data };
		}

		ElementRef ElementRef::operator[](const std::string& key) noxnd {
			return { &(*m_layout)[key],m_data };
		}

		ElementRef ElementRef::operator[](size_t index) noxnd {
			return { &(*m_layout)[index],m_data };
		}

		ElementRef::Ptr ElementRef::operator&() noxnd {
			return Ptr(this);
		}

		ElementRef::ElementRef(const LayoutElement* layout, char* data)
			:m_layout(layout), m_data(data)
		{
		}

		ElementRef::Ptr::Ptr(ElementRef* ref) noexcept : m_ref(ref){}

		//CPUConstantBuffer
		CPUConstantBuffer::CPUConstantBuffer(const Dynamic::Dsr::ConstantEntryPoint& entry)
		{
			Layout layout(entry);
			m_root = layout.ShareRoot();
			m_data.resize(m_root->GetOffsetEnd());
		}

		ElementRef CPUConstantBuffer::operator[](const std::string& key) noxnd {
			return ElementRef(&(*m_root)[key], m_data.data());
		}

		ConstElementRef CPUConstantBuffer::operator[](const std::string& key) const noxnd {
			return const_cast<CPUConstantBuffer&>(*this)[key];
		}

		void CPUConstantBuffer::CopyFrom(const CPUConstantBuffer& rhs) noxnd {
			assert(&GetRootElement() == &rhs.GetRootElement());
			std::copy(rhs.m_data.begin(), rhs.m_data.end(), m_data.begin());
		}
	}
}

#undef DYNAMIC_CONSTANT_SOURCE_FILE