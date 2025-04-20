#pragma once

#include <utils.h>
#include <shader.h>
#include <models.h>
#include <geometry.h>

/*
class Test : public Utils {
public:
	Test();
	~Test();

	void render() override;
	void prepare() override;
	void prepare_ui(const std::string& name) override;

	glm::mat4 box_model = glm::mat4(1.0f);
	glm::mat4 sphere_model = glm::mat4(1.0f);

	std::unique_ptr<Shader> testShader;

	Model backpack;

	std::unique_ptr<GeometryBase> box;
	std::unique_ptr<GeometryBase> sphere;
	std::unique_ptr<GeometryBase> plane;

	glm::mat4 box_MVP;
	glm::mat4 sphere_MVP;
};
*/