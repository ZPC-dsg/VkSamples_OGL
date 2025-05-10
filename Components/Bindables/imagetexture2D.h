#pragma once

#include <Bindables/abstracttexture.h>

#include <array>

namespace Bind {
	class ImageTexture2D :public AbstractTexture {
	public:
		ImageTexture2D(const std::string& tag, const std::string& path, const OGL_TEXTURE_PARAMETER& param, GLuint unit, bool generate_mip = true);
		ImageTexture2D(std::shared_ptr<RawTexture2D> texture2D, const OGL_TEXTURE_PARAMETER& param, GLuint unit, bool generate_mip = false);
		~ImageTexture2D() = default;

		void Bind() noxnd override;
		static std::shared_ptr<ImageTexture2D> Resolve(const std::string& tag, const std::string& path, const OGL_TEXTURE_PARAMETER& param, GLuint unit, bool generate_mip = true);
		static std::shared_ptr<ImageTexture2D> Resolve(std::shared_ptr<RawTexture2D> texture2D, const OGL_TEXTURE_PARAMETER& param, GLuint unit, bool generate_mip = false);
		static std::string GenerateUID(const std::string& tag, const std::string& path, const OGL_TEXTURE_PARAMETER& param, GLuint unit, bool generate_mip = true);
		static std::string GenerateUID(std::shared_ptr<RawTexture2D> texture2D, const OGL_TEXTURE_PARAMETER& param, GLuint unit, bool generate_mip = false);
		std::string GetUID() const noexcept override;

		std::type_index GetTypeInfo() const noexcept override;

	private:
		std::string m_path = std::string("");
	};
}