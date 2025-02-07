#pragma once

#include <camera.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>

#define GL_CALL(x) do{globalSettings::debugInfo.file = __FILE__; globalSettings::debugInfo.line = __LINE__; x;} while(0)

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);

void APIENTRY glDebugOutput(GLenum source,
	GLenum type,
	unsigned int id,
	GLenum severity,
	GLsizei length,
	const char* message,
	const void* userParam);

namespace globalSettings {
	extern unsigned int screen_width;
	extern unsigned int screen_height;
	extern float deltaTime;
	extern float lastFrame;
	extern Camera mainCamera;
	extern GLFWwindow* mainWindow;
	extern GLfloat max_anisotropy;

	extern struct DebugInfo
	{
		const char* file;
		int line;
	} debugInfo;
};

void init();

void fin();
