#pragma once

#include <Bindables/includer.h>

#include <unordered_map>

namespace Bind {
	class DepthStencilState :public Bindable {
	public:
		DepthStencilState(const OGL_DEPTH_STENCIL_STATE& dsstate);
		~DepthStencilState() = default;

		void Bind() noxnd override;
		static std::shared_ptr<DepthStencilState> Resolve(const OGL_DEPTH_STENCIL_STATE& mode);
		static std::string GenerateUID(const OGL_DEPTH_STENCIL_STATE& mode);
		std::string GetUID() const noexcept override;

		std::type_index GetTypeInfo() const noexcept override;

	private:
		OGL_DEPTH_STENCIL_STATE m_state;
	};
}