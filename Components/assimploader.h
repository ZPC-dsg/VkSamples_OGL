#pragma once

#include <SceneGraph/material.h>

#include <memory>
#include <string>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

namespace SceneGraph {
	class ControlNode;
	class Node;
	class Scene;
	class Material;
}

class AssimpLoader {
public:
	AssimpLoader() = default;
	~AssimpLoader() = default;

	static void LoadModel(const std::string& file, SceneGraph::Scene& scene);

private:
	static std::unique_ptr<SceneGraph::Material> parse_material(const aiMaterial& mat);
	static void parse_material(const aiMaterial& mat, SceneGraph::Material& target, SceneGraph::Material::TextureCategory type);
	static void parse_material(const aiMaterial& mat, SceneGraph::Material& target);

	static SceneGraph::Node& parse_node(size_t& ID, const aiNode& node, const aiScene& model, SceneGraph::Scene& scene);

	static glm::mat4 AimatToGLM(const aiMatrix4x4& aiMat);
};