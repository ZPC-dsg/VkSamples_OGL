#include <Dynamic/shader_reflection.h>

#include <algorithm>

namespace Dynamic {
	namespace Dsr {
		ShaderReflection::ShaderReflection(std::shared_ptr<Bind::ShaderProgram> program)
			:m_program(program)
		{
		}

		ShaderReflection::ShaderReflection(std::shared_ptr<Shader> shader)
			:m_program(std::make_shared<Bind::ShaderProgram>(shader->ID))
		{
		}

		std::vector<VertexAttrib> ShaderReflection::GetVertexAttribs() noxnd {
			std::vector<VertexAttrib> attribs;

			GLint active_attribs;
			glGetProgramiv(m_program->get_program(), GL_ACTIVE_ATTRIBUTES, &active_attribs);
			attribs.reserve(active_attribs);

			const size_t buff_size = 100;
			for (GLuint i = 0; i < (GLuint)active_attribs; i++) {
				VertexAttrib element;

				GLsizei length;
				char name[buff_size];

				glGetActiveAttrib(m_program->get_program(), i, buff_size, &length, &element.size, &element.type, name);
				element.name = std::string(name);
				element.location = glGetAttribLocation(m_program->get_program(), name);

				attribs.push_back(element);
			}

			//按location从小到大排列
			std::ranges::sort(attribs, [](const VertexAttrib& lhs, const VertexAttrib& rhs)->bool {return lhs.location < rhs.location; });

			return attribs;
		}
	}
}