#pragma once 

#include <memory>
#include <glad/glad.h>

class TextureBase;

enum TextureType {
	STORAGE_IMAGE,
	TEXTURE_IMAGE,
	TEXTURE_ATTACHMENT
};

class TextureFactory {
public:
	static std::unique_ptr<TextureBase> build(TextureType type, unsigned int width, unsigned int height, const char* path = nullptr, GLint wrap_mode = GL_REPEAT);
};