#pragma once

#include <init.h>
#include <texturebuilder.h>
#include <nocopyable.h>

#include <stdexcept>

class Utils : private NoCopyable
{
public:
	void processInput(GLFWwindow* window);

	Utils();
	virtual ~Utils();

	void renderCube();
	void renderQuad();

	virtual void render() = 0;
	virtual void prepare() = 0;

	void start();
	void terminate();

private:
	unsigned int cubeVAO = 0;
	unsigned int cubeVBO = 0;
	unsigned int quadVAO = 0;
	unsigned int quadVBO = 0;

	void genCube();
	void genQuad();
};