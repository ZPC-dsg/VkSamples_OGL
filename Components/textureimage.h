#pragma once

#include <texturebase.h>

class TextureFactory;

class TextureImage :public TextureBase {
	friend TextureFactory;

	TextureImage(const char* path, GLint wrap_mode = GL_REPEAT);
	TextureImage(unsigned int width, unsigned int height); //used for framebuffer color attachments

public:
	virtual void bind() override;
	virtual void bind(unsigned int index) override;
	virtual void unbind() override;
	virtual void unbind(unsigned int inidex) override;

	virtual ~TextureImage() override;

private:
	int binding_point = -1;//-1代表未用作纹理，大于等于0代表纹理绑定点
};