#pragma once

#include <utils.h>
#include <geometry.h>
#include <shader.h>
#include <Bindables/inputlayout.h>
#include <Bindables/imagetexture2D.h>
#include <Bindables//rendertarget.h>

class BindableTest :public Utils {
public:
	BindableTest();
	~BindableTest() = default;

	void prepare() override;
	void render() override;
	void prepare_ui(const std::string& name) override;

	std::shared_ptr<Shader> m_shader;
	std::shared_ptr<Shader> m_quadShader;
	std::unique_ptr<Box> m_box;
	std::shared_ptr<Bind::InputLayout> m_layout;
	std::shared_ptr<Dynamic::Dvtx::CPUVertexBuffer> m_cpubuffer;
	std::unique_ptr<Bind::ImageTexture2D> m_texture;
	std::unique_ptr<Bind::RenderTarget> m_framebuffer;
	std::shared_ptr<Bind::ImageTexture2D> m_rendertarget;
};