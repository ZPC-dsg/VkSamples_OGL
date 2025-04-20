#include <Bindables/dsstate.h>

namespace Bind {
	std::unordered_map<DepthStencilState::DSModes, std::string> DepthStencilState::name_map = { {Normal,std::string("normal")},
		{DepthReverse,std::string("depth_reverse")},{DepthOff,std::string("depth_off")},{DepthWriteOff,"depthwrite_off"} };

	DepthStencilState::DepthStencilState(DSModes mode) :m_mode(mode) {
		if (mode & DepthReverse) {
			(*this).with_depth_func(GL_GREATER);
		}
		else if (mode & DepthOff) {
			(*this).with_depth_test(false).with_depth_write(false);
		}
		else if (mode & DepthWriteOff) {
			(*this).with_depth_write(false);
		}
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

	std::shared_ptr<DepthStencilState> DepthStencilState::Resolve(DSModes mode) {
		return BindableResolver::Resolve<DepthStencilState>(mode);
	}

	std::string DepthStencilState::GenerateUID(DSModes mode) {
		using namespace std::string_literals;
		return typeid(DepthStencilState).name() + "#"s + name_map[mode];
	}

	std::string DepthStencilState::GetUID() const noexcept {
		return GenerateUID(m_mode);
	}
	DepthStencilState& DepthStencilState::with_depth_func(GLenum func) {
		m_state.depth_compare_op = func;
		return (*this);
	}
	DepthStencilState& DepthStencilState::with_depth_test(bool on) {
		m_state.depth_enabled = on;
		return (*this);
	}
	DepthStencilState& DepthStencilState::with_depth_write(bool on) {
		m_state.depth_write_enabled = on;
		return (*this);
	}
	DepthStencilState& DepthStencilState::with_stencil(bool on) {
		m_state.stencil_enabled = on;
		return (*this);
	}
	DepthStencilState& DepthStencilState::with_stencil_func(GLenum func) {
		m_state.stencil_compare_op = func;
		return (*this);
	}
	DepthStencilState& DepthStencilState::with_stencil_compare_mask(GLuint mask) {
		m_state.stencil_compare_mask = mask;
		return (*this);
	}
	DepthStencilState& DepthStencilState::with_stencil_write_mask(GLuint mask) {
		m_state.stencil_write_mask = mask;
		return (*this);
	}
	DepthStencilState& DepthStencilState::with_stencil_ref(GLint ref) {
		m_state.stencil_ref = ref;
		return (*this);
	}
	DepthStencilState& DepthStencilState::with_stencil_fail_op(GLenum op) {
		m_state.stencil_fail_op = op;
		return (*this);
	}
	DepthStencilState& DepthStencilState::with_stencil_pass_depth_fail_op(GLenum op) {
		m_state.stencil_pass_depth_fail_op = op;
		return (*this);
	}
	DepthStencilState& DepthStencilState::with_depth_pass_op(GLenum op) {
		m_state.depth_pass_op = op;
		return (*this);
	}
}