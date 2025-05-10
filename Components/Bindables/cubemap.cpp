#include <Bindables/cubemap.h>

#include <stb_image.h>

namespace Bind {
	CubeMap::CubeMap(const std::string& tag, std::array<std::string, 6> path, const OGL_TEXTURE_PARAMETER& param, GLuint unit, bool generate_mip)
		:AbstractTexture(param, unit) {
		int width, height, channels;

		OGL_TEXTURE2D_DESC desc;
		desc.target = GL_TEXTURE_CUBE_MAP;
		
		for (int i = 0; i < 6; i++) {
			int l_width, l_height, l_channels;
			if (i == 0) {
				unsigned char* data = gen_image_from_file(path[0], width, height, channels);
				desc.width = width;
				desc.height = height;
				if (channels == 4) {
					desc.cpu_format = GL_RGBA;
					desc.internal_format = GL_RGBA;
				}

				m_resource = std::dynamic_pointer_cast<RawTexture2D>(ResourceFactory::CreateTexture2D(tag, desc));
				m_resource->UpdateSlice({ 0,0,(float)desc.width,(float)desc.height }, desc.cpu_format, desc.data_type, (void*)data, 0, generate_mip);

				stbi_image_free(data);
			}
			else {
				unsigned char* data = gen_image_from_file(path[i], l_width, l_height, l_channels);
				m_resource->UpdateSlice({ 0,0,(float)desc.width,(float)desc.height }, desc.cpu_format, desc.data_type, (void*)data, i, generate_mip);

				stbi_image_free(data);
			}
		}

		m_path = path;

		m_resource->SetParameters(param);
	}

	CubeMap::CubeMap(std::shared_ptr<RawTexture2D> cubemap, const OGL_TEXTURE_PARAMETER& param, GLuint unit, bool generate_mip)
		:AbstractTexture(cubemap, param, unit)
	{
		m_resource->SetParameters(param);
		if (generate_mip) {
			m_resource->GenerateMips();
		}
	}

	void CubeMap::Bind() noxnd {
		m_resource->Bind(m_unit);
	}

	std::shared_ptr<CubeMap> CubeMap::Resolve(const std::string& tag, std::array<std::string, 6> path, const OGL_TEXTURE_PARAMETER& param, GLuint unit, bool generate_mip) {
		return BindableResolver::Resolve<CubeMap>(tag, path, param, unit, generate_mip);
	}

	std::shared_ptr<CubeMap> CubeMap::Resolve(std::shared_ptr<RawTexture2D> cubemap, const OGL_TEXTURE_PARAMETER& param, GLuint unit, bool generate_mip) {
		return BindableResolver::Resolve<CubeMap>(cubemap, param, unit, generate_mip);
	}

	std::string CubeMap::GenerateUID(const std::string& tag, std::array<std::string, 6> path, const OGL_TEXTURE_PARAMETER& param, GLuint unit, bool generate_mip) {
		using namespace std::string_literals;
		
		std::string gID = typeid(CubeMap).name() + "#"s + tag + "__"s;
		for (auto p : path) {
			gID += p + "__"s;
		}

		return gID;
	}

	std::string CubeMap::GenerateUID(std::shared_ptr<RawTexture2D> cubemap, const OGL_TEXTURE_PARAMETER& param, GLuint unit, bool generate_mip) {
		using namespace std::string_literals;

		return typeid(CubeMap).name() + "#"s + cubemap->ResourceName() + "__"s + OGL_TEXTURE_PARAMETER::GlobalTag(param) + "__"s + std::to_string(unit);
	}

	std::string CubeMap::GetUID() const noexcept {
		return m_path[0].length() ? GenerateUID(resource_name(), m_path, m_params, m_unit, false) :
			GenerateUID(m_resource, m_params, m_unit, false);
	}

	std::type_index CubeMap::GetTypeInfo() const noexcept {
		return typeid(CubeMap);
	}
}