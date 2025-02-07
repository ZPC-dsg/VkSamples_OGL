#include <buffer.h>
#include <iostream>
#include <init.h>

Buffer::Buffer(GLenum target, GLenum usage, size_t size, const void* data) : target(target), usage(usage), data_size(size) {
	glGenBuffers(1, &ID);
	glBindBuffer(target, ID);
	glBufferData(target, size, data, usage);
	glBindBuffer(target, 0);
}

void Buffer::bind(GLuint index) {
	glBindBufferBase(target, index, ID);
}

void Buffer::bind() {
	glBindBuffer(target, ID);
}

void Buffer::unbind(GLuint index) {
	glBindBufferBase(target, index, 0);
}

void Buffer::unbind() {
	glBindBuffer(target, 0);
}

void Buffer::rebind(GLenum new_target) {
	target = new_target;
	glBindBuffer(new_target, ID);
}

void Buffer::update(size_t offset, size_t size, const void* data) {
	bind();
	glBufferSubData(target, offset, size, data);
	unbind();
}

void Buffer::update(size_t size, const void* data) {
	bind();
	glBufferData(target, size, data, usage);
	unbind();
}

void Buffer::copy(const Buffer& source, size_t read_offsets, size_t write_offsets, size_t size)
{
	glBindBuffer(GL_COPY_READ_BUFFER, source.ID);
	glBindBuffer(GL_COPY_WRITE_BUFFER, ID);
	glCopyBufferSubData(GL_COPY_READ_BUFFER, GL_COPY_WRITE_BUFFER, read_offsets, write_offsets, size);
	glBindBuffer(GL_COPY_READ_BUFFER, 0); 
	glBindBuffer(GL_COPY_WRITE_BUFFER, 0);
}

Buffer::~Buffer() {
	glDeleteBuffers(1, &ID);
}