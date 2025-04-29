#pragma once

#include <utils.h>
#include <geometry.h>
#include <shader.h>
#include <Bindables/inputlayout.h>
#include <Bindables/constantbuffer.h>

class TestConstant :public Utils {
public:
	TestConstant();
	~TestConstant() = default;

	void prepare() override;
	void render() override;
	void prepare_ui(const std::string& name) override;

	std::shared_ptr<Shader> rshader;
	std::shared_ptr<Bind::ConstantBuffer> m_constbuffer;
};