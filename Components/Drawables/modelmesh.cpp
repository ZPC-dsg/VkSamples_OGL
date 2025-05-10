#include <Drawables/modelmesh.h>

namespace DrawItems {
	ModelMesh::ModelMesh(const aiMesh& mesh) {
		SetName(mesh.mName.C_Str());

		parse_mesh(mesh);
	}

	void ModelMesh::parse_mesh(const aiMesh& mesh) {
		int vert_count = mesh.mNumVertices;

		m_positions.resize(vert_count);
		for (int i = 0; i < vert_count; i++) {
			m_positions[i] = glm::vec3(mesh.mVertices[i].x, mesh.mVertices[i].y, mesh.mVertices[i].z);
		}

		if (mesh.HasNormals()) {
			m_normals.resize(vert_count);
			for (int i = 0; i < vert_count; i++) {
				m_normals[i] = glm::vec3(mesh.mNormals[i].x, mesh.mNormals[i].y, mesh.mNormals[i].z);
			}
		}

		if (mesh.HasTangentsAndBitangents()) {
			for (int i = 0; i < vert_count; i++) {
				m_tangents.resize(vert_count);
				m_bitangents.resize(vert_count);
				m_tangents[i] = glm::vec3(mesh.mTangents[i].x, mesh.mTangents[i].y, mesh.mTangents[i].z);
				m_bitangents[i] = glm::vec3(mesh.mBitangents[i].x, mesh.mBitangents[i].y, mesh.mBitangents[i].z);
			}
		}

		int index = -1;
		while (mesh.HasTextureCoords(++index));
		m_texcoords = std::vector<std::vector<glm::vec2>>(index, std::vector<glm::vec2>(vert_count));
		for (int i = 0; i < vert_count; i++) {
			for (int j = 0; j < index; j++) {
				m_texcoords[j][i] = glm::vec2(mesh.mTextureCoords[j][i].x, mesh.mTextureCoords[j][i].y);
			}
		}

		index = -1;
		while (mesh.HasVertexColors(index++));
		m_vertexcolors = std::vector<std::vector<glm::vec4>>(index, std::vector<glm::vec4>(vert_count));
		for (int i = 0; i < vert_count; i++) {
			for (int j = 0; j < index; j++) {
				m_vertexcolors[j][i] = glm::vec4(mesh.mColors[j][i].r, mesh.mColors[j][i].g, mesh.mColors[j][i].b, mesh.mColors[j][i].a);
			}
		}

		if (mesh.HasFaces()) {
			for (int i = 0; i < mesh.mNumFaces; i++) {
				const aiFace& face = mesh.mFaces[i];
				for (int j = 0; j < face.mNumIndices; j++) {
					m_indices.push_back(face.mIndices[j]);
				}
			}
		}
	}
}