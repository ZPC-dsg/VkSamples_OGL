#define DYNAMIC_CONSTANT_SOURCE_FILE

#include <Dynamic/dynamic_constant.h>

namespace Dynamic {
	namespace Dcb {
#ifdef _DEBUG
		std::string type_debug_output(LeafType type) {
			switch (type) {
#define X(Type,GLSLType,Code) case Type: return std::string(LeafMap<Type>::SysCode);
				TYPE_GENERATOR
#undef X
			case LeafType::Struct: return "Struct";
			case LeafType::Array: return "Array";
			default:
				return "???";
			}
		}

		std::string type_debug_output(GLenum type) {
			switch(type) {
#define X(Type,GLSLType,Code) case GLSLType: return std::string(LeafMap<Type>::SysCode);
				TYPE_GENERATOR
#undef X
			default:
				return "???";
			}
		}
#endif

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

		bool LayoutElement::Exists() const noexcept {
			return m_type != LeafType::Empty;
		}

		const LayoutElement& LayoutElement::operator[](const std::string& key) const noxnd {
			return const_cast<LayoutElement&>(*this)[key];
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
		}

		//ConstantLayoutElement
		std::string ConstantLayoutElement::GetSignatureForStruct() const noxnd {
			using namespace std::string_literals;
			auto sig = "St{"s;
			for (const auto& el : static_cast<ConstantExtraData::Struct&>(*m_extradata).m_elements)
			{
				sig += el.first + ":"s + el.second.GetSignature() + ";"s;
			}
			sig += "}"s;
			return sig;
		}

		std::string ConstantLayoutElement::GetSignatureForArray() const noxnd {
			using namespace std::string_literals;
			const auto& data = static_cast<ConstantExtraData::Array&>(*m_extradata);
			return "Ar:"s + std::to_string(data.m_elements.size()) + "{"s + data.m_elements[0].GetSignature() + "}"s;
		}

		size_t ConstantLayoutElement::GetSizeInBytes() const noxnd {
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

		size_t ConstantLayoutElement::GetOffsetEnd() const noxnd {
			assert(m_type != LeafType::Empty);

			switch (m_type) {
#define X(Type,GLSLType,Code) case Type:return m_offset.value() + LeafMap<Type>::SysSize;
				TYPE_GENERATOR;
#undef X
			case LeafType::Struct:
				return static_cast<ConstantExtraData::Struct&>(*m_extradata).m_elements.back().second.GetOffsetEnd();
				return static_cast<ConstantExtraData::Array&>(*m_extradata).m_elements.back().GetOffsetEnd();
				assert("Invalid element type to retrieve offset!" && false);
				return 0;
			}
		}

		LayoutElement& ConstantLayoutElement::operator[](const std::string& key) noxnd {
			assert("Keying into non-struct!" && m_type == LeafType::Struct);
			for (auto& mem : static_cast<ConstantExtraData::Struct&>(*m_extradata).m_elements) {//需要加上引用，因为LayoutElement类具有unique_ptr成员，无法拷贝
				if (mem.first == key) {
					return mem.second;
				}
			}
			return GetEmptyElement();
		}

		LayoutElement& ConstantLayoutElement::operator[](size_t index) noxnd {
			assert("Keying into non-array!" && m_type == LeafType::Array);
			auto& p = static_cast<ConstantExtraData::Array&>(*m_extradata);
			return p.m_elements[index];
		}

		ConstantLayoutElement::ConstantLayoutElement(LeafType type, size_t offset)
			:LayoutElement(type, offset)
		{
			assert(type != Empty);
			if (type == LeafType::Struct)
			{
				m_extradata = std::unique_ptr<ConstantExtraData::Struct>{ new ConstantExtraData::Struct() };
			}
			else if (type == LeafType::Array)
			{
				m_extradata = std::unique_ptr<ConstantExtraData::Array>{ new ConstantExtraData::Array() };
			}
		}

		void ConstantLayoutElement::AppendChild(const Dynamic::Dsr::ConstantTreeNode& root, const Dynamic::Dsr::ConstantEntryPoint& entry) {
			switch (m_type) {
#define X(Type,GLSLType,Code) case Type:
				TYPE_GENERATOR
#undef X
					return;
			case LeafType::Struct: {
				auto& p = static_cast<ConstantExtraData::Struct&>(*m_extradata);
				for (int i = 0; i < root.ChildrenAmount(); i++) {
					const auto& child = root[i];
					if (child.IsLeaf()) {
						const auto& attrib = entry[child.GetRange().first];
						p.m_elements.emplace_back(attrib.name, ConstantLayoutElement(GLSLTypeToLeafType(attrib.type), attrib.offset));
					}
					else if (std::string name; child.IsStruct(name)) {//Struct的offset设置为第一个子元素的offset
						size_t offset = entry[child.GetRange().first].offset;
						p.m_elements.emplace_back(name, ConstantLayoutElement(LeafType::Struct, offset));
						p.m_elements.back().second.AppendChild(child, entry);
					}
					else {
						size_t offset = entry[child.GetRange().first].offset;
						p.m_elements.emplace_back(name, ConstantLayoutElement(LeafType::Array, offset));
						p.m_elements.back().second.AppendChild(child, entry);
					}
				}
				return;
			}
			case LeafType::Array: {
				auto& arr = static_cast<ConstantExtraData::Array&>(*m_extradata);
				for (int i = 0; i < root.ChildrenAmount(); i++) {
					const auto& child = root[i];
					if (child.IsLeaf()) {
						const auto& attrib = entry[child.GetRange().first];
						arr.m_elements.emplace_back(ConstantLayoutElement(GLSLTypeToLeafType(attrib.type), attrib.offset));
					}
					else if (std::string name; child.IsStruct(name)) {
						size_t offset = entry[child.GetRange().first].offset;
						arr.m_elements.emplace_back(ConstantLayoutElement(LeafType::Struct, offset));
						arr.m_elements.back().AppendChild(child, entry);
					}
					else {
						size_t offset = entry[child.GetRange().first].offset;
						arr.m_elements.emplace_back(ConstantLayoutElement(LeafType::Array, offset));
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

		//UniformLayoutElement
		std::string UniformLayoutElement::GetSignatureForStruct() const noxnd {
			using namespace std::string_literals;
			auto sig = "St{"s;
			for (const auto& el : static_cast<UniformExtraData::Struct&>(*m_extradata).m_elements)
			{
				sig += el.first + ":"s + el.second.GetSignature() + ";"s;
			}
			sig += "}"s;
			return sig;
		}

		std::string UniformLayoutElement::GetSignatureForArray() const noxnd {
			using namespace std::string_literals;
			const auto& data = static_cast<UniformExtraData::Array&>(*m_extradata);
			return "Ar:"s + std::to_string(data.m_elements.size()) + "{"s + data.m_elements[0].GetSignature() + "}"s;
		}

		LayoutElement& UniformLayoutElement::operator[](const std::string& key) noxnd {
			assert("Keying into non-struct!" && m_type == LeafType::Struct);
			for (auto& mem : static_cast<UniformExtraData::Struct&>(*m_extradata).m_elements) {//需要加上引用，因为LayoutElement类具有unique_ptr成员，无法拷贝
				if (mem.first == key) {
					return mem.second;
				}
			}
			return GetEmptyElement();
		}

		LayoutElement& UniformLayoutElement::operator[](size_t index) noxnd {
			assert("Keying into non-array!" && m_type == LeafType::Array);
			auto& p = static_cast<UniformExtraData::Array&>(*m_extradata);
			return p.m_elements[index];
		}

		UniformLayoutElement::UniformLayoutElement(LeafType type, size_t offset, std::optional<GLint> location)
			:LayoutElement(type, offset), m_location(location)
		{
			assert(type != Empty);
			if (type == LeafType::Struct)
			{
				m_extradata = std::unique_ptr<UniformExtraData::Struct>{ new UniformExtraData::Struct() };
			}
			else if (type == LeafType::Array)
			{
				m_extradata = std::unique_ptr<UniformExtraData::Array>{ new UniformExtraData::Array() };
			}
		}

		void UniformLayoutElement::AppendChild(const Dynamic::Dsr::ConstantTreeNode& root, const Dynamic::Dsr::UniformEntryPoint& entry) {
			switch (m_type) {
#define X(Type,GLSLType,Code) case Type:
				TYPE_GENERATOR
#undef X
					return;
			case LeafType::Struct: {
				auto& p = static_cast<UniformExtraData::Struct&>(*m_extradata);
				for (int i = 0; i < root.ChildrenAmount(); i++) {
					const auto& child = root[i];
					if (child.IsLeaf()) {
						const auto& attrib = entry[child.GetRange().first];
						p.m_elements.emplace_back(attrib.name, UniformLayoutElement(GLSLTypeToLeafType(attrib.type), child.GetRange().first, attrib.location));
					}
					else if (std::string name; child.IsStruct(name)) {//Struct的offset设置为第一个子元素的offset
						p.m_elements.emplace_back(name, UniformLayoutElement(LeafType::Struct, child.GetRange().first));
						p.m_elements.back().second.AppendChild(child, entry);
					}
					else {
						p.m_elements.emplace_back(name, UniformLayoutElement(LeafType::Array, child.GetRange().first));
						p.m_elements.back().second.AppendChild(child, entry);
					}
				}
				return;
			}
			case LeafType::Array: {
				auto& arr = static_cast<UniformExtraData::Array&>(*m_extradata);
				for (int i = 0; i < root.ChildrenAmount(); i++) {
					const auto& child = root[i];
					if (child.IsLeaf()) {
						const auto& attrib = entry[child.GetRange().first];
						arr.m_elements.emplace_back(UniformLayoutElement(GLSLTypeToLeafType(attrib.type), child.GetRange().first, attrib.location));
					}
					else if (std::string name; child.IsStruct(name)) {
						arr.m_elements.emplace_back(UniformLayoutElement(LeafType::Struct, child.GetRange().first));
						arr.m_elements.back().AppendChild(child, entry);
					}
					else {
						arr.m_elements.emplace_back(UniformLayoutElement(LeafType::Array, child.GetRange().first));
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

		//Layout
		std::string Layout::GetSignature() const noxnd {
			return m_root->GetSignature();
		}

		LayoutElement& Layout::operator[](const std::string& name) noxnd {
			return (*m_root)[name];
		}

		const LayoutElement& Layout::operator[](const std::string& name) const noxnd {
			return const_cast<Layout&>(*this)[name];
		}

		//ConstantLayout
		ConstantLayout::ConstantLayout(const Dynamic::Dsr::ConstantEntryPoint& entry) {
			m_root = std::shared_ptr<LayoutElement>(new ConstantLayoutElement(LeafType::Struct, 0u));//ConstantLayout构造函数私有，无法使用make_shared
			std::dynamic_pointer_cast<ConstantLayoutElement>(m_root)->AppendChild(*(entry.RootNode()), entry);
		}

		size_t ConstantLayout::GetSizeInBytes() const noexcept {
			return std::dynamic_pointer_cast<ConstantLayoutElement>(m_root)->GetSizeInBytes();
		}

		//UniformLayout
		UniformLayout::UniformLayout(const Dynamic::Dsr::UniformEntryPoint& entry) {
			m_leafs.reserve(entry.AttribAmount());

			if (entry.RootNode()->IsLeaf()) {
				switch (entry[0].type) {
#define X(Type,GLSLType,Code) case GLSLType: m_root=std::shared_ptr<UniformLayoutElement>(new UniformLayoutElement(ReverseLeafMap<typename GLSLTypeMap<GLSLType>::ConvType>::SysType, 0, entry[0].location)); break;
					TYPE_GENERATOR
#undef X
				}
				m_leafs.push_back(static_cast<UniformLayoutElement&>(*m_root));
			}
			else if (std::string name; entry.RootNode()->IsStruct(name)) {
				m_root = std::shared_ptr<LayoutElement>(new UniformLayoutElement(LeafType::Struct, 0));
				std::static_pointer_cast<UniformLayoutElement>(m_root)->AppendChild(*(entry.RootNode()), entry);
			}
			else {
				m_root = std::shared_ptr<LayoutElement>(new UniformLayoutElement(LeafType::Array, 0));
				std::static_pointer_cast<UniformLayoutElement>(m_root)->AppendChild(*(entry.RootNode()), entry);
			}

			ConstructLeafVector(static_cast<const UniformLayoutElement&>(*m_root));
		}

		void UniformLayout::ConstructLeafVector(const UniformLayoutElement& node) {
			if (node.IsLeaf()) {
				m_leafs.push_back(const_cast<UniformLayoutElement&>(node));
			}
			else if (node.GetType() == LeafType::Struct) {
				const auto& extra = static_cast<UniformExtraData::Struct&>(*node.m_extradata);
				for (const auto& p : extra.m_elements) {
					ConstructLeafVector(p.second);
				}
			}
			else {
				const auto& extra = static_cast<UniformExtraData::Array&>(*node.m_extradata);
				for (const auto& ele : extra.m_elements) {
					ConstructLeafVector(ele);
				}
			}
		}

		LayoutElement& UniformLayout::operator[](const std::string& key) noxnd {
			assert(m_root->GetType() == LeafType::Struct);

			return Layout::operator[](key);
		}

		LayoutElement& UniformLayout::operator[](size_t index) noxnd {
			assert(m_root->GetType() == LeafType::Array);

			return (*m_root)[index];
		}

		const LayoutElement& UniformLayout::operator[](size_t index) const noxnd {
			return const_cast<UniformLayout&>(*this)[index];
		}

		void UniformLayout::ClearAllFlags() noxnd {
			for (auto p : m_leafs) {
				p.get().SetDirtyFlag(false);
			}
		}

		LeafType UniformLayout::Type(size_t index) const noxnd { 
			assert(index < m_leafs.size());
			return m_leafs[index].get().GetType(); 
		}

		bool UniformLayout::LeafIsDirty(size_t index) const noxnd {
			assert(index < m_leafs.size());
			return (m_leafs[index]).get().IsDirty();
		}

		GLint UniformLayout::LeafLocation(size_t index) const noxnd {
			assert(index < m_leafs.size());
			return (m_leafs[index]).get().GetLocation();
		}

		//ConstElementRef
		template <typename Derived>
		bool ConstElementRef<Derived>::Exists() const noexcept
		{
			return m_layout->Exists();
		}

		template <typename Derived>
		ConstElementRef<Derived>::Ptr ConstElementRef<Derived>::operator&() const noxnd {
			return Ptr{ this };
		}

		template <typename Derived>
		ConstElementRef<Derived>::ConstElementRef(const LayoutElement* layout) 
			:m_layout(layout)
		{
		}

		template <typename Derived>
		ConstElementRef<Derived>::Ptr::Ptr(const ConstElementRef<Derived>* ref) noexcept :m_ref(ref){}

		//ConstConstantElementRef
		ConstConstantElementRef ConstConstantElementRef::operator[](const std::string& key) const noxnd {
			return { &(*(this->m_layout))[key],m_data };
		}

		ConstConstantElementRef ConstConstantElementRef::operator[](size_t index) const noxnd {
			return { &(*(this->m_layout))[index],m_data };
		}

		ConstConstantElementRef::ConstConstantElementRef(const LayoutElement* layout, const char* data)
			:ConstElementRef<ConstConstantElementRef>(layout), m_data(data)
		{
		}

		//ConstUniformElementRef
		ConstUniformElementRef ConstUniformElementRef::operator[](const std::string& key) const noxnd {
			return { &(*(this->m_layout))[key],m_data };
		}

		ConstUniformElementRef ConstUniformElementRef::operator[](size_t index) const noxnd {
			return { &(*(this->m_layout))[index],m_data };
		}

		ConstUniformElementRef::ConstUniformElementRef(const LayoutElement* layout, const AvailableType* data)
			:ConstElementRef<ConstUniformElementRef>(layout), m_data(data)
		{
		}

		//ElementRef
		template <typename Derived>
		bool ElementRef<Derived>::Exists() const noexcept {
			return m_layout->Exists();
		}

		template <typename Derived>
		ElementRef<Derived>::Ptr ElementRef<Derived>::operator&() noxnd {
			return Ptr(this);
		}

		template <typename Derived>
		ElementRef<Derived>::ElementRef(LayoutElement* layout)
			:m_layout(layout)
		{
		}

		template <typename Derived>
		ElementRef<Derived>::Ptr::Ptr(ElementRef<Derived>* ref) noexcept : m_ref(ref){}

		//ConstantElementRef

		ConstantElementRef::operator ConstConstantElementRef() const noxnd {
			return { this->m_layout,m_data };
		}

		ConstantElementRef ConstantElementRef::operator[](const std::string& key) noxnd {
			return { &(*(this->m_layout))[key],m_data };
		}

		ConstantElementRef ConstantElementRef::operator[](size_t index) noxnd {
			return { &(*(this->m_layout))[index],m_data };
		}

		ConstantElementRef::ConstantElementRef(LayoutElement* layout, char* data)
			:ElementRef<ConstantElementRef>(layout), m_data(data)
		{
		}

		//UniformElementRef
		UniformElementRef::operator ConstUniformElementRef() const noxnd {
			return { this->m_layout,m_data };
		}

		UniformElementRef UniformElementRef::operator[](const std::string& key) noxnd {
			return { &(*(this->m_layout))[key],m_data };
		}

		UniformElementRef UniformElementRef::operator[](size_t index) noxnd {
			return { &(*(this->m_layout))[index],m_data };
		}

		UniformElementRef::UniformElementRef(LayoutElement* layout, AvailableType* data)
			:ElementRef<UniformElementRef>(layout), m_data(data)
		{
		}

		//CPUConstantBuffer
		CPUConstantBuffer::CPUConstantBuffer(const Dynamic::Dsr::ConstantEntryPoint& entry) {
			ConstantLayout layout(entry);
			m_root = std::static_pointer_cast<ConstantLayoutElement>(layout.ShareRoot());
			m_data.resize(m_root->GetOffsetEnd());
		}

		ConstantElementRef CPUConstantBuffer::operator[](const std::string& key) noxnd {
			return ConstantElementRef(&(*m_root)[key], m_data.data());
		}

		ConstConstantElementRef CPUConstantBuffer::operator[](const std::string& key) const noxnd {
			return const_cast<CPUConstantBuffer&>(*this)[key];
		}

		void CPUConstantBuffer::CopyFrom(const CPUConstantBuffer& rhs) noxnd {
			assert(&GetRootElement() == &rhs.GetRootElement());
			std::copy(rhs.m_data.begin(), rhs.m_data.end(), m_data.begin());
		}

		//CPUUniformBlock
		CPUUniformBlock::CPUUniformBlock(const Dynamic::Dsr::UniformEntryPoint& entry) 
			:m_layout(std::shared_ptr<UniformLayout>(new UniformLayout(entry)))
		{
			m_data.resize(entry.AttribAmount());
			for (int i = 0; i < m_data.size(); i++) {
				InitializeVariant(m_data[i], entry[i].type);
			}
		}

		UniformElementRef CPUUniformBlock::operator[](const std::string& key) noxnd {
			m_is_dirty = true;
			return { &((*m_layout)[key]),m_data.data()};
		}

		ConstUniformElementRef CPUUniformBlock::operator[](const std::string& key) const noxnd {
			return { &((*m_layout)[key]),m_data.data()};
		}

		UniformElementRef CPUUniformBlock::operator[](size_t index) noxnd {
			m_is_dirty = true;
			return { &(*m_layout)[index],m_data.data()};
		}

		ConstUniformElementRef CPUUniformBlock::operator[](size_t index) const noxnd {
			return { &(*m_layout)[index],m_data.data()};
		}

		void CPUUniformBlock::CopyFrom(const CPUUniformBlock& rhs) noxnd {
			assert(&GetRootElement() == &rhs.GetRootElement());
			m_is_dirty = true;
			m_data = rhs.GetData();
		}

		void CPUUniformBlock::ClearAllFlags() noxnd {
			m_layout->ClearAllFlags();
			m_is_dirty = false;
		}

		LeafType CPUUniformBlock::UniformType(size_t index) const noxnd {
			return m_layout->Type(index);
		}

		bool CPUUniformBlock::UniformIsDirty(size_t index) const noxnd {
			return m_layout->LeafIsDirty(index);
		}

		const AvailableType& CPUUniformBlock::UniformInformation(size_t index, GLint& location) const noxnd {
			location = m_layout->LeafLocation(index);
			return m_data[index];
		}

		void CPUUniformBlock::InitializeVariant(AvailableType& element, GLenum type) {
			switch (type) {
#define X(Type,GLSLType,Code) case GLSLType: element = GLSLTypeMap<GLSLType>::ConvType(); return;
				TYPE_GENERATOR
#undef X
			default:
				return;
			}
		}
	}
}

#undef DYNAMIC_CONSTANT_SOURCE_FILE