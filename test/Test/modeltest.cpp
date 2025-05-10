#include "modeltest.h"

#include <assimploader.h>

ModelTest::ModelTest(const std::string& scene_name)
	:Utils(scene_name)
{
}

void ModelTest::prepare() {
	AssimpLoader::LoadModel("backpack/backpack.obj", m_main_scene);
}

void ModelTest::prepare_ui(const std::string& name) {

}

void ModelTest::render() {

}