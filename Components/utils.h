#pragma once

#include <init.h>
#include <texturebuilder.h>
#include <nocopyable.h>
#include <cpuTimer.h>
#include <gpuTimer.h>
#include <SceneGraph/scene.h>

#include <stdexcept>

class Utils : private NoCopyable
{
public:
	Utils();
	Utils(const std::string& name);
	virtual ~Utils();

	void renderCube();
	void renderQuad();

	virtual void render() = 0;
	virtual void prepare() = 0;
	virtual void prepare_ui(const std::string& name) = 0;

	void start();
	void terminate();

	void ui_newFrame();
	void draw_ui();

	void AppendSceneNode(std::unique_ptr<SceneGraph::Node>&& node);//TODO

protected:
	unsigned int cubeVAO = 0;
	unsigned int cubeVBO = 0;
	unsigned int quadVAO = 0;
	unsigned int quadVBO = 0;

	Timer m_cpuTimer;
	GpuTimer m_gpuTimer;

	void genCube();
	void genQuad();

	void processInput();

	SceneGraph::Scene m_main_scene;
};