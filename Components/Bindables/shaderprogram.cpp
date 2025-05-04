#include <Bindables/shaderprogram.h>
#include <Dynamic/dynamic_constant.h>
#include <tools.h>

namespace Bind {
	ShaderProgram::ShaderProgram(const std::string& tag, std::vector<GLuint> shaders) 
		:m_tag(tag)
	{
        m_program = glCreateProgram();
		for (GLuint s : shaders) {
			glAttachShader(m_program, s);
		}
        glLinkProgram(m_program);
        CheckCompileErrors(m_program);

        glObjectLabel(GL_PROGRAM, m_program, -1, tag.c_str());

		auto uniforms = Dynamic::Dsr::ShaderReflection::GetUniformAttribs(m_program);
		for (auto p : uniforms) {
			m_uniforms.emplace(p.first, Dynamic::Dcb::CPUUniformBlock(Dynamic::Dsr::UniformEntryPoint(p.first, p.second)));
		}
	}

	ShaderProgram::ShaderProgram(GLuint ID) :m_program(ID) {};

	ShaderProgram::~ShaderProgram() {
		glDeleteProgram(m_program);
	}

	void ShaderProgram::Bind() noxnd {
		glUseProgram(m_program);

		GLint location;
		for (auto& p : m_uniforms) {
			if (p.second.IsDirty()) {
				for (int i = 0; i < p.second.UniformAmount(); i++) {
					if (p.second.UniformIsDirty(i)) {
						const auto& info = p.second.UniformInformation(i, location);
						UpdataUniform(p.second.UniformType(i), location, info);
					}
				}
			}

			p.second.ClearAllFlags();
		}
	}

	std::shared_ptr<ShaderProgram> ShaderProgram::Resolve(const std::string& tag, std::vector<GLuint> shaders) {
		return BindableResolver::Resolve<ShaderProgram>(tag, shaders);
	}

	std::string ShaderProgram::GenerateUID(const std::string& tag, std::vector<GLuint> shaders) {
		using namespace std::string_literals;

		return typeid(ShaderProgram).name() + "#"s + tag;
	}

	std::string ShaderProgram::GetUID() const noexcept {
		return GenerateUID(m_tag, std::vector<GLuint>());
	}

	Dynamic::Dcb::CPUUniformBlock& ShaderProgram::operator[](const std::string& key) noxnd {
		assert("Name doesn't corresponde to a valid uniform name in this shader!" && m_uniforms.contains(key));
		return m_uniforms[key];
	}

	Dynamic::Dcb::CPUUniformBlock& ShaderProgram::EditUniform(const std::string& key) noxnd {
		return (*this)[key];
	}

	void ShaderProgram::CheckCompileErrors(GLuint program)
	{
		GLint success;
		GLchar infoLog[1024];
		glGetProgramiv(program, GL_LINK_STATUS, &success);
		if (!success)
		{
			glGetProgramInfoLog(program, 1024, NULL, infoLog);
			std::cout << "ERROR::PROGRAM_LINKING_ERROR of type: " << "PROGRAM" << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
		}
	}

	void ShaderProgram::UpdataUniform(Dynamic::Dcb::LeafType type, GLint location, const Dynamic::Dcb::AvailableType& data) noxnd {
		switch (type) {
		case Dynamic::Dcb::LeafType::Float:
			glUniform1f(location, std::get<float>(data));
			return;
		case Dynamic::Dcb::LeafType::Float2:
			glUniform2fv(location, 1, &(std::get<glm::vec2>(data)[0]));
			return;
		case Dynamic::Dcb::LeafType::Float3:
			glUniform3fv(location, 1, &(std::get<glm::vec3>(data)[0]));
			return;
		case Dynamic::Dcb::LeafType::Float4:
			glUniform4fv(location, 1, &(std::get<glm::vec4>(data)[0]));
			return;
		case Dynamic::Dcb::LeafType::Double:
			glUniform1d(location, std::get<double>(data));
			return;
		case Dynamic::Dcb::LeafType::Double2:
			glUniform2dv(location, 1, &(std::get<glm::dvec2>(data)[0]));
			return;
		case Dynamic::Dcb::LeafType::Double3:
			glUniform3dv(location, 1, &(std::get<glm::dvec3>(data)[0]));
			return;
		case Dynamic::Dcb::LeafType::Double4:
			glUniform4dv(location, 1, &(std::get<glm::dvec4>(data)[0]));
			return;
		case Dynamic::Dcb::LeafType::Int:
			glUniform1i(location, std::get<int>(data));
			return;
		case Dynamic::Dcb::LeafType::Int2:
			glUniform2iv(location, 1, &(std::get<glm::ivec2>(data)[0]));
			return;
		case Dynamic::Dcb::LeafType::Int3:
			glUniform3iv(location, 1, &(std::get<glm::ivec3>(data)[0]));
			return;
		case Dynamic::Dcb::LeafType::Int4:
			glUniform4iv(location, 1, &(std::get<glm::ivec4>(data)[0]));
			return;
		case Dynamic::Dcb::LeafType::Uint:
			glUniform1ui(location, std::get<unsigned int>(data));
			return;
		case Dynamic::Dcb::LeafType::Uint2:
			glUniform2uiv(location, 1, &(std::get<glm::uvec2>(data)[0]));
			return;
		case Dynamic::Dcb::LeafType::Uint3:
			glUniform3uiv(location, 1, &(std::get<glm::uvec3>(data)[0]));
			return;
		case Dynamic::Dcb::LeafType::Uint4:
			glUniform4uiv(location, 1, &(std::get<glm::uvec4>(data)[0]));
			return;
		case Dynamic::Dcb::LeafType::Bool:
			glUniform1i(location, std::get<bool>(data));
			return;
		case Dynamic::Dcb::LeafType::Bool2:
			auto l_data = std::get<glm::bvec2>(data);
			glUniform2i(location, (int)l_data[0], (int)l_data[1]);
			return;
		case Dynamic::Dcb::LeafType::Bool3: {
			auto l_data = std::get<glm::bvec3>(data);
			glUniform3i(location, (int)l_data[0], (int)l_data[1], (int)l_data[2]);
			return;
		}
		case Dynamic::Dcb::LeafType::Bool4: {
			auto l_data = std::get<glm::bvec4>(data);
			glUniform4i(location, (int)l_data[0], (int)l_data[1], (int)l_data[2], (int)l_data[3]);
			return;
		}
		case Dynamic::Dcb::LeafType::FMat2:
			glUniformMatrix2fv(location, 1, GL_FALSE, &(std::get<glm::mat2>(data)[0][0]));
			return;
		case Dynamic::Dcb::LeafType::FMat3:
			glUniformMatrix3fv(location, 1, GL_FALSE, &(std::get<glm::mat3>(data)[0][0]));
			return;
		case Dynamic::Dcb::LeafType::FMat4:
			glUniformMatrix4fv(location, 1, GL_FALSE, &(std::get<glm::mat4>(data)[0][0]));
			return;
		case Dynamic::Dcb::LeafType::DMat2:
			glUniformMatrix2dv(location, 1, GL_FALSE, &(std::get<glm::dmat2>(data)[0][0]));
			return;
		case Dynamic::Dcb::LeafType::DMat3:
			glUniformMatrix3dv(location, 1, GL_FALSE, &(std::get<glm::dmat3>(data)[0][0]));
			return;
		case Dynamic::Dcb::LeafType::DMat4:
			glUniformMatrix4dv(location, 1, GL_FALSE, &(std::get<glm::dmat4>(data)[0][0]));
			return;
		default:
			assert("Type not supported for uniform updating!" && false);
			return;
		}
	}
}