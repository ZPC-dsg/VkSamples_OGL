#pragma once

#include <utils.h>

class ModelTest :public Utils {
public:
	ModelTest(const std::string& scene_name);
	~ModelTest() = default;

	void prepare() override;
	void prepare_ui(const std::string& name) override;
	void render() override;

private:

};