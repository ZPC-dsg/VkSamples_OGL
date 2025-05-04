#include <Dynamic/shader_reflection_resolver.h>

namespace Dynamic {
	namespace Dsr {
		std::unordered_map<GLuint, std::unordered_map<std::string, std::vector<Dynamic::Dsr::ConstantAttrib>>> ShaderReflectionResolver::constant_map;

		const std::vector<Dynamic::Dsr::ConstantAttrib>& ShaderReflectionResolver::ResolveForCBuffer(std::shared_ptr<Bind::ShaderProgram> program, const std::string& name) {
			const auto i = constant_map.find(program->get_program());
			if (i != constant_map.end()) {
				assert("Constant buffer name is invalid for this shader program!" && i->second.contains(name));
				return i->second[name];
			}
			else {
				const auto& cb = ShaderReflection::GetConstantAttribs(program->get_program());
				constant_map[program->get_program()] = cb;
				assert("Constant buffer name is invalid for this shader program!" && cb.contains(name));
				return constant_map[program->get_program()][name];
			}
		}
	}
}