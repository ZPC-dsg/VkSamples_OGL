#include <resourcefactory.h>
#include <init.h>

ResourceFactory& MainFactory = ResourceFactory::GetInstance();

std::shared_ptr<RawBuffer> ResourceFactory::CreateBuffer(size_t size, GLbitfield flags) noxnd {
	std::shared_ptr<RawBuffer> buffer = std::shared_ptr<RawBuffer>(new RawBuffer());
	buffer->Storage(size, flags);
	return buffer;
}

RawBuffer::RawBuffer() {
	glCreateBuffers(1, &m_buffer);//如果使用glNamedBufferStorage，需要使用glCreateBuffers而不是glGenBuffers生成的buffer，不然会报找不到buffer对象的错误
}

RawBuffer::~RawBuffer() {
	glDeleteBuffers(1, &m_buffer);
}

void RawBuffer::Bind(GLenum target) noxnd {
	glBindBuffer(target, m_buffer);
}

void RawBuffer::Storage(size_t size, GLbitfield flags) noxnd {
	glNamedBufferStorage(m_buffer, size, NULL, flags);
}

void RawBuffer::Update(size_t size, size_t offset, const void* data) noxnd {
	glNamedBufferSubData(m_buffer, offset, size, data);
}