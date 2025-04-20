#include <resourcefactory.h>
#include <init.h>

ResourceFactory& MainFactory = ResourceFactory::GetInstance();

std::shared_ptr<RawBuffer> ResourceFactory::CreateBuffer(size_t size, GLbitfield flags) noxnd {
	std::shared_ptr<RawBuffer> buffer = std::shared_ptr<RawBuffer>(new RawBuffer());
	buffer->Storage(size, flags);
	return buffer;
}

RawBuffer::RawBuffer() {
	glCreateBuffers(1, &m_buffer);//���ʹ��glNamedBufferStorage����Ҫʹ��glCreateBuffers������glGenBuffers���ɵ�buffer����Ȼ�ᱨ�Ҳ���buffer����Ĵ���
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