#include <Bindables/vertexbuffer.h>

namespace Bind {
	VertexBuffer::VertexBuffer(const std::string& tag, const Dynamic::Dvtx::CPUVertexBuffer& buffer)
		:m_layout(buffer.get_layout()) {
		m_buffer = std::dynamic_pointer_cast<RawBuffer>(ResourceFactory::CreateBuffer(tag, buffer.BufferSize(), GL_DYNAMIC_STORAGE_BIT));
		m_buffer->Update(buffer.BufferSize(), 0, buffer.get_data());
	}

	VertexBuffer::VertexBuffer(const Dynamic::Dvtx::CPUVertexBuffer& layout, std::shared_ptr<RawBuffer> buffer) 
		:m_layout(layout.get_layout()) {
		m_buffer = buffer;
	}

	void VertexBuffer::Bind() noxnd {
		m_buffer->Bind(GL_ARRAY_BUFFER);
	}

	std::string VertexBuffer::GetUID() const noexcept {
		return genID_impl(resource_name());
	}

	const Dynamic::Dvtx::VertexLayout& VertexBuffer::get_layout() const noexcept {
		return m_layout;
	}

	std::string VertexBuffer::genID_impl(const std::string& tag) {
		using namespace std::string_literals;
		return typeid(VertexBuffer).name() + "#"s + tag;
	}
}