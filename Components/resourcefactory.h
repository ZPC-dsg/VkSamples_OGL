#pragma once

#include <nocopyable.h>
#include <Macros/conditional_noexcept.h>
#include <ogl_structures.h>

#include <glad/glad.h>
#include <memory>
#include <string>
#include <array>

class AbstractResource;

class ResourceFactory :private NoCopyable {
public:
	static ResourceFactory& GetInstance() {
		static ResourceFactory factory;
		return factory;
	}

	static std::shared_ptr<AbstractResource> CreateBuffer(const std::string& name, size_t size, GLbitfield flags = 0) noxnd;
	static std::shared_ptr<AbstractResource> CreateTexture2D(const std::string& name, const OGL_TEXTURE2D_DESC& desc) noxnd;
	static std::shared_ptr<AbstractResource> CreateRenderBuffer(const std::string& name, GLenum internal_format, unsigned int width, unsigned int height, 
		unsigned int sample = 1) noxnd;

private:
	ResourceFactory() = default;
};


class AbstractResource :private NoCopyable {
	friend class ResourceFactory;
public:
	virtual ~AbstractResource() = default;

	void SetDebugName(GLenum target, const std::string& tag) noxnd;

	inline std::string ResourceName() const noexcept { return m_name; }

protected:
	AbstractResource(const std::string& name);

protected:
	GLuint m_resource;
	std::string m_name;
};

class RawBuffer :public AbstractResource {
	friend class ResourceFactory;
public:
	~RawBuffer();

	void Bind(GLenum target) noxnd;
	void BindBase(GLenum target, unsigned int binding_point) noxnd;
	void Storage(size_t size, GLbitfield flags) noxnd;
	void UpdateCopy(size_t size, size_t offset, const void* data) noxnd;
	void UpdataMap(size_t size, size_t offset, const void* data) noxnd;
	void MapRange(size_t offset, size_t length, GLbitfield flags = 0) noxnd;
	bool UnMapRange() noxnd;
	inline GLbitfield StorageFlags() const noexcept { return m_storage_flags; };
	inline bool HasFlag(GLbitfield flag) const noexcept { return (m_storage_flags & flag) == flag; };

private:
	RawBuffer(const std::string& name);

private:
	GLbitfield m_storage_flags = 0;
	void* m_data_pointer;
	bool m_is_mapped = false;
};

class RawTexture2D :public AbstractResource {
	friend class ResourceFactory;
public:
	~RawTexture2D();

	void Bind(GLuint unit) noxnd;
	void Storage(const OGL_TEXTURE2D_DESC& desc) noxnd;
	void Update(const OGL_RECT& range, GLenum format, GLenum type, const void* data, bool genMip = false) noxnd;
	void UpdateSlice(const OGL_RECT& range, GLenum format, GLenum type, const void* data, unsigned int slice = 0, bool genMip = false) noxnd;
	void GenerateMips() noxnd;
	void SetParameters(const OGL_TEXTURE_PARAMETER& params) noxnd;

	void BindAsRenderTarget(GLuint framebuffer, unsigned int order, unsigned int mip_level = 0) noxnd;
	void BindSliceAsRenderTarget(GLuint framebuffer, unsigned int order, unsigned int slice, unsigned int mip_level = 0) noxnd;//立方体贴图纹理的slice指定绑定的面
	void BindAsDepthStencil(GLuint framebuffer, unsigned int mip_level = 0) noxnd;
	void BindSliceAsDepthStencil(GLuint framebuffer, unsigned int slice, unsigned int mip_level = 0) noxnd;
	void BindAsDepthComponent(GLuint framebuffer, unsigned int mip_level = 0) noxnd;
	void BindSliceAsDepthComponent(GLuint framebuffer, unsigned int slice, unsigned int mip_level = 0) noxnd;

	inline OGL_TEXTURE2D_DESC GetDescription() const noexcept { return m_desc; }
	bool DepthOnly() const noexcept;

private:
	RawTexture2D(const std::string& name, GLenum target);

private:
	OGL_TEXTURE2D_DESC m_desc;
	bool m_mipped = false;
};

class RawRenderBuffer :public AbstractResource {
	friend class ResourceFactory;
public:
	~RawRenderBuffer();

	void Bind() noxnd;
	void Storage(GLenum internal_format, unsigned int width, unsigned int height, unsigned int sample_count = 1) noxnd;

	void BindAsRenderTarget(GLuint framebuffer, unsigned int order) noxnd;
	void BindAsDepthStencil(GLuint framebuffer) noxnd;
	void BindAsDepthComponent(GLuint framebuffer) noxnd;

private:
	RawRenderBuffer(const std::string& name);
};


extern ResourceFactory& MainFactory;