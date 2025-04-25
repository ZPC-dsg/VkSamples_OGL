#include <resourcefactory.h>
#include <init.h>

ResourceFactory& MainFactory = ResourceFactory::GetInstance();

//ResourceFactory
std::shared_ptr<AbstractResource> ResourceFactory::CreateBuffer(const std::string& name, size_t size, GLbitfield flags) noxnd {
	std::shared_ptr<RawBuffer> buffer = std::make_shared<RawBuffer>(name);
	buffer->Storage(size, flags);
	return buffer;
}

std::shared_ptr<AbstractResource> ResourceFactory::CreateTexture2D(const std::string& name, const OGL_TEXTURE2D_DESC& desc) noxnd {
	std::shared_ptr<RawTexture2D> texture2D = std::make_shared<RawTexture2D>(name, desc.target);
	texture2D->Storage(desc);
	return texture2D;
}

std::shared_ptr<AbstractResource> ResourceFactory::CreateRenderBuffer(const std::string& name, GLenum internal_format, 
	unsigned int width, unsigned int height, unsigned int sample) noxnd {
	std::shared_ptr<RawRenderBuffer> renderbuffer = std::make_shared<RawRenderBuffer>(name);
	renderbuffer->Storage(internal_format, width, height, sample);
	return renderbuffer;
}

//AbstractResource
AbstractResource::AbstractResource(const std::string& name)
	:m_name(name)
{
}

void AbstractResource::SetDebugName(GLenum target, const std::string& tag) noxnd {
	glObjectLabel(target, m_resource, -1, tag.c_str());
}


//RawBuffer
RawBuffer::RawBuffer(const std::string& name) :AbstractResource(name) {
	glCreateBuffers(1, &m_resource);//如果使用glNamedBufferStorage，需要使用glCreateBuffers而不是glGenBuffers生成的buffer，不然会报找不到buffer对象的错误
	SetDebugName(GL_BUFFER, name);
}

RawBuffer::~RawBuffer() {
	glDeleteBuffers(1, &m_resource);
}

void RawBuffer::Bind(GLenum target) noxnd {
	glBindBuffer(target, m_resource);
}

void RawBuffer::Storage(size_t size, GLbitfield flags) noxnd {
	glNamedBufferStorage(m_resource, size, NULL, flags);
}

void RawBuffer::Update(size_t size, size_t offset, const void* data) noxnd {
	glNamedBufferSubData(m_resource, offset, size, data);
}

//RawTexture
RawTexture2D::RawTexture2D(const std::string& name, GLenum target)
	:AbstractResource(name)
{
	glCreateTextures(target, 1, &m_resource);
	SetDebugName(GL_TEXTURE, name);
	m_desc.target = target;
}

RawTexture2D::~RawTexture2D() {
	glDeleteTextures(1, &m_resource);
}

void RawTexture2D::Bind(GLuint unit) noxnd {
	glBindTextureUnit(unit, m_resource);
}

void RawTexture2D::Storage(const OGL_TEXTURE2D_DESC& desc) noxnd {
	m_desc = desc;

	if (desc.arrayslices > 1) {
		if (desc.samplecount > 1) {
			glTextureStorage3DMultisample(m_resource, desc.samplecount, desc.internal_format, desc.width, desc.height, desc.arrayslices,desc.fixed_sample_location);
		}
		else {
			glTextureStorage3D(m_resource, 1, desc.internal_format, desc.width, desc.height, desc.arrayslices);
		}
	}
	else {
		if (desc.samplecount > 1) {
			glTextureStorage2DMultisample(m_resource, desc.samplecount, desc.internal_format, desc.width, desc.height, desc.fixed_sample_location);
		}
		else {
			glTextureStorage2D(m_resource, 1, desc.internal_format, desc.width, desc.height);
		}
	}
}

void RawTexture2D::Update(const OGL_RECT& range, GLenum format, GLenum type, const void* data, bool genMip) noxnd {
	//多重采样纹理一般不能直接更新图像数据，而是需要作为渲染目标更新内部数据
	assert((m_desc.target != GL_TEXTURE_2D_MULTISAMPLE) && (m_desc.target != GL_TEXTURE_2D_MULTISAMPLE_ARRAY));
	
	glTextureSubImage2D(m_resource, 0, range.x, range.y, range.width, range.height, format, type, data);
	

	if ((!m_mipped) && genMip) {
		glGenerateTextureMipmap(m_resource);
		m_mipped = true;
	}
}

void RawTexture2D::UpdateSlice(const OGL_RECT& range, GLenum format, GLenum type, const void* data, unsigned int slice, bool genMip) noxnd {
	//多重采样纹理一般不能直接更新图像数据，而是需要作为渲染目标更新内部数据
	assert((m_desc.target != GL_TEXTURE_2D_MULTISAMPLE) && (m_desc.target != GL_TEXTURE_2D_MULTISAMPLE_ARRAY));

	glTextureSubImage3D(m_resource, 0, range.x, range.y, slice, range.width, range.height, 1, format, type, data);

	if ((!m_mipped) && genMip) {
		glGenerateTextureMipmap(m_resource);
		m_mipped = true;
	}
}

void RawTexture2D::SetParameters(const OGL_TEXTURE_PARAMETER& param) noxnd {
	glTextureParameteri(m_resource, GL_TEXTURE_MIN_FILTER, param.min_filter);
	glTextureParameteri(m_resource, GL_TEXTURE_MAG_FILTER, param.mag_filter);
	glTextureParameteri(m_resource, GL_TEXTURE_WRAP_R, param.wrap_z);
	glTextureParameteri(m_resource, GL_TEXTURE_WRAP_S, param.wrap_x);
	glTextureParameteri(m_resource, GL_TEXTURE_WRAP_T, param.wrap_y);

	if (param.wrap_x == GL_CLAMP_TO_BORDER || param.wrap_y == GL_CLAMP_TO_BORDER) {
		if (param.border_color.has_value()) {
			float color[4]={ param.border_color.value().x,param.border_color.value().y,param.border_color.value().z,param.border_color.value().w };
			glTextureParameterfv(m_resource, GL_TEXTURE_BORDER_COLOR, color);
		}
		else {
			float color[4] = { 0,0,0,0 };
			glTextureParameterfv(m_resource, GL_TEXTURE_BORDER_COLOR, color);
		}
	}
}

void RawTexture2D::GenerateMips() noxnd {
	if (!m_mipped) {
		glGenerateTextureMipmap(m_resource);
	}
}

void RawTexture2D::BindAsRenderTarget(GLuint framebuffer, unsigned int order, unsigned int mip_level) noxnd {
	mip_level = m_mipped ? mip_level : 0;
	glNamedFramebufferTexture(framebuffer, GL_COLOR_ATTACHMENT0 + order, m_resource, mip_level);
}

void RawTexture2D::BindSliceAsRenderTarget(GLuint framebuffer, unsigned int order, unsigned int slice, unsigned int mip_level) noxnd {
	mip_level = m_mipped ? mip_level : 0;
	if (m_desc.target == GL_TEXTURE_2D) {
		BindAsRenderTarget(framebuffer, order, mip_level);
	}
	else {
		glNamedFramebufferTextureLayer(framebuffer, GL_COLOR_ATTACHMENT0 + order, m_resource, mip_level, slice);
	}
}

void RawTexture2D::BindAsDepthStencil(GLuint framebuffer, unsigned int mip_level) noxnd {
	mip_level = m_mipped ? mip_level : 0;
	glNamedFramebufferTexture(framebuffer, GL_DEPTH_STENCIL_ATTACHMENT, m_resource, mip_level);
}

void RawTexture2D::BindSliceAsDepthStencil(GLuint framebuffer, unsigned int slice, unsigned int mip_level) noxnd {
	mip_level = m_mipped ? mip_level : 0;
	if (m_desc.target == GL_TEXTURE_2D) {
		BindAsDepthStencil(framebuffer, mip_level);
	}
	else {
		glNamedFramebufferTextureLayer(framebuffer, GL_DEPTH_STENCIL_ATTACHMENT, m_resource, mip_level, slice);
	}
}

void RawTexture2D::BindAsDepthComponent(GLuint framebuffer, unsigned int mip_level) noxnd {
	mip_level = m_mipped ? mip_level : 0;
	glNamedFramebufferTexture(framebuffer, GL_DEPTH_ATTACHMENT, m_resource, mip_level);
}

void RawTexture2D::BindSliceAsDepthComponent(GLuint framebuffer, unsigned int slice, unsigned int mip_level) noxnd {
	mip_level = m_mipped ? mip_level : 0;
	if (m_desc.target == GL_TEXTURE_2D) {
		BindAsDepthComponent(framebuffer, mip_level);
	}
	else {
		glNamedFramebufferTextureLayer(framebuffer, GL_DEPTH_ATTACHMENT, m_resource, mip_level, slice);
	}
}

bool RawTexture2D::DepthOnly() const noexcept {
	return m_desc.internal_format == GL_DEPTH_COMPONENT24 || m_desc.internal_format == GL_DEPTH_COMPONENT32 || m_desc.internal_format == GL_DEPTH_COMPONENT32F;
}

//RenderBuffer
RawRenderBuffer::RawRenderBuffer(const std::string& name) :AbstractResource(name) {
	glCreateRenderbuffers(1, &m_resource);
	SetDebugName(GL_RENDERBUFFER, name);
}

RawRenderBuffer::~RawRenderBuffer() {
	glDeleteRenderbuffers(1, &m_resource);
}

void RawRenderBuffer::Bind() noxnd {
	glBindRenderbuffer(GL_RENDERBUFFER, m_resource);
}

void RawRenderBuffer::Storage(GLenum internal_format, unsigned int width, unsigned int height, unsigned int sample_count) noxnd {
	if (sample_count == 1) {
		glNamedRenderbufferStorage(m_resource, internal_format, width, height);
	}
	else {
		glNamedRenderbufferStorageMultisample(m_resource, sample_count, internal_format, width, height);
	}
}

void RawRenderBuffer::BindAsRenderTarget(GLuint framebuffer, unsigned int order) noxnd {
	glNamedFramebufferRenderbuffer(framebuffer, GL_COLOR_ATTACHMENT0 + order, GL_RENDERBUFFER, m_resource);
}

void RawRenderBuffer::BindAsDepthStencil(GLuint framebuffer) noxnd {
	glNamedFramebufferRenderbuffer(framebuffer, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, m_resource);
}

void RawRenderBuffer::BindAsDepthComponent(GLuint framebuffer) noxnd {
	glNamedFramebufferRenderbuffer(framebuffer, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, m_resource);
}