#include "dvtxTest.h"

DvtxTest::DvtxTest() {
	globalSettings::mainCamera.set_perspective(60.0f, globalSettings::screen_width, globalSettings::screen_height, 512.0f, 0.1f);
	globalSettings::mainCamera.set_position(glm::vec3(0.0f, 0.0f, 4.0f));
}

DvtxTest::~DvtxTest() {

}

void DvtxTest::render() {
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	m_shader->setMat4("MVP", globalSettings::mainCamera.get_perspective() * globalSettings::mainCamera.get_view() * m_box->get_model());
	m_layout->Bind();
	glDrawElements(GL_TRIANGLES, m_box->get_data().indices32.size(), GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}

void DvtxTest::prepare() {
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	m_box = std::make_unique<Box>();
	m_box->set_model(glm::mat4(1.0));
	const GeometryData& data = m_box->get_data();
	m_shader = std::shared_ptr<Shader>(new Shader("test", "test.vert", "test.frag"));
	std::vector<Dynamic::Dsr::VertexAttrib> attribs = Dynamic::Dsr::ShaderReflection::GetVertexAttribs(m_shader->ID);
	m_cpubuffer = std::make_shared<Dynamic::Dvtx::CPUVertexBuffer>(attribs, data.vertices.size(), Dynamic::Dvtx::VertexLayout::InputClassification::PerVertex, Dynamic::Dvtx::VertexLayout::InputSteppingType::Continuous);
	m_cpubuffer->InitializeData(0, data.vertices, data.texcoords);
	std::shared_ptr<Bind::VertexBuffer> vertex_buffer = std::make_shared<Bind::VertexBuffer>("vertex", *m_cpubuffer);
	std::shared_ptr<Bind::IndexBuffer> index_buffer = std::make_shared<Bind::IndexBuffer>("index", data.indices32);
	m_layout = std::make_shared<Bind::InputLayout>("input", std::vector<std::shared_ptr<Bind::VertexBuffer>>{ vertex_buffer }, index_buffer);
	m_shader->use();
}

void DvtxTest::prepare_ui(const std::string& name) {

}