#pragma once

#include <Bindables/includer.h>

namespace Bind {
	class Rasterizer :public Bindable{
	public:
		Rasterizer(const OGL_RASTERIZER_STATE& rststate);
		~Rasterizer() = default;

		void Bind() noxnd override;
		static std::shared_ptr<Rasterizer> Resolve(const OGL_RASTERIZER_STATE& rststate);
		static std::string GenerateUID(const OGL_RASTERIZER_STATE& rststate);
		std::string GetUID() const noexcept override;

		std::type_index GetTypeInfo() const noexcept override;

	private:
		OGL_RASTERIZER_STATE m_state;
	};
}