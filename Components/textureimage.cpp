#include <textureimage.h>
#include <stb_image.h>
#include <stdexcept>
#include <init.h>

TextureImage::TextureImage(const char* path, GLint wrap_mode) {
    glGenTextures(1, &ID);
    glBindTexture(GL_TEXTURE_2D, ID);
    // set the texture wrapping/filtering options (on the currently bound texture object)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wrap_mode);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wrap_mode);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAX_ANISOTROPY, globalSettings::max_anisotropy);
    // load and generate the texture
    int width, height, nrChannels;
    std::string whole_path(path);
    whole_path = "../assets/textures/" + whole_path;
    stbi_set_flip_vertically_on_load(true);
    unsigned char* data = stbi_load(whole_path.c_str(), &width, &height, &nrChannels, 0);
    if (data)
    {
        if (nrChannels == 3) {
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        }
        else {
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
        }
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        throw std::runtime_error("Failed to load texture");
    }
    stbi_image_free(data);
    glBindTexture(GL_TEXTURE_2D, 0);
}

TextureImage::TextureImage(unsigned int width, unsigned int height) {
    glGenTextures(1, &ID);
    glBindTexture(GL_TEXTURE_2D, ID);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glBindTexture(GL_TEXTURE_2D, 0);
}

void TextureImage::bind() {
    glBindTexture(GL_TEXTURE_2D, ID);
}

void TextureImage::bind(unsigned int index) {
    binding_point = index;
    glActiveTexture(GL_TEXTURE0 + index);
    glBindTexture(GL_TEXTURE_2D, ID);
}

void TextureImage::unbind() {
    glBindTexture(GL_TEXTURE_2D, 0);
}

void TextureImage::unbind(unsigned int index) {
    binding_point = -1;
    glBindTexture(GL_TEXTURE_2D, 0);
}

TextureImage::~TextureImage() {
}