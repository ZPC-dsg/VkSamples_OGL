#pragma once

#define RENDERTARGET_FILE

#include <Bindables/cubemap.h>
#include <Bindables/imagetexture2D.h>
#include <Bindables/imagetexture2Darray.h>

namespace Bind {
#ifndef RENDERTARGET_FILE
#undef TEXTURE_HELPER
#else
#define TEXTURE_HELPER \
	X(GL_TEXTURE_2D) \
	X(GL_TEXTURE_2D_ARRAY) \
	X(GL_TEXTURE_CUBE_MAP)
#endif

	template <typename T>
	concept texture_type = std::is_base_of_v<AbstractTexture, T> && !std::is_same_v<AbstractTexture, T>;

	class RenderTarget :public Bindable {
	public:
		RenderTarget(const std::string& tag, std::vector<std::shared_ptr<AbstractTexture>> rendertargets, std::shared_ptr<AbstractTexture> depthstencil);
		RenderTarget(const std::string& tag, std::vector<std::shared_ptr<AbstractTexture>> rendertargets, std::shared_ptr<AbstractTexture> depthstencil,
			unsigned int* mips, unsigned int* slices);
		RenderTarget(const std::string& tag, std::vector<std::shared_ptr<AbstractTexture>> rendertargets, const std::string& rb_tag, bool depth_only = true);
		RenderTarget(const std::string& tag, std::vector<std::shared_ptr<AbstractTexture>> rendertargets, const std::string& rb_tag,
			unsigned int* mips, unsigned int* slices, bool depth_only = true);
		RenderTarget(const std::string& tag, unsigned int width, unsigned int height, unsigned int sample_count = 1, GLenum format = GL_RGB8);
		~RenderTarget();

		template <GLenum Target>
		RenderTarget& AppendTexture(const std::string& tag, unsigned int slices = 1) noxnd;
#define X(Target) \
	template <> \
	RenderTarget& AppendTexture<Target>(const std::string& name, unsigned int slices) noxnd; 

		TEXTURE_HELPER

#undef X


		template <GLenum Target>
		RenderTarget& AppendDepthComponent(const std::string& tag, unsigned int slices = 1) noxnd;
#define X(Target) \
	template <> \
	RenderTarget& AppendDepthComponent<Target>(const std::string& tag, unsigned int slices) noxnd;

		TEXTURE_HELPER

#undef X
		template <>
		RenderTarget& AppendDepthComponent<GL_RENDERBUFFER>(const std::string& tag, unsigned int slices) noxnd;


		template <GLenum Target>
		RenderTarget& AppendDepthStencil(const std::string& tag, unsigned int slices = 1) noxnd;
#define X(Target) \
	template <> \
	RenderTarget& AppendDepthStencil<Target>(const std::string& tag, unsigned int slices) noxnd;

		TEXTURE_HELPER

#undef X
		template <>
		RenderTarget& AppendDepthStencil<GL_RENDERBUFFER>(const std::string& tag, unsigned int slices) noxnd;

		void CheckCompleteness() noxnd;

		void Bind() noxnd override;
		static std::shared_ptr<RenderTarget> Resolve(const std::string& tag, std::vector<std::shared_ptr<AbstractTexture>> rendertargets, std::shared_ptr<AbstractTexture> depthstencil);
		static std::shared_ptr<RenderTarget> Resolve(const std::string& tag, std::vector<std::shared_ptr<AbstractTexture>> rendertargets, std::shared_ptr<AbstractTexture> depthstencil,
			unsigned int* mips, unsigned int* slices);
		static std::shared_ptr<RenderTarget> Resolve(const std::string& tag, std::vector<std::shared_ptr<AbstractTexture>> rendertargets, const std::string& rb_tag, bool depth_only = true);
		static std::shared_ptr<RenderTarget> Resolve(const std::string& tag, std::vector<std::shared_ptr<AbstractTexture>> rendertargets, const std::string& rb_tag,
			unsigned int* mips, unsigned int* slices, bool depth_only = true);
		static std::shared_ptr<RenderTarget> Resolve(const std::string& tag, unsigned int width, unsigned int height, unsigned int sample_count = 1, GLenum format = GL_RGB8);
		template <typename ...Ignore>
		static std::string GenerateUID(const std::string& tag, Ignore... ignore) {
			using namespace std::string_literals;
			return typeid(RenderTarget).name() + "#"s + tag;
		}
		std::string GetUID() const noexcept override;

		void change_texture_slice(unsigned int index, unsigned int slice, unsigned int mip = 0) noxnd;
		void change_texture_slice(const std::string& name, unsigned int slice, unsigned int mip = 0) noxnd;
		void change_depthstencil_slice(unsigned int slice, unsigned int mip = 0) noxnd;

		std::shared_ptr<AbstractResource> get_render_target(const std::string& name, int& index) const noexcept;
		std::shared_ptr<AbstractResource> get_render_target(unsigned int index) const noexcept;
		std::shared_ptr<AbstractResource> get_depth_stencil() const noexcept;

		template <texture_type T>
		std::shared_ptr<T> get_texture_image(const std::string& name, OGL_TEXTURE_PARAMETER param, GLuint unit, bool generate_mip = false) const noxnd;

		template <texture_type T>
		std::shared_ptr<T> get_texture_depthstencil(OGL_TEXTURE_PARAMETER param, GLuint unit, bool generate_mip = false) const noxnd;

		inline unsigned int get_width() const noexcept { return m_width; }
		inline unsigned int get_height() const noexcept { return m_height; }

		std::type_index GetTypeInfo() const noexcept override;

	private:
		void gen_framebuffer(unsigned int* mips, unsigned int* slices, bool is_renderbuffer, bool is_depthonly) noxnd;

	private:
		std::string m_tag;
		GLuint m_framebuffer;
		std::vector<std::shared_ptr<AbstractResource>> m_rendertargets;//按照着色器中location顺序的渲染目标
		std::shared_ptr<AbstractResource> m_depthstencil;

		unsigned int m_width, m_height, m_samples = 1;
		GLenum m_internal_format = GL_RGB8;
	};

	template <texture_type T>
	std::shared_ptr<T> RenderTarget::get_texture_image(const std::string& name, OGL_TEXTURE_PARAMETER param, GLuint unit, bool generate_mip) const noxnd {
		int index;
		auto p = get_render_target(name, index);
		if (!p)
			return nullptr;

		return T::Resolve(std::dynamic_pointer_cast<RawTexture2D>(p), param, unit, generate_mip);
	}

	template <texture_type T>
	std::shared_ptr<T> RenderTarget::get_texture_depthstencil(OGL_TEXTURE_PARAMETER param, GLuint unit, bool generate_mip) const noxnd {
		auto d = std::dynamic_pointer_cast<RawTexture2D>(m_depthstencil);
		if (!d)
			return nullptr;

		return T::Resolve(d, param, unit, generate_mip);
	}

#undef RENDERTARGET_FILE
}