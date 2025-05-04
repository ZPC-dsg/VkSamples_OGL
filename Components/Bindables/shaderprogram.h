#pragma once

#include <Bindables/includer.h>
#include <Dynamic/dynamic_constant.h>
#include <Bindables/shaderobject.h>

namespace Bind {
	class ShaderProgram :public Bindable {
	public:
		ShaderProgram(const std::string& tag, std::vector<GLuint> shaders);
		ShaderProgram(GLuint ID);
		~ShaderProgram();

		void Bind() noxnd override;
		static std::shared_ptr<ShaderProgram> Resolve(const std::string& tag, std::vector<GLuint> shaders);
		static std::string GenerateUID(const std::string& tag, std::vector<GLuint> shaders);
		std::string GetUID() const noexcept override;

		inline GLuint get_program() const noexcept { return m_program; }

		Dynamic::Dcb::CPUUniformBlock& operator[](const std::string& key) noxnd;
		Dynamic::Dcb::CPUUniformBlock& EditUniform(const std::string& key) noxnd;

	private:
		static void CheckCompileErrors(GLuint program);

		static void UpdataUniform(Dynamic::Dcb::LeafType type, GLint location, const Dynamic::Dcb::AvailableType& data) noxnd;

	private:
		std::string m_tag;
		GLuint m_program;
		std::unordered_map<std::string, Dynamic::Dcb::CPUUniformBlock> m_uniforms;
	};
}