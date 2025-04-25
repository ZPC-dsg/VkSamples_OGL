#pragma once

#include <Bindables/includer.h>

namespace Bind {
	class ShaderProgram {
	public:
		ShaderProgram(GLuint ID);
		inline GLuint get_program() const noexcept { return m_program; }

	private:
		GLuint m_program;
	};
}