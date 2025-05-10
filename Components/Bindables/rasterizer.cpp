#include <Bindables/rasterizer.h>

namespace Bind {
	Rasterizer::Rasterizer(const OGL_RASTERIZER_STATE& rststate)
		:m_state(rststate)
	{
	}

	void Rasterizer::Bind() noxnd {
		glFrontFace(m_state.front_face);
		glPolygonMode(GL_FRONT_AND_BACK, m_state.fill_mode);
		glLineWidth(m_state.line_width);

		if (m_state.point_size > 1.0) {
			glEnable(GL_PROGRAM_POINT_SIZE);
			glPointSize(m_state.point_size);
		}
		else {
			glDisable(GL_PROGRAM_POINT_SIZE);
		}

		if (m_state.cull_enabled) {
			glEnable(GL_CULL_FACE);
			glCullFace(m_state.cull_mode);
		}
		else {
			glCullFace(GL_BACK);
			glDisable(GL_CULL_FACE);
		}

		if (m_state.polygon_offset_enabled) {
			glEnable(GL_POLYGON_OFFSET_FILL);
			glPolygonOffset(m_state.slope_scaled_depth_bias, m_state.depth_bias);
		}
		else {
			glDisable(GL_POLYGON_OFFSET_FILL);
		}

		if (m_state.depth_clamp_enabled) {
			glEnable(GL_DEPTH_CLAMP);
		}
		else {
			glDisable(GL_DEPTH_CLAMP);
		}
	}

	std::shared_ptr<Rasterizer> Rasterizer::Resolve(const OGL_RASTERIZER_STATE& rststate) {
		return BindableResolver::Resolve<Rasterizer>(rststate);
	}

	std::string Rasterizer::GenerateUID(const OGL_RASTERIZER_STATE& rststate) {
		using namespace std::string_literals;
		return typeid(Rasterizer).name() + "#"s + OGL_RASTERIZER_STATE::GlobalTag(rststate);
	}

	std::string Rasterizer::GetUID() const noexcept {
		return GenerateUID(m_state);
	}

	std::type_index Rasterizer::GetTypeInfo() const noexcept {
		return typeid(Rasterizer);
	}
}