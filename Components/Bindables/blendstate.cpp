#include <Bindables/blendstate.h>

namespace Bind {
	BlendState::BlendState(const OGL_BLEND_STATE& blend_state) 
		:m_blendstate(blend_state)
	{
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

	std::shared_ptr<BlendState> BlendState::Resolve(const OGL_BLEND_STATE& blend_state) {
		return BindableResolver::Resolve<BlendState>(blend_state);
	}

	std::string BlendState::GenerateUID(const OGL_BLEND_STATE& blend_state) {
		using namespace std::string_literals;

		return typeid(BlendState).name() + "#"s + OGL_BLEND_STATE::GlobalTag(blend_state);
	}

	std::string BlendState::GetUID() const noexcept {
		return GenerateUID(m_blendstate);
	}
}