#define SHADER_OBJECT_SOURCE_FILE

#include <Bindables/shaderobject.h>
#include <tools.h>

#include <fstream>
#include <sstream>
#include <iostream>
#include <cassert>

namespace Bind {
    std::unordered_map<std::string, std::shared_ptr<ShaderObject>> ShaderObject::m_vertexshaders;
    std::unordered_map<std::string, std::shared_ptr<ShaderObject>> ShaderObject::m_fragmentshaders;
    std::unordered_map<std::string, std::shared_ptr<ShaderObject>> ShaderObject::m_geometryshaders;
    std::unordered_map<std::string, std::shared_ptr<ShaderObject>> ShaderObject::m_computeshaders;
    std::unordered_map<std::string, std::shared_ptr<ShaderObject>> ShaderObject::m_tesscontrolshaders;
    std::unordered_map<std::string, std::shared_ptr<ShaderObject>> ShaderObject::m_tessevaluationshaders;

#define SWITCH_TYPE \
	X(ShaderObject::ShaderType::Vertex,m_vertexshaders) \
	X(ShaderObject::ShaderType::Fragment,m_fragmentshaders) \
	X(ShaderObject::ShaderType::Geometry,m_geometryshaders) \
	X(ShaderObject::ShaderType::Compute,m_computeshaders) \
	X(ShaderObject::ShaderType::TessControl,m_tesscontrolshaders) \
	X(ShaderObject::ShaderType::TessEvaluation,m_tessevaluationshaders)

	ShaderObject::ShaderObject(ShaderType type, const std::string& tag, const std::string& proj, const std::string& file) 
        :m_tag(tag), m_type(type)
    {
        std::string code;
        std::string fragmentCode;
        std::string geometryCode;
        std::ifstream file_stream;

        file_stream.exceptions(std::ifstream::failbit | std::ifstream::badbit);
        try
        {
            std::string abs_dir = Tools::get_solution_dir() + "Shaders/";
            std::string path = abs_dir + proj + std::string("/") + file;
            file_stream.open(path);
            std::stringstream stream;

            stream << file_stream.rdbuf();
            file_stream.close();

            code = stream.str();
        }
        catch (std::ifstream::failure& e)
        {
            std::cout << "ERROR::SHADER::FILE_NOT_SUCCESSFULLY_READ: " << e.what() << std::endl;
        }

        const char* c_code = code.c_str();

        switch (type) {
#define X(GLType,Type) case Type: m_shader = glCreateShader(GLType); break;
            TYPE_GENERATOR
#undef X
        default:
            assert("Type is not supported!" && false);
        }

        glShaderSource(m_shader, 1, &c_code, NULL);
        glCompileShader(m_shader);
        
        switch (type) {
#define X(GLType,Type) case Type: checkCompileErrors(m_shader, #Type); break;
            TYPE_GENERATOR
#undef X
        }

        glObjectLabel(GL_SHADER, m_shader, -1, tag.c_str());
	}

    GLuint ShaderObject::Resolve(ShaderObject::ShaderType type, const std::string& tag, const std::string& proj, const std::string& file) {
        switch (type) {
#define X(Type,Member) \
	case Type: \
        if(!Member.contains(tag)) \
		    Member[tag] = std::make_shared<ShaderObject>(type, tag, proj, file); \
        else \
            assert("Name has been occupied!" && false); \
        return *Member[tag];

            SWITCH_TYPE

#undef X
        default:
            assert("Type is not supported!" && false);
            return 0;
        }
    }

    GLuint ShaderObject::Resolve(ShaderObject::ShaderType type, const std::string& tag) {
        switch (type) {
#define X(Type, Member) \
	case Type: \
		assert("Name doesn't correspond to an existing shader object!" && Member.contains(tag)); \
		return *Member[tag];

            SWITCH_TYPE

#undef X
        default:
            assert("Type is not supported!" && false);
            return 0;
        }
    }

    ShaderObject::~ShaderObject() {
        if (glIsShader(m_shader)) {
            glDeleteShader(m_shader);
            switch (m_type) {
#define X(Type,Member) case Type: Member.erase(m_tag); break;
                SWITCH_TYPE
#undef X
            default:
                assert("Type not supported!" && false);
            }
        }
    }

    ShaderObject::operator const GLuint& () const noexcept {
        return m_shader;
    }

    void ShaderObject::checkCompileErrors(GLuint shader, std::string type)
    {
        GLint success;
        GLchar infoLog[1024];
        glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(shader, 1024, NULL, infoLog);
            std::cout << "ERROR::SHADER_COMPILATION_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
        }
    }

#undef SWITCH_TYPE
}