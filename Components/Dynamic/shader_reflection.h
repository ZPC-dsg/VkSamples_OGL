#pragma once

#include <Bindables/shaderprogram.h>
#include <shader.h>

#include <glad/glad.h>

namespace Dynamic {
	namespace Dsr {
		struct VertexAttrib {
			GLuint location;
			GLenum type;
			GLint size;
			std::string name;
		};

		class ShaderReflection {
		public:
			ShaderReflection(std::shared_ptr<Bind::ShaderProgram> program);
			ShaderReflection(std::shared_ptr<Shader> shader);
			~ShaderReflection() = default;

			std::vector<Dynamic::Dsr::VertexAttrib> GetVertexAttribs() noxnd;

		private:
			std::shared_ptr<Bind::ShaderProgram> m_program;
		};
	}
}