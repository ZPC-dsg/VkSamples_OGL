#include <storageimage.h>

StorageImage::StorageImage(unsigned int width, unsigned int height) {
	glGenTextures(1, &ID);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, ID);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA32F, width, height, 0, GL_RGBA,
		GL_FLOAT, nullptr);
	glBindTexture(GL_TEXTURE_2D, 0);
}

void StorageImage::bind() {
	glBindImageTexture(0, ID, 0, GL_FALSE, 0, GL_READ_WRITE, GL_RGBA32F);
}

void StorageImage::bind(unsigned int index) {
	binding_point = index;
	glBindImageTexture(index, ID, 0, GL_FALSE, 0, GL_READ_WRITE, GL_RGBA32F);
}

void StorageImage::unbind() {
	glBindImageTexture(0, 0, 0, GL_FALSE, 0, GL_READ_WRITE, GL_RGBA32F);
}

void StorageImage::unbind(unsigned int index) {
	binding_point = 0;
	glBindImageTexture(index, 0, 0, GL_FALSE, 0, GL_READ_WRITE, GL_RGBA32F);
}

StorageImage::~StorageImage() {
}