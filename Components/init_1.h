#pragma once

#include <camera.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);

namespace globalSettings {
	extern unsigned int screen_width;
	extern unsigned int screen_height;
	extern float deltaTime;
	extern float lastFrame;
	extern Camera mainCamera;
};

class Initializer
{
	Initializer();

public:
	Initializer(const Initializer& rhs) = delete;
	Initializer(Initializer&& rhs) = delete;
	Initializer& operator=(const Initializer& rhs) = delete;
	Initializer& operator=(Initializer&& rhs) = delete;

	static GLFWwindow* init();
	GLFWwindow* get();

	~Initializer();
	
private:
	GLFWwindow* window;
};