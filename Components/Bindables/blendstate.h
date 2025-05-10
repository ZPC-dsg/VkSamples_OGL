#pragma once

#include <Bindables/includer.h>

#include <glad/glad.h>
#include <optional>
#include <glm/glm.hpp>

namespace Bind {
	class BlendState :public Bindable {
	public:
		BlendState() = default;
		BlendState(const OGL_BLEND_STATE& blend_state);
		~BlendState() = default;

		void Bind() noxnd override;
		static std::shared_ptr<BlendState> Resolve(const OGL_BLEND_STATE& blend_state);
		static std::string GenerateUID(const OGL_BLEND_STATE& blend_state);
		std::string GetUID() const noexcept override;

		inline glm::vec4 get_factor() { return m_blendstate.blend_factor ? m_blendstate.blend_factor.value() : glm::vec4(-1); }

		std::type_index GetTypeInfo() const noexcept override;

	private:
		OGL_BLEND_STATE m_blendstate;
	};
}