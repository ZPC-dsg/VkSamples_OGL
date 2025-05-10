#pragma once

#include <Bindables/includer.h>

namespace Bind {
	class ViewScissor :public Bindable {
	public:
		ViewScissor();
		ViewScissor(const OGL_VIEWPORT_SCISSOR_STATE& vsstate);
		~ViewScissor() = default;

		void Bind() noxnd override;
		static std::shared_ptr<ViewScissor> Resolve(const OGL_VIEWPORT_SCISSOR_STATE& vsstate);
		static std::shared_ptr<ViewScissor> Resolve();
		static std::string GenerateUID(const OGL_VIEWPORT_SCISSOR_STATE& vsstate);
		static std::string GenerateUID();
		std::string GetUID() const noexcept override;

		std::type_index GetTypeInfo() const noexcept override;

	private:
		OGL_VIEWPORT_SCISSOR_STATE m_state;
	};
}