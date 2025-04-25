#include "bindableTest.h"

BindableTest::BindableTest() {
	globalSettings::mainCamera.set_perspective(60.0f, globalSettings::screen_width, globalSettings::screen_height, 512.0f, 0.1f);
	globalSettings::mainCamera.set_position(glm::vec3(0.0f, 0.0f, 4.0f));
}

void BindableTest::prepare() {
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);

	m_texture = std::make_unique<Bind::ImageTexture2D>("image", "girl.jpg", OGL_TEXTURE_PARAMETER(), 0, true);
	m_texture->Bind();

	OGL_TEXTURE2D_DESC desc = m_texture->get_description();
	m_framebuffer = std::make_unique<Bind::RenderTarget>("framebuffer", desc.width, desc.height);
	m_framebuffer->AppendTexture<GL_TEXTURE_2D>("rendertarget").AppendDepthComponent<GL_RENDERBUFFER>("depth").CheckCompleteness();
	m_rendertarget = m_framebuffer->get_texture_image<Bind::ImageTexture2D>("rendertarget", OGL_TEXTURE_PARAMETER{}, 1);

	m_box = std::make_unique<Box>();
	m_box->set_model(glm::mat4(1.0));
	const GeometryData& data = m_box->get_data();
	m_shader = std::shared_ptr<Shader>(new Shader("test", "test.vert", "test.frag"));
	Dynamic::Dsr::ShaderReflection reflection(m_shader);
	std::vector<Dynamic::Dsr::VertexAttrib> attribs = reflection.GetVertexAttribs();
	m_cpubuffer = std::make_shared<Dynamic::Dvtx::CPUVertexBuffer>(attribs, data.vertices.size(), Dynamic::Dvtx::VertexLayout::InputClassification::PerVertex, Dynamic::Dvtx::VertexLayout::InputSteppingType::Continuous);
	m_cpubuffer->InitializeData(0, data.vertices, data.texcoords);
	std::shared_ptr<Bind::VertexBuffer> vertex_buffer = std::make_shared<Bind::VertexBuffer>("vertex", *m_cpubuffer);
	std::shared_ptr<Bind::IndexBuffer> index_buffer = std::make_shared<Bind::IndexBuffer>("index", data.indices32);
	m_layout = std::make_shared<Bind::InputLayout>("input", std::vector<std::shared_ptr<Bind::VertexBuffer>>{ vertex_buffer }, index_buffer);

	m_shader->use();
	m_shader->setInt("girl", 0);

	m_quadShader = std::make_shared<Shader>("test", "quad.vert", "quad.frag");
	m_quadShader->use();
	m_quadShader->setInt("quad_image", 1);
}

void BindableTest::render() {
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glViewport(0, 0, m_framebuffer->get_width(), m_framebuffer->get_height());
	m_framebuffer->Bind();
	m_shader->use();
	m_shader->setMat4("MVP", globalSettings::mainCamera.get_perspective() * globalSettings::mainCamera.get_view() * m_box->get_model());
	m_layout->Bind();
	glDrawElements(GL_TRIANGLES, m_box->get_data().indices32.size(), GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);

	glViewport(0, 0, globalSettings::screen_width, globalSettings::screen_height);
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
	m_rendertarget->Bind();
	renderQuad();
}

void BindableTest::prepare_ui(const std::string& name) {

}