#include <Bindables/blendstate.h>

namespace Bind {
	BlendState::BlendState(std::optional<glm::vec4> factor) {
		if (factor.has_value()) {
			(*this).with_scr_blend(GL_CONSTANT_COLOR).with_dst_blend(GL_ONE_MINUS_CONSTANT_COLOR).with_src_alp_blend(GL_CONSTANT_ALPHA)
				.with_dst_alp_blend(GL_ONE_MINUS_CONSTANT_ALPHA).with_factor(factor.value());
		}
	}

	void BlendState::Bind() noxnd {
		glEnable(GL_BLEND);
		glBlendFuncSeparate(m_blendstate.src_blend_func, m_blendstate.dst_blend_func, m_blendstate.src_alp_blend_func, m_blendstate.dst_alp_blend_func);
		glBlendEquation(m_blendstate.blend_eq);
		glBlendColor(0.0, 0.0, 0.0, 0.0);
		if (m_blendstate.blend_factor.has_value()) {
			glBlendColor(m_blendstate.blend_factor.value().x, m_blendstate.blend_factor.value().y, m_blendstate.blend_factor.value().z, m_blendstate.blend_factor.value().w);
		}
	}

	std::shared_ptr<BlendState> BlendState::Resolve(std::optional<glm::vec4> color) {
		return BindableResolver::Resolve<BlendState>(color);
	}

	std::string BlendState::GenerateUID(std::optional<glm::vec4> color) {
		using namespace std::string_literals;

		return typeid(BlendState).name() + "#"s + (color.has_value() ? "#f"s + std::to_string(color.value().x) + "#f"s + std::to_string(color.value().y) 
			+ "#f"s + std::to_string(color.value().z) + "#f"s + std::to_string(color.value().w) : "");
	}

	std::string BlendState::GetUID() const noexcept {
		return GenerateUID(m_blendstate.blend_factor);
	}

	BlendState& BlendState::with_dst_alp_blend(GLenum dst_alp_blend) {
		m_blendstate.dst_alp_blend_func = dst_alp_blend;
		return *this;
	}

	BlendState& BlendState::with_dst_blend(GLenum dst_blend) {
		m_blendstate.dst_blend_func = dst_blend;
		return *this;
	}

	BlendState& BlendState::with_equation(GLenum eq) {
		m_blendstate.blend_eq = eq;
		return *this;
	}

	BlendState& BlendState::with_factor(const glm::vec4& color) {
		m_blendstate.blend_factor = color;
		return *this;
	}

	BlendState& BlendState::with_scr_blend(GLenum src_blend) {
		m_blendstate.src_blend_func = src_blend;
		return *this;
	}

	BlendState& BlendState::with_src_alp_blend(GLenum src_alp_blend) {
		m_blendstate.src_alp_blend_func = src_alp_blend;
		return *this;
	}
}