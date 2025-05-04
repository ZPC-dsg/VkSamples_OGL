#pragma once

#include <Bindables/shaderprogram.h>

namespace Dynamic {
	namespace Dsr {
		class ShaderReflectionResolver {
		public:
			static const std::vector<Dynamic::Dsr::ConstantAttrib>& ResolveForCBuffer(std::shared_ptr<Bind::ShaderProgram> program, const std::string& name);

		private:
			ShaderReflectionResolver() = default;

			static ShaderReflectionResolver& Get() {
				static ShaderReflectionResolver resolver;
				return resolver;
			}

		private:
			static std::unordered_map<GLuint, std::unordered_map<std::string, std::vector<Dynamic::Dsr::ConstantAttrib>>> constant_map;
		};
	}
}