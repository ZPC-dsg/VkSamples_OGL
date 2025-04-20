#pragma once

#include <utils.h>
#include <geometry.h>
#include <shader.h>
#include <Bindables/inputlayout.h>

class DvtxTest :public Utils {
public:
	DvtxTest();
	~DvtxTest();

	void render() override;
	void prepare() override; 
	void prepare_ui(const std::string& name) override;

	std::shared_ptr<Shader> m_shader;
	std::unique_ptr<Box> m_box;
	std::shared_ptr<Bind::InputLayout> m_layout;
	std::shared_ptr<Dynamic::Dvtx::CPUVertexBuffer> m_cpubuffer;
};