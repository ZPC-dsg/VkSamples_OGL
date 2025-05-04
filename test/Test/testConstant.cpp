#include "testConstant.h"

TestConstant::TestConstant() {
	globalSettings::mainCamera.set_perspective(60.0f, globalSettings::screen_width, globalSettings::screen_height, 512.0f, 0.1f);
	globalSettings::mainCamera.set_position(glm::vec3(0.0f, 0.0f, 4.0f));
}

void TestConstant::prepare() {
	glEnable(GL_DEPTH_TEST);

	//rshader = std::make_shared<Shader>("test", "test.vert", "test.frag");

	//reflection = std::make_shared<Dynamic::Dsr::ShaderReflection>(rshader);
	//auto runiformblock = reflection->GetConstantAttribs()["TestBlock"];
	/*
	for (int i = 0; i < runiformblock.size(); i++) {
		std::cout << runiformblock[i];
	}
	*/
	//entry = std::make_shared<Dynamic::Dsr::ConstantEntryPoint>("TestBlock", runiformblock);

	/*
	m_constbuffer = std::make_shared<Bind::ConstantBuffer>("constant", std::make_shared<Bind::ShaderProgram>(rshader->ID), "MVP_Uniform", 0);
	(*m_constbuffer)["MVP"] = globalSettings::mainCamera.get_perspective() * globalSettings::mainCamera.get_view();
	m_constbuffer->Bind();
	m_constbuffer->Update();

	rshader->use();
	*/

	/*
	auto reflection = Dynamic::Dsr::ShaderReflection::GetUniformAttribs(rshader->ID);
	for (auto& p : reflection) {
		std::cout << p.first << std::endl;
		for (auto& v : p.second) {
			std::cout << v;
		}
	}
	*/

	GLuint vertex = Bind::ShaderObject::Resolve(Bind::ShaderObject::ShaderType::Vertex, "vertex", "test", "test.vert");
	GLuint fragment = Bind::ShaderObject::Resolve(Bind::ShaderObject::ShaderType::Fragment, "fragment", "test", "test.frag");
	m_shader = std::make_shared<Bind::ShaderProgram>("shader", std::vector<GLuint>{vertex, fragment});
	m_shader->EditUniform("block")[std::string("colors")] = glm::vec3(1.0);
	m_shader->EditUniform("block")[std::string("intensity")][0] = 0.1f;
	m_shader->EditUniform("block")[std::string("intensity")][1] = 0.5f;
	m_shader->EditUniform("block")[std::string("intensity")][2] = 0.9f;
	m_shader->EditUniform("time") = 0.1f;
	m_shader->Bind();
	m_constbuffer = std::make_shared<Bind::ConstantBuffer>("constant", m_shader, "MVP_Uniform", 0);
	m_constbuffer->EditConstant("MVP") = globalSettings::mainCamera.get_perspective() * globalSettings::mainCamera.get_view();
	m_constbuffer->Bind();
	m_constbuffer->Update();
}

void TestConstant::render() {
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	m_constbuffer->EditConstant("MVP") = globalSettings::mainCamera.get_perspective() * globalSettings::mainCamera.get_view();
	m_constbuffer->Update();

	m_shader->EditUniform("time") = (float)globalSettings::lastFrame - (float)((int)globalSettings::lastFrame);
	m_shader->Bind();

	renderCube();
}

void TestConstant::prepare_ui(const std::string& name) {

}