#pragma once

#include <Bindables/bindable.h>
#include <Bindables/bindable_resolver.h>

#include <glad/glad.h>
#include <optional>
#include <glm/glm.hpp>

namespace Bind {
	class BlendState :public Bindable {
	public:
		BlendState() = default;
		BlendState(std::optional<glm::vec4> factor);
		~BlendState() = default;

		void Bind() noxnd override;
		static std::shared_ptr<BlendState> Resolve(std::optional<glm::vec4> factor = {});
		static std::string GenerateUID(std::optional<glm::vec4> factor);
		std::string GetUID() const noexcept override;

		BlendState& with_factor(const glm::vec4& color);
		BlendState& with_scr_blend(GLenum src_blend);
		BlendState& with_dst_blend(GLenum dst_blend);
		BlendState& with_src_alp_blend(GLenum src_alp_blend);
		BlendState& with_dst_alp_blend(GLenum dst_alp_blend);
		BlendState& with_equation(GLenum equation);

		inline glm::vec4 get_factor() { return m_blendstate.blend_factor ? m_blendstate.blend_factor.value() : glm::vec4(-1); }

	private:
		struct BlendState_OGL {
			GLenum src_blend_func = GL_ONE;
			GLenum dst_blend_func = GL_ZERO;
			GLenum src_alp_blend_func = GL_ONE;
			GLenum dst_alp_blend_func = GL_ZERO;

			GLenum blend_eq = GL_FUNC_ADD;

			std::optional<glm::vec4> blend_factor;
		};

		BlendState_OGL m_blendstate;
	};
}