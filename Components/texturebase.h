#pragma once
#include <glad/glad.h>

#include <nocopyable.h>

class TextureBase : private NoCopyable {
public:
	TextureBase() = default;

	virtual ~TextureBase();

	inline virtual void bind() {};
	inline virtual void bind(unsigned int index) {};
	inline virtual void unbind() {};
	inline virtual void unbind(unsigned int index) {};

protected:
	unsigned int ID = 0;
};
