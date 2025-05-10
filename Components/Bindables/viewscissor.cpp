#include <Bindables/viewscissor.h>
#include <init.h>

namespace Bind {
	ViewScissor::ViewScissor() {
		m_state.viewport.width = globalSettings::screen_width;
		m_state.viewport.height = globalSettings::screen_height;
	}

	ViewScissor::ViewScissor(const OGL_VIEWPORT_SCISSOR_STATE& vsstate)
		:m_state(vsstate)
	{
	}

	void ViewScissor::Bind() noxnd {
		glViewport(m_state.viewport.x, m_state.viewport.y, m_state.viewport.width, m_state.viewport.height);

		if (m_state.scissor_enabled) {
			glEnable(GL_SCISSOR_TEST);
			glScissor(m_state.scissor.x, m_state.scissor.y, m_state.scissor.width, m_state.scissor.height);
		}
		else {
			glDisable(GL_SCISSOR_TEST);
		}
	}

	std::shared_ptr<ViewScissor> ViewScissor::Resolve(const OGL_VIEWPORT_SCISSOR_STATE& vsstate) {
		return BindableResolver::Resolve<ViewScissor>(vsstate);
	}

	std::shared_ptr<ViewScissor> ViewScissor::Resolve() {
		OGL_VIEWPORT_SCISSOR_STATE state;
		state.viewport.width= globalSettings::screen_width;
		state.viewport.height= globalSettings::screen_height;
		return BindableResolver::Resolve<ViewScissor>(state);
	}

	std::string ViewScissor::GenerateUID(const OGL_VIEWPORT_SCISSOR_STATE& vsstate) {
		using namespace std::string_literals;
		return typeid(ViewScissor).name() + "#"s + OGL_VIEWPORT_SCISSOR_STATE::GlobalTag(vsstate);
	}

	std::string ViewScissor::GenerateUID() {
		using namespace std::string_literals;
		OGL_VIEWPORT_SCISSOR_STATE state;
		state.viewport.width = globalSettings::screen_width;
		state.viewport.height = globalSettings::screen_height;
		return typeid(ViewScissor).name() + "#"s + OGL_VIEWPORT_SCISSOR_STATE::GlobalTag(state);
	}

	std::string ViewScissor::GetUID() const noexcept {
		return GenerateUID(m_state);
	}

	std::type_index ViewScissor::GetTypeInfo() const noexcept {
		return typeid(ViewScissor);
	}
}