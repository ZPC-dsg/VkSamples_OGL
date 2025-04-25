#pragma once

#include <Bindables/abstracttexture.h>

#include <array>

namespace Bind {
	class CubeMap :public AbstractTexture {
	public:
		CubeMap(const std::string& tag, std::array<std::string, 6> path, const OGL_TEXTURE_PARAMETER& param, GLuint unit, bool generate_mip = false);
		CubeMap(std::shared_ptr<RawTexture2D> cubemap, const OGL_TEXTURE_PARAMETER& param, GLuint unit, bool generate_mip = false);
		~CubeMap() = default;

		void Bind() noxnd override;
		static std::shared_ptr<CubeMap> Resolve(const std::string& tag, std::array<std::string, 6> path, const OGL_TEXTURE_PARAMETER& param, GLuint unit, bool generate_mip = false);
		static std::shared_ptr<CubeMap> Resolve(std::shared_ptr<RawTexture2D> cubemap, const OGL_TEXTURE_PARAMETER& param, GLuint unit, bool generate_mip = false);
		static std::string GenerateUID(const std::string& tag, std::array<std::string, 6> path, const OGL_TEXTURE_PARAMETER& param, GLuint unit, bool generate_mip = false);
		static std::string GenerateUID(std::shared_ptr<RawTexture2D> cubemap, const OGL_TEXTURE_PARAMETER& param, GLuint unit, bool generate_mip = false);
		std::string GetUID() const noexcept override;

	private:
		std::array<std::string, 6> m_path{};
	};
}