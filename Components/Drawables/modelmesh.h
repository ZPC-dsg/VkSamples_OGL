#pragma once

#include <Drawables/drawable.h>
#include <assimp/scene.h>

//TODO mesh��AABB��aimesh��Ҳ�а�����֮��ʵ��frustum culling��ʱ������������Ϣ

namespace DrawItems {
	class ModelMesh :public Drawable {
	public:
		ModelMesh(const aiMesh& mesh);
		~ModelMesh() = default;

	private:
		void parse_mesh(const aiMesh& mesh);

	private:
		std::vector<glm::vec3> m_positions;
		std::vector<glm::vec3> m_normals;
		std::vector<glm::vec3> m_tangents;
		std::vector<glm::vec3> m_bitangents;
		std::vector<std::vector<glm::vec2>> m_texcoords;
		std::vector<std::vector<glm::vec4>> m_vertexcolors;

		std::vector<uint32_t> m_indices;
	};
}