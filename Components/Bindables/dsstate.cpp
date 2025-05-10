#include <Bindables/dsstate.h>

namespace Bind {
	DepthStencilState::DepthStencilState(const OGL_DEPTH_STENCIL_STATE& dsstate) 
		: m_state(dsstate) 
	{
	}

	void DepthStencilState::Bind() noxnd {
		if (m_state.depth_enabled) {
			glEnable(GL_DEPTH_TEST);

			if (!m_state.depth_write_enabled) {
				glDepthMask(GL_FALSE);
			}

			glDepthFunc(m_state.depth_compare_op);
		}
		else {
			glDisable(GL_DEPTH_TEST);
			glDepthMask(GL_TRUE);//»Ö¸´Éî¶ÈÐ´Èë×´Ì¬
		}

		if (m_state.stencil_enabled) {
			glEnable(GL_STENCIL_TEST);
			glStencilMask(m_state.stencil_write_mask);
			glStencilFunc(m_state.stencil_compare_op, m_state.stencil_ref, m_state.stencil_compare_mask);
			glStencilOp(m_state.stencil_fail_op, m_state.stencil_pass_depth_fail_op, m_state.depth_pass_op);
		}
		else {
			glDisable(GL_STENCIL_TEST);
		}
	}

	std::shared_ptr<DepthStencilState> DepthStencilState::Resolve(const OGL_DEPTH_STENCIL_STATE& dsstate) {
		return BindableResolver::Resolve<DepthStencilState>(dsstate);
	}

	std::string DepthStencilState::GenerateUID(const OGL_DEPTH_STENCIL_STATE& mode) {
		using namespace std::string_literals;
		return typeid(DepthStencilState).name() + "#"s + OGL_DEPTH_STENCIL_STATE::GlobalTag(mode);
	}

	std::string DepthStencilState::GetUID() const noexcept {
		return GenerateUID(m_state);
	}

	std::type_index DepthStencilState::GetTypeInfo() const noexcept {
		return typeid(DepthStencilState);
	}
}