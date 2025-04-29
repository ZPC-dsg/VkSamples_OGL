#include <Bindables/indexbuffer.h>

namespace Bind {
	IndexBuffer::IndexBuffer(const std::string& tag, const std::vector<uint32_t>& indices)
		:m_count(indices.size()) {
		m_buffer = std::dynamic_pointer_cast<RawBuffer>(ResourceFactory::CreateBuffer(tag, indices.size() * sizeof(uint32_t), GL_DYNAMIC_STORAGE_BIT));
		m_buffer->UpdateCopy(indices.size() * sizeof(uint32_t), 0, indices.data());
	}

	IndexBuffer::IndexBuffer(int count, std::shared_ptr<RawBuffer> buffer)
		:m_count(count) {
		m_buffer = buffer;
	}

	void IndexBuffer::Bind() noxnd {
		m_buffer->Bind(GL_ELEMENT_ARRAY_BUFFER);
	}

	std::string IndexBuffer::GetUID() const noexcept {
		return genID_impl(resource_name());
	}

	std::string IndexBuffer::genID_impl(const std::string& tag) {
		using namespace std::string_literals;
		return typeid(IndexBuffer).name() + "#"s + tag;
	}
}