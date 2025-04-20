#include "sceneTest.h"

/*
Test::Test() {
	globalSettings::mainCamera.set_perspective(60.0f, globalSettings::screen_width, globalSettings::screen_height, 512.0f, 0.1f);
	globalSettings::mainCamera.set_position(glm::vec3(0.0f, 0.0f, 4.0f));
}

Test::~Test() {

}

void Test::render() {
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	box_MVP = globalSettings::mainCamera.get_perspective() * globalSettings::mainCamera.get_view() * box->get_model();
	testShader->setMat4("MVP", box_MVP);
	box->Draw();
	
	sphere_MVP = globalSettings::mainCamera.get_perspective() * globalSettings::mainCamera.get_view() * sphere->get_model();
	testShader->setMat4("MVP", sphere_MVP);
	sphere->Draw();
	//model = glm::translate(model, glm::vec3(3.0));
	//MVP = globalSettings::mainCamera.get_perspective() * globalSettings::mainCamera.get_view() * model;
	//testShader->setMat4("MVP", MVP);
	//plane->Draw();
}

void Test::prepare() {
	glEnable(GL_DEPTH_TEST);
	testShader = std::unique_ptr<Shader>(new Shader("test", "test.vert", "test.frag"));
	testShader->use();
	//backpack = Model("backpack", "backpack.obj");
	box = std::unique_ptr<GeometryBase>(new Box());
	box->set_model(glm::scale(glm::mat4(1.0f), glm::vec3(0.5f)));
	//sphere = std::make_unique<Sphere>();
	//plane = std::make_unique<Plane>();
	sphere = std::unique_ptr<GeometryBase>(new Sphere());
	sphere->set_model(glm::translate(glm::mat4(1.0f), glm::vec3(1.0f)));
}

void Test::prepare_ui(const std::string& name) {

}
*/