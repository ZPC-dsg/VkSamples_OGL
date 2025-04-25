#pragma once

#include <glad/glad.h>
#include <optional>
#include <glm/glm.hpp>
#include <string>
#include <vector>
#include <utility>

struct OGL_BLEND_STATE {
	GLenum src_blend_func = GL_ONE;
	GLenum dst_blend_func = GL_ZERO;
	GLenum src_alp_blend_func = GL_ONE;
	GLenum dst_alp_blend_func = GL_ZERO;

	GLenum blend_eq = GL_FUNC_ADD;

	std::optional<glm::vec4> blend_factor;

	static std::string GlobalTag(OGL_BLEND_STATE state) noexcept;
};

struct OGL_DEPTH_STENCIL_STATE {
	bool depth_enabled = true;
	bool depth_write_enabled = true;
	bool stencil_enabled = false;

	GLenum depth_compare_op = GL_LEQUAL;

	GLenum stencil_compare_op = GL_ALWAYS;
	GLuint stencil_compare_mask = 0xFF;
	GLuint stencil_write_mask = 0xFF;
	GLint stencil_ref = 0;

	GLenum stencil_fail_op = GL_KEEP;
	GLenum stencil_pass_depth_fail_op = GL_KEEP;
	GLenum depth_pass_op = GL_KEEP;

	static std::string GlobalTag(OGL_DEPTH_STENCIL_STATE state) noexcept;
};

struct OGL_RASTERIZER_STATE {
	bool cull_enabled = false;
	bool polygon_offset_enabled = false;
	bool depth_clamp_enabled = true;

	GLenum fill_mode = GL_FILL;
	GLenum cull_mode = GL_BACK;
	GLenum front_face = GL_CCW;

	float line_width = 1.0;
	float point_size = 1.0;

	float depth_bias = 0.0;
	float slope_scaled_depth_bias = 0.0f;

	static std::string GlobalTag(OGL_RASTERIZER_STATE state) noexcept;
};

struct OGL_RECT {
	float x = 0.0;
	float y = 0.0;
	float width = 0.0;
	float height = 0.0;

	static std::string GlobalTag(OGL_RECT state) noexcept;
};

struct OGL_VIEWPORT_SCISSOR_STATE {
	friend class ViewScissor;
public:
	bool scissor_enabled = false;

	OGL_RECT viewport;
	OGL_RECT scissor;

	static std::string GlobalTag(OGL_VIEWPORT_SCISSOR_STATE state) noexcept;
};

struct OGL_INPUT_ELEMENT_DESC {
	GLuint sementic_location;
	GLint element_count;
	unsigned int element_column;//如果是矩阵，需要每一列指定一个顶点属性
	GLenum element_type;
	size_t byteoffset;
};

struct OGL_TEXTURE2D_DESC {
	GLenum target;

	GLsizei width = 0.0;
	GLsizei height = 0.0;

	GLenum internal_format = GL_RGB8;//GPU端的图像数据存储格式，使用NamedStorage系列函数指定内存的时候必须使用sized格式，也就是基础格式后面要加上通道占用位数等信息
	GLenum cpu_format = GL_RGB;//CPU端的图像数据存储格式
	GLenum data_type = GL_UNSIGNED_BYTE;//单通道图像数据格式

	unsigned int arrayslices = 1;
	unsigned int samplecount = 1;

	bool fixed_sample_location = true;

	static std::string GlobalTag(OGL_TEXTURE2D_DESC desc) noexcept;
};

struct OGL_TEXTURE_PARAMETER {
	GLenum min_filter = GL_LINEAR;
	GLenum mag_filter = GL_LINEAR;

	GLenum wrap_x = GL_REPEAT;
	GLenum wrap_y = GL_REPEAT;
	GLenum wrap_z = GL_REPEAT;

	std::optional<glm::vec4> border_color;

	static std::string GlobalTag(OGL_TEXTURE_PARAMETER param) noexcept;
};

namespace {
	template <typename T>
	struct StringMap {
		static std::string Convert(const T& object) {
			return std::to_string(object);
		}
	};

	template <typename T>
	concept array_pointer_obj = std::is_array_v<T> || std::is_pointer_v<T>;

	template <array_pointer_obj T>
	struct StringMap<T> {
		static std::string Convert(T object, size_t sz = 1) {
			std::string tag;

			for (int i = 0; i < sz; i++) {
				tag += StringMap<decltype(object[0])>::Convert(object[i]);
			}

			return tag;
		}
	};

	template <typename T>
	struct StringMap<std::vector<T>> {
		static std::string Convert(std::vector<T> object, size_t sz = 1) {
			assert(object.size() >= sz);

			return StringMap<T*>::Convert(object.data(), sz);
		}
	};

	template <>
	struct StringMap<glm::vec4> {
		static std::string Convert(const glm::vec4& object) {
			float data[4]{ object.x,object.y,object.z,object.w };
			return StringMap<float*>::Convert(data, 4);
		}
	};

	template <>
	struct StringMap<bool> {
		static std::string Convert(const bool& object) {
			return object ? std::string("true") : std::string("false");
		}
	};

	template <typename T>
	struct StringMap<std::optional<T>> {
		static std::string Convert(std::optional<T> object) {
			return object.has_value() ? std::string("hasVal:") + StringMap<T>::Convert(object.value()) : std::string("noVal!");
		}
	};
}

template <typename... Args>
static std::string Resolver(Args&&... args) {
	return (std::string{} + ... + StringMap<typename std::remove_cvref<Args>::type>::Convert(std::forward<Args>(args)));
}