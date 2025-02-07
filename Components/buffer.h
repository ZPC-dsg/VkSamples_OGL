#pragma once

#include <glad/glad.h>

#include <nocopyable.h>

class Buffer : private NoCopyable {
public:
	Buffer(GLenum target, GLenum usage, size_t size, const void* data);
	~Buffer();

	void bind(GLuint index);
	void bind();
	void unbind(GLuint index);
	void unbind();
	void rebind(GLenum new_target);

	void update(size_t offset, size_t size, const void* data);
	void update(size_t size, const void* data);

	void copy(const Buffer& source, size_t read_offsets, size_t write_offsets, size_t size);

	inline size_t size() {
		return data_size;
	}

	GLuint ID;

private:
	GLenum target;
	GLenum usage;
	size_t data_size;
};