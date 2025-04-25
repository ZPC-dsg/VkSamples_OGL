#include <Bindables/abstracttexture.h>
#include <tools.h>

#include <stb_image.h>

namespace Bind {
	AbstractTexture::AbstractTexture(const OGL_TEXTURE_PARAMETER& param, GLuint unit)
		:m_params(param), m_unit(unit)
	{
	}

	AbstractTexture::AbstractTexture(std::shared_ptr<RawTexture2D> resource, const OGL_TEXTURE_PARAMETER& param, GLuint unit)
		:m_params(param), m_unit(unit), m_resource(resource)
	{
	}

	void AbstractTexture::set_params(const OGL_TEXTURE_PARAMETER& param) noxnd {
		m_params = param;
		m_resource->SetParameters(param);
	}

	unsigned char* AbstractTexture::gen_image_from_file(const std::string& path, int& width, int& height, int& channels) {
		std::string whole_path = Tools::get_solution_dir() + "assets/textures/" + path;

		stbi_set_flip_vertically_on_load(true);
		unsigned char* data = stbi_load(whole_path.c_str(), &width, &height, &channels, 0);

		return data;
	}

	bool AbstractTexture::is_depth_only() const noexcept {
		return m_resource->DepthOnly();
	}

	std::string AbstractTexture::resource_name() const noexcept {
		return m_resource->ResourceName();
	}
}