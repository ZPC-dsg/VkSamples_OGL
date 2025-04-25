#include <Dynamic/dynamic_vertex.h>

namespace Dynamic {
	namespace Dvtx {
		//VertexLayout
		const VertexLayout::Element& VertexLayout::ResolveByIndex(size_t i) const noxnd
		{
			return m_elements[i];
		}

		VertexLayout& VertexLayout::Append(Dynamic::Dsr::VertexAttrib attrib) noxnd
		{
			if (!Has(attrib.type, attrib.name))
			{
				m_elements.emplace_back(attrib, m_input_steppingtype == VertexLayout::InputSteppingType::Interleaved ? InterleavedSize() : ContinuousSize());
			}
			return *this;
		}

		bool VertexLayout::Has(GLenum type, std::string name) const noexcept
		{
			for (auto& e : m_elements)
			{
				if (e.GetType() == type && e.GetName() == name)
				{
					return true;
				}
			}
			return false;
		}

		size_t VertexLayout::InterleavedSize() const noxnd
		{
			return m_elements.empty() ? 0u : m_elements.back().GetOffsetAfter();
		}

		size_t VertexLayout::ContinuousSize() const noxnd {
			return m_elements.empty() ? 0u : m_elements.back().GetOffset() + m_vertex_count * m_elements.back().Size();
		}

		size_t VertexLayout::VertexSize() const noxnd {
			int size = 0;
			for (const auto& ele : m_elements) {
				size += ele.Size();
			}
			return size;
		}

		std::vector<OGL_INPUT_ELEMENT_DESC> VertexLayout::GetOGLLayout() const noxnd {
			std::vector<OGL_INPUT_ELEMENT_DESC> desc;
			desc.reserve(GetElementCount());
			for (const auto& e : m_elements) {
				desc.push_back(e.GetDesc());
			}
			return desc;
		}

		std::string VertexLayout::GetCode() const noxnd
		{
			std::string code;
			for (const auto& e : m_elements)
			{
				code += e.GetCode();
			}
			return code;
		}


		//VertexLayout::Element
		VertexLayout::Element::Element(const Dynamic::Dsr::VertexAttrib& attrib, size_t offset)
			:
			m_attrib(attrib),
			m_offset(offset)
		{
		}

		size_t VertexLayout::Element::GetOffsetAfter() const noxnd
		{
			return m_offset + Size();
		}

		size_t VertexLayout::Element::GetOffset() const
		{
			return m_offset;
		}

		size_t VertexLayout::Element::Size() const noxnd
		{
			return SizeOf(m_attrib.type);
		}

		template <GLenum type>
		struct SysSizeLookup {
			static constexpr auto Exec(std::string name) noexcept {
				return sizeof(VertexLayout::Map<type>::SysType);
			}
		};
		constexpr size_t VertexLayout::Element::SizeOf(GLenum type) noxnd
		{
			return Bridge<SysSizeLookup>(type, std::string());
		}

		template <GLenum type>
		struct CodeLookup {
			static constexpr auto Exec(std::string name) noexcept {
				return (name + std::string("_") + std::string(VertexLayout::Map<type>::code)).c_str();
			}
		};
		const char* Dvtx::VertexLayout::Element::GetCode() const noexcept
		{
			return Bridge<CodeLookup>(m_attrib.type, m_attrib.name);
		}

		template <GLenum type>
		struct DescGenerator {
			static constexpr OGL_INPUT_ELEMENT_DESC Exec(std::string name, Dynamic::Dsr::VertexAttrib attrib, size_t offset) noexcept {
				return { attrib.location, VertexLayout::Map<type>::row_ele_count, VertexLayout::Map<type>::col_ele_count,
					VertexLayout::Map<type>::ele_format, offset };
			}
		};
		OGL_INPUT_ELEMENT_DESC VertexLayout::Element::GetDesc() const noxnd {
			return Bridge<DescGenerator>(m_attrib.type, m_attrib.name, m_attrib, m_offset);
		}

		//CPUVertexBuffer
		CPUVertexBuffer::CPUVertexBuffer(std::vector<Dynamic::Dsr::VertexAttrib> attribs, unsigned int vertices,
			VertexLayout::InputClassification classification, VertexLayout::InputSteppingType type) noxnd {
			m_layout.SetInputClassification(classification).SetInputSteppingType(type).SetVertexCount(vertices);
			for (auto attrib : attribs) {
				m_layout.Append(attrib);
			}

			m_buffer.resize(m_layout.VertexSize() * vertices);
		}

		/*
		// Vertex
		Vertex::Vertex(char* pData, const VertexLayout& layout) noxnd
			: m_data(pData), m_layout(layout)
		{
			assert(pData != nullptr);
		}
		ConstVertex::ConstVertex(const Vertex& v) noxnd
			: m_vertex(v)
		{
		}

		Vertex CPUVertexBuffer::Back() noxnd
		{
			assert(m_buffer.size() != 0u);
			return Vertex(m_buffer.data() + m_buffer.size() - m_layout.InterleavedSize(), m_layout);
		}
		Vertex CPUVertexBuffer::Front() noxnd
		{
			assert(m_buffer.size() != 0u);
			return Vertex(m_buffer.data(), m_layout);
		}
		Vertex CPUVertexBuffer::operator[](size_t i) noxnd
		{
			assert(i < m_layout.GetCount());
			return Vertex(m_buffer.data() + m_layout.InterleavedSize() * i, m_layout);
		}
		ConstVertex CPUVertexBuffer::Back() const noxnd
		{
			return const_cast<CPUVertexBuffer*>(this)->Back();
		}
		ConstVertex CPUVertexBuffer::Front() const noxnd
		{
			return const_cast<CPUVertexBuffer*>(this)->Front();
		}
		ConstVertex CPUVertexBuffer::operator[](size_t i) const noxnd
		{
			return const_cast<CPUVertexBuffer&>(*this)[i];
		}
		*/
	}
}