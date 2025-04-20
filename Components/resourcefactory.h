#pragma once

#include <nocopyable.h>
#include <Macros/conditional_noexcept.h>

#include <glad/glad.h>
#include <memory>

class RawBuffer;

class ResourceFactory :private NoCopyable {
public:
	static ResourceFactory& GetInstance() {
		static ResourceFactory factory;
		return factory;
	}

	static std::shared_ptr<RawBuffer> CreateBuffer(size_t size, GLbitfield flags = 0) noxnd;

private:
	ResourceFactory() = default;
};

class RawBuffer {
public:
	friend class ResourceFactory;

	RawBuffer();
	~RawBuffer();

	void Bind(GLenum target) noxnd;
	void Storage(size_t size, GLbitfield flags) noxnd;
	void Update(size_t size, size_t offset, const void* data) noxnd;

private:
	GLuint m_buffer;
};


extern ResourceFactory& MainFactory;