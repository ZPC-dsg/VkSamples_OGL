#pragma once

#include <Bindables/includer.h>
#include <resourcefactory.h>

namespace Bind {
	class AbstractTexture :public Bindable {
		friend class RenderTarget;
	public:
		AbstractTexture(const OGL_TEXTURE_PARAMETER& param, GLuint unit);
		AbstractTexture(std::shared_ptr<RawTexture2D> resource, const OGL_TEXTURE_PARAMETER& param, GLuint unit);
		~AbstractTexture() = default;

		inline OGL_TEXTURE_PARAMETER get_parameter() const noexcept { return m_params; }
		inline OGL_TEXTURE2D_DESC get_description() const noexcept { return m_resource->GetDescription(); }
		void set_params(const OGL_TEXTURE_PARAMETER& param) noxnd;

		bool is_depth_only() const noexcept;

		std::string resource_name() const noexcept;

	protected:
		static unsigned char* gen_image_from_file(const std::string& path, int& width, int& height, int& channels);

	protected:
		OGL_TEXTURE_PARAMETER m_params;
		GLuint m_unit;

		std::shared_ptr<RawTexture2D> m_resource;
	};
}