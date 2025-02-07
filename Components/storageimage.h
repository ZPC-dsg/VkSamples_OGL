#pragma once

#include <texturebase.h>

class TextureFactory;

class StorageImage :public TextureBase {
	friend TextureFactory;

	StorageImage(unsigned int width, unsigned int height);

public:
	virtual void bind() override;
	virtual void bind(unsigned int index) override;
	virtual void unbind() override;
	virtual void unbind(unsigned int index) override;

	virtual ~StorageImage() override;

private:
	unsigned int binding_point = 0;//Bind to binding point 0 by default
};