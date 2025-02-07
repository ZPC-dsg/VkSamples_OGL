#include <texturebase.h>

TextureBase::~TextureBase() {
	glDeleteTextures(1, &ID);
}