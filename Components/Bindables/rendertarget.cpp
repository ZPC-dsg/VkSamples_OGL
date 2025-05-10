#include <Bindables/rendertarget.h>

#include <numeric>

#define RENDERTARGET_FILE

namespace Bind {
	RenderTarget::RenderTarget(const std::string& tag, std::vector<std::shared_ptr<AbstractTexture>> rendertargets, std::shared_ptr<AbstractTexture> depthstencil)
		:m_tag(tag), m_width(rendertargets[0]->get_description().width), m_height(rendertargets[0]->get_description().height), 
		m_samples(rendertargets[0]->get_description().samplecount), m_internal_format(rendertargets[0]->get_description().internal_format)
	{
		m_rendertargets.reserve(rendertargets.size());
		for (auto r : rendertargets) {
			m_rendertargets.push_back(r->m_resource);
		}

	    m_depthstencil = depthstencil->m_resource;
		
		std::vector<unsigned int> slices(m_rendertargets.size() + 1, 0);
		std::vector<unsigned int> mips(m_rendertargets.size() + 1, 0);
		gen_framebuffer(mips.data(), slices.data(), false, depthstencil->is_depth_only());
	}

	RenderTarget::RenderTarget(const std::string& tag, std::vector<std::shared_ptr<AbstractTexture>> rendertargets, std::shared_ptr<AbstractTexture> depthstencil,
		unsigned int* mips, unsigned int* slices)
		:m_tag(tag), m_width(rendertargets[0]->get_description().width), m_height(rendertargets[0]->get_description().height),
		m_samples(rendertargets[0]->get_description().samplecount), m_internal_format(rendertargets[0]->get_description().internal_format)
	{
		m_rendertargets.reserve(rendertargets.size());
		for (auto r : rendertargets) {
			m_rendertargets.push_back(r->m_resource);
		}

		m_depthstencil = depthstencil->m_resource;

		gen_framebuffer(mips, slices, false, depthstencil->is_depth_only());
	}

	RenderTarget::RenderTarget(const std::string& tag, std::vector<std::shared_ptr<AbstractTexture>> rendertargets, const std::string& rb_tag, bool depth_only)
		:m_tag(tag), m_width(rendertargets[0]->get_description().width), m_height(rendertargets[0]->get_description().height),
		m_samples(rendertargets[0]->get_description().samplecount), m_internal_format(rendertargets[0]->get_description().internal_format)
	{
		m_rendertargets.reserve(rendertargets.size());
		for (auto r : rendertargets) {
			m_rendertargets.push_back(r->m_resource);
		}

		auto desc = rendertargets[0]->get_description();
		m_depthstencil = ResourceFactory::CreateRenderBuffer(rb_tag, depth_only ? GL_DEPTH_COMPONENT24 : GL_DEPTH24_STENCIL8, 
			desc.width, desc.height, desc.samplecount);

		std::vector<unsigned int> slices(m_rendertargets.size(), 0);
		std::vector<unsigned int> mips(m_rendertargets.size(), 0);
		gen_framebuffer(mips.data(), slices.data(), true, depth_only);
	}

	RenderTarget::RenderTarget(const std::string& tag, std::vector<std::shared_ptr<AbstractTexture>> rendertargets, const std::string& rb_tag,
		unsigned int* mips, unsigned int* slices, bool depth_only)
		:m_tag(tag), m_width(rendertargets[0]->get_description().width), m_height(rendertargets[0]->get_description().height),
		m_samples(rendertargets[0]->get_description().samplecount), m_internal_format(rendertargets[0]->get_description().internal_format)
	{
		m_rendertargets.reserve(rendertargets.size());
		for (auto r : rendertargets) {
			m_rendertargets.push_back(r->m_resource);
		}

		auto desc = rendertargets[0]->get_description();
		m_depthstencil = ResourceFactory::CreateRenderBuffer(rb_tag, depth_only ? GL_DEPTH_COMPONENT24 : GL_DEPTH24_STENCIL8,
			desc.width, desc.height, desc.samplecount);

		gen_framebuffer(mips, slices, true, depth_only);
	}

	RenderTarget::RenderTarget(const std::string& tag, unsigned int width, unsigned int height, unsigned int sample_count, GLenum format)
		:m_tag(tag), m_width(width), m_height(height), m_samples(sample_count), m_internal_format(format)
	{
		glCreateFramebuffers(1, &m_framebuffer);
	}

	RenderTarget::~RenderTarget() {
		glDeleteFramebuffers(1, &m_framebuffer);
	}

	void RenderTarget::gen_framebuffer(unsigned int* mips, unsigned int* slices, bool is_renderbuffer, bool is_depthonly) noxnd {
		glCreateFramebuffers(1, &m_framebuffer);
		glBindFramebuffer(GL_FRAMEBUFFER, m_framebuffer);

		for (int i = 0; i < m_rendertargets.size(); i++) {
			std::dynamic_pointer_cast<RawTexture2D>(m_rendertargets[i])->BindSliceAsRenderTarget(m_framebuffer, i, slices[i], mips[i]);
		}
		if (is_renderbuffer) {
			auto d = std::dynamic_pointer_cast<RawRenderBuffer>(m_depthstencil);
			is_depthonly ? d->BindAsDepthComponent(m_framebuffer) : d->BindAsDepthStencil(m_framebuffer);
		}
		else {
			auto d = std::dynamic_pointer_cast<RawTexture2D>(m_depthstencil);
			is_depthonly ? d->BindSliceAsDepthComponent(m_framebuffer, slices[m_rendertargets.size()], mips[m_rendertargets.size()]) :
				d->BindSliceAsDepthStencil(m_framebuffer, slices[m_rendertargets.size()], mips[m_rendertargets.size()]);
		}

		CheckCompleteness();

		glObjectLabel(GL_FRAMEBUFFER, m_framebuffer, -1, m_tag.c_str());
	}

	void RenderTarget::CheckCompleteness() noxnd {
		GLenum res = glCheckNamedFramebufferStatus(m_framebuffer, GL_FRAMEBUFFER);
		if (res != GL_FRAMEBUFFER_COMPLETE) {
			switch (res) {
			case GL_FRAMEBUFFER_UNDEFINED:
				assert("Frame buffer does not exist!" && false);
				break;
			case GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT:
				assert("One or more attachments are not complete!" && false);
				break;
			case GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT:
				assert("Without image attachments!" && false);
				break;
			case GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER:
				assert("Draw buffers incomplete!" && false);
				break;
			case GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER:
				assert("Read buffers incomplete!" && false);
				break;
			case GL_FRAMEBUFFER_UNSUPPORTED:
				assert("Internal format of attached images are not supported!" && false);
				break;
			case GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE:
				assert("Sample count differs between attachments!" && false);
				break;
			case GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS:
				assert("Targets of attachments aren't the same!" && false);
				break;
			}
		}
		glBindFramebuffer(GL_FRAMEBUFFER, 0);
	}

	void RenderTarget::Bind() noxnd {
		glBindFramebuffer(GL_FRAMEBUFFER, m_framebuffer);
		std::vector<unsigned int> attachments(m_rendertargets.size());
		std::iota(attachments.begin(), attachments.end(), GL_COLOR_ATTACHMENT0);
		glDrawBuffers(m_rendertargets.size(), attachments.data());
	}

	std::shared_ptr<RenderTarget> RenderTarget::Resolve(const std::string& tag, std::vector<std::shared_ptr<AbstractTexture>> rendertargets, std::shared_ptr<AbstractTexture> depthstencil) {
		return BindableResolver::Resolve<RenderTarget>(tag, rendertargets, depthstencil);
	}

	std::shared_ptr<RenderTarget> RenderTarget::Resolve(const std::string& tag, std::vector<std::shared_ptr<AbstractTexture>> rendertargets, std::shared_ptr<AbstractTexture> depthstencil,
		unsigned int* mips, unsigned int* slices) {
		return BindableResolver::Resolve<RenderTarget>(tag, rendertargets, depthstencil, mips, slices);
	}

	std::shared_ptr<RenderTarget> RenderTarget::Resolve(const std::string& tag, std::vector<std::shared_ptr<AbstractTexture>> rendertargets, const std::string& rb_tag, bool depth_only) {
		return BindableResolver::Resolve<RenderTarget>(tag, rendertargets, rb_tag, depth_only);
	}

	std::shared_ptr<RenderTarget> RenderTarget::Resolve(const std::string& tag, std::vector<std::shared_ptr<AbstractTexture>> rendertargets, const std::string& rb_tag,
		unsigned int* mips, unsigned int* slices, bool depth_only) {
		return BindableResolver::Resolve<RenderTarget>(tag, rendertargets, rb_tag, mips, slices, depth_only);
	}

	std::shared_ptr<RenderTarget> RenderTarget::Resolve(const std::string& tag, unsigned int width, unsigned int height, unsigned int sample_count, GLenum format) {
		return BindableResolver::Resolve<RenderTarget>(tag, width, height, sample_count, format);
	}

	std::string RenderTarget::GetUID() const noexcept {
		return GenerateUID(m_tag);
	}

	void RenderTarget::change_texture_slice(unsigned int index, unsigned int slice, unsigned int mip) noxnd {
		assert(index < m_rendertargets.size());

		std::dynamic_pointer_cast<RawTexture2D>(m_rendertargets[index])->BindSliceAsRenderTarget(m_framebuffer, index, slice, mip);
	}

	void RenderTarget::change_texture_slice(const std::string& name, unsigned int slice, unsigned int mip) noxnd {
		int index;
		auto tar = get_render_target(name, index);
		assert(tar != nullptr);

		std::dynamic_pointer_cast<RawTexture2D>(tar)->BindSliceAsRenderTarget(m_framebuffer, index, slice, mip);
	}

	void RenderTarget::change_depthstencil_slice(unsigned int slice, unsigned int mip) noxnd {
		auto t = std::dynamic_pointer_cast<RawTexture2D>(m_depthstencil);
		assert(t != nullptr);

		if (t->DepthOnly()) {
			t->BindSliceAsDepthComponent(m_framebuffer, slice, mip);
		}
		else {
			t->BindSliceAsDepthStencil(m_framebuffer, slice, mip);
		}
	}

	std::shared_ptr<AbstractResource> RenderTarget::get_render_target(const std::string& name, int& index) const noexcept {
		for (int i = 0; i < m_rendertargets.size(); i++) {
			if (m_rendertargets[i]->ResourceName() == name) {
				index = i;
				return m_rendertargets[i];
			}
		}

		index = -1;
		return nullptr;
	}

	std::shared_ptr<AbstractResource> RenderTarget::get_render_target(unsigned int index) const noexcept {
		return index < m_rendertargets.size() ? m_rendertargets[index] : nullptr;
	}

	std::shared_ptr<AbstractResource> RenderTarget::get_depth_stencil() const noexcept {
		return m_depthstencil;
	}

	std::type_index RenderTarget::GetTypeInfo() const noexcept {
		return typeid(RenderTarget);
	}

#define X(Target) \
	template <> \
	RenderTarget& RenderTarget::AppendTexture<Target>(const std::string& tag, unsigned int slices) noxnd { \
		OGL_TEXTURE2D_DESC desc; \
		desc.width = m_width; \
		desc.height = m_height; \
		desc.samplecount = m_samples; \
		desc.internal_format = m_internal_format; \
		desc.arrayslices = slices; \
		desc.target = Target; \
		\
		auto resource = ResourceFactory::CreateTexture2D(tag, desc); \
		glBindFramebuffer(GL_FRAMEBUFFER, m_framebuffer); \
		std::dynamic_pointer_cast<RawTexture2D>(resource)->BindSliceAsRenderTarget(m_framebuffer, m_rendertargets.size(), 0, 0);\
		m_rendertargets.push_back(resource);\
		\
		return *this;\
	}

	TEXTURE_HELPER

#undef X

#define X(Target) \
	template <> \
	RenderTarget& RenderTarget::AppendDepthComponent<Target>(const std::string& tag, unsigned int slices) noxnd { \
		OGL_TEXTURE2D_DESC desc; \
		desc.width = m_width; \
		desc.height = m_height; \
		desc.samplecount = m_samples; \
		desc.internal_format = GL_DEPTH_COMPONENT24; \
		desc.arrayslices = slices; \
		desc.target = Target; \
		\
		m_depthstencil = ResourceFactory::CreateTexture2D(tag, desc); \
		auto d = std::dynamic_pointer_cast<RawTexture2D>(m_depthstencil); \
		glBindFramebuffer(GL_FRAMEBUFFER, m_framebuffer); \
		d->BindSliceAsDepthComponent(m_framebuffer, 0, 0); \
		\
		return *this; \
	}

		TEXTURE_HELPER

#undef X
	template <>
	RenderTarget& RenderTarget::AppendDepthComponent<GL_RENDERBUFFER>(const std::string& tag, unsigned int slices) noxnd {
		m_depthstencil = ResourceFactory::CreateRenderBuffer(tag, GL_DEPTH_COMPONENT24, m_width, m_height, m_samples);
		auto d = std::dynamic_pointer_cast<RawRenderBuffer>(m_depthstencil);
		d->BindAsDepthComponent(m_framebuffer);

		return *this;
	}

#define X(Target) \
	template <> \
	RenderTarget& RenderTarget::AppendDepthStencil<Target>(const std::string& tag, unsigned int slices) noxnd { \
		OGL_TEXTURE2D_DESC desc; \
		desc.width = m_width; \
		desc.height = m_height; \
		desc.samplecount = m_samples; \
		desc.internal_format = GL_DEPTH24_STENCIL8; \
		desc.arrayslices = slices; \
		desc.target = Target; \
        \
		m_depthstencil = ResourceFactory::CreateTexture2D(tag, desc); \
		auto d = std::dynamic_pointer_cast<RawTexture2D>(m_depthstencil); \
		glBindFramebuffer(GL_FRAMEBUFFER, m_framebuffer); \
		d->BindSliceAsDepthStencil(m_framebuffer, 0, 0); \
		\
		return *this; \
    }

	TEXTURE_HELPER

#undef X
	template <>
	RenderTarget& RenderTarget::AppendDepthStencil<GL_RENDERBUFFER>(const std::string& tag, unsigned int slices) noxnd {
		m_depthstencil = ResourceFactory::CreateRenderBuffer(tag, GL_DEPTH24_STENCIL8, m_width, m_height, m_samples);
		auto d = std::dynamic_pointer_cast<RawRenderBuffer>(m_depthstencil);
		d->BindAsDepthStencil(m_framebuffer);

		return *this;
	}

#undef RENDERTARGET_FILE
}