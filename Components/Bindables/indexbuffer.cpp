#include <Bindables/indexbuffer.h>

namespace Bind {
	IndexBuffer::IndexBuffer(const std::string& tag, const std::vector<uint32_t>& indices)
		:m_tag(tag), m_count(indices.size()) {
		m_buffer = ResourceFactory::CreateBuffer(indices.size() * sizeof(uint32_t), GL_DYNAMIC_STORAGE_BIT);
		m_buffer->Update(indices.size() * sizeof(uint32_t), 0, indices.data());
	}

	IndexBuffer::IndexBuffer(const std::string& tag, int count, std::shared_ptr<RawBuffer> buffer)
		:m_tag(tag), m_count(count) {
		m_buffer = buffer;
	}

	void IndexBuffer::Bind() noxnd {
		m_buffer->Bind(GL_ELEMENT_ARRAY_BUFFER);
	}

	std::string IndexBuffer::GetUID() const noexcept {
		return genID_impl(m_tag);
	}

	std::string IndexBuffer::genID_impl(const std::string& tag) {
		using namespace std::string_literals;
		return typeid(IndexBuffer).name() + "#"s + tag;
	}
}