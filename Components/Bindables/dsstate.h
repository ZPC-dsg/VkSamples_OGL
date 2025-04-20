#pragma once

#include <Bindables/bindable.h>
#include <Bindables/bindable_resolver.h>
#include <unordered_map>

namespace Bind {
	class DepthStencilState :public Bindable {
	public:
		enum DSModes {
			Normal = 1,
			DepthReverse = 2,
			DepthOff = 4,
			DepthWriteOff = 8
		};
		DepthStencilState(DSModes mode);
		~DepthStencilState() = default;

		void Bind() noxnd override;
		static std::shared_ptr<DepthStencilState> Resolve(DSModes mode);
		static std::string GenerateUID(DSModes mode);
		std::string GetUID() const noexcept override;

	private:
		DepthStencilState& with_depth_test(bool on);
		DepthStencilState& with_depth_write(bool on);
		DepthStencilState& with_stencil(bool on);
		DepthStencilState& with_depth_func(GLenum func);
		DepthStencilState& with_stencil_func(GLenum func);
		DepthStencilState& with_stencil_compare_mask(GLuint mask);
		DepthStencilState& with_stencil_write_mask(GLuint mask);
		DepthStencilState& with_stencil_ref(GLint ref);
		DepthStencilState& with_stencil_fail_op(GLenum op);
		DepthStencilState& with_stencil_pass_depth_fail_op(GLenum op);
		DepthStencilState& with_depth_pass_op(GLenum op);

	private:
		struct DSState_OGL {
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
		};

		DSState_OGL m_state;
		DSModes m_mode;

		static std::unordered_map<DSModes, std::string> name_map;
	};
}