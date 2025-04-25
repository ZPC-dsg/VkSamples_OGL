#include <Bindables/imagetexture2D.h>
#include <stb_image.h>

namespace Bind {
	ImageTexture2D::ImageTexture2D(const std::string& tag, const std::string& path, const OGL_TEXTURE_PARAMETER& param, GLuint unit, bool generate_mip)
		:AbstractTexture(param, unit) {
		int width, height, channels;
		unsigned char* data = gen_image_from_file(path, width, height, channels);

		OGL_TEXTURE2D_DESC desc;
		desc.target = GL_TEXTURE_2D;
		desc.width = width;
		desc.height = height;
		if (channels == 4) {
			desc.cpu_format = GL_RGBA;
			desc.internal_format = GL_RGBA8;
		}

		m_resource = std::dynamic_pointer_cast<RawTexture2D>(ResourceFactory::CreateTexture2D(tag, desc));

		m_resource->Update({ 0,0,(float)desc.width,(float)desc.height }, desc.cpu_format, desc.data_type, (void*)data, true);
		m_resource->SetParameters(param);

		stbi_image_free(data);

		m_path = path;
	}

	ImageTexture2D::ImageTexture2D(std::shared_ptr<RawTexture2D> texture2D, const OGL_TEXTURE_PARAMETER& param, GLuint unit, bool generate_mip)
		:AbstractTexture(texture2D, param, unit) {
		m_resource->SetParameters(param);
		if (generate_mip) {
			m_resource->GenerateMips();
		}
	}

	void ImageTexture2D::Bind() noxnd {
		m_resource->Bind(m_unit);
	}

	std::shared_ptr<ImageTexture2D> ImageTexture2D::Resolve(const std::string& tag, const std::string& path, const OGL_TEXTURE_PARAMETER& param, GLuint unit, bool generate_mip) {
		return BindableResolver::Resolve<ImageTexture2D>(tag, path, param, unit, generate_mip);
	}

    std::shared_ptr<ImageTexture2D> ImageTexture2D::Resolve(std::shared_ptr<RawTexture2D> texture2D, const OGL_TEXTURE_PARAMETER& param, GLuint unit, bool generate_mip ) {
		return BindableResolver::Resolve<ImageTexture2D>(texture2D, param, unit, generate_mip);
	}

	std::string ImageTexture2D::GenerateUID(const std::string& tag, const std::string& path, const OGL_TEXTURE_PARAMETER& param, GLuint unit, bool generate_mip) {
		using namespace std::string_literals;
		return typeid(ImageTexture2D).name() + "#"s + tag + path;
	}

	std::string ImageTexture2D::GenerateUID(std::shared_ptr<RawTexture2D> texture2D, const OGL_TEXTURE_PARAMETER& param, GLuint unit, bool generate_mip) {
		using namespace std::string_literals;

		return typeid(ImageTexture2D).name() + "#"s + texture2D->ResourceName() + "__"s + OGL_TEXTURE_PARAMETER::GlobalTag(param) + "__"s +
			std::to_string(unit);
	}

	std::string ImageTexture2D::GetUID() const noexcept {
		return m_path.length() ? GenerateUID(resource_name(), m_path, m_params, m_unit, false) :
			GenerateUID(m_resource, m_params, m_unit, false);//最后一个参数不影响名称
	}
}