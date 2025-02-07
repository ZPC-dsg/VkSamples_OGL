#include <texturebuilder.h>
#include <storageimage.h>
#include <textureimage.h>

#include <iostream>

std::unique_ptr<TextureBase> TextureFactory::build(TextureType type, unsigned int width, unsigned int height, const char* path, GLint wrap_mode) {
	switch (type) {
	case STORAGE_IMAGE:
		return std::unique_ptr<StorageImage>(new StorageImage(width, height));
	case TEXTURE_IMAGE:
		return std::unique_ptr<TextureImage>(new TextureImage(path, wrap_mode));
	case TEXTURE_ATTACHMENT:
		return std::unique_ptr<TextureImage>(new TextureImage(width, height));
	default:
		throw std::runtime_error("Unsupported type!");
	}
}

