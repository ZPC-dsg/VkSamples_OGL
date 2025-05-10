#include <climits>
#include <Drawables/modelmesh.h>

#include <assimploader.h>
#include <SceneGraph/scene.h>
#include <tools.h>
#include <logging.h>

#define MAT_SELECTION_HELPER \
	X(SceneGraph::Material::TextureCategory::DIFFUSE, aiTextureType_DIFFUSE) \
	X(SceneGraph::Material::TextureCategory::SPECULAR, aiTextureType_SPECULAR) \
	X(SceneGraph::Material::TextureCategory::AMBIENT, aiTextureType_AMBIENT) \
	X(SceneGraph::Material::TextureCategory::EMISSIVE, aiTextureType_EMISSIVE) \
	X(SceneGraph::Material::TextureCategory::HEIGHT, aiTextureType_HEIGHT) \
	X(SceneGraph::Material::TextureCategory::NORMAL, aiTextureType_NORMALS) \
	X(SceneGraph::Material::TextureCategory::SHININESS, aiTextureType_SHININESS) \
	X(SceneGraph::Material::TextureCategory::OPACITY, aiTextureType_OPACITY) \
	X(SceneGraph::Material::TextureCategory::DISPLACEMENT, aiTextureType_DISPLACEMENT) \
	X(SceneGraph::Material::TextureCategory::LIGHTMAP, aiTextureType_LIGHTMAP) \
	X(SceneGraph::Material::TextureCategory::REFLECTION, aiTextureType_REFLECTION)

#define MAT_SERIALIZATION \
	X(SceneGraph::Material::TextureCategory::DIFFUSE, diffuse) \
	X(SceneGraph::Material::TextureCategory::SPECULAR, specular) \
	X(SceneGraph::Material::TextureCategory::AMBIENT, ambient) \
	X(SceneGraph::Material::TextureCategory::EMISSIVE, emissive) \
	X(SceneGraph::Material::TextureCategory::HEIGHT, height) \
	X(SceneGraph::Material::TextureCategory::NORMAL, normal) \
	X(SceneGraph::Material::TextureCategory::SHININESS, shininess) \
	X(SceneGraph::Material::TextureCategory::OPACITY, opacity) \
	X(SceneGraph::Material::TextureCategory::DISPLACEMENT, displacement) \
	X(SceneGraph::Material::TextureCategory::LIGHTMAP, lightmap) \
	X(SceneGraph::Material::TextureCategory::REFLECTION, reflection) 

void AssimpLoader::LoadModel(const std::string& file, SceneGraph::Scene& scene) {
	static Assimp::Importer imp;
	
	std::string path = Tools::get_solution_dir() + "assets/models/" + file;
	const auto pScene = imp.ReadFile(path.c_str(),
		aiProcess_Triangulate |
		aiProcess_JoinIdenticalVertices |
		aiProcess_ConvertToLeftHanded |
		aiProcess_GenNormals |
		aiProcess_GenUVCoords |
		aiProcess_CalcTangentSpace
	);

	if (!pScene || pScene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !pScene->mRootNode) {
		LOGE("Failed to load assimp model file {}.", path.c_str());
		return;
	}

	//每个模型都有一个根控制节点
	std::unique_ptr<SceneGraph::Node> root(new SceneGraph::ControlNode(0, std::string("Model ") + pScene->mName.C_Str() + "'s Entry Point"));
	scene.AddChild(*root);

	size_t ID = 1;
	LOGI("Start parsing model {}...", pScene->mName.C_Str());
	auto& model_root = parse_node(ID, *pScene->mRootNode, *pScene, scene);
	LOGI("Finish parsing model {}!", pScene->mName.C_Str());

	model_root.SetParent(*root);
	root->AddChild(model_root);

	scene.AddNode(std::move(root));
}

std::unique_ptr<SceneGraph::Material> AssimpLoader::parse_material(const aiMaterial& mat) {
	aiString mat_name;
	mat.Get(AI_MATKEY_NAME, mat_name);
	std::unique_ptr<SceneGraph::Material> target = std::make_unique<SceneGraph::Material>(mat_name.C_Str());

	LOGI("Start for texture loading for material {}...", mat_name.C_Str());
#define X(MatType, aiMatType) parse_material(mat, *target, MatType);
	MAT_SELECTION_HELPER
#undef X
	LOGI("Texture Loading for material {} finished!", mat_name.C_Str());

	LOGI("Start for extra properties extraction or material {}...", mat_name.C_Str());
	parse_material(mat, *target);
	LOGI("Extra properties extraction for material {} finished!", mat_name.C_Str());

	return target;
}

void AssimpLoader::parse_material(const aiMaterial& mat, SceneGraph::Material& target, SceneGraph::Material::TextureCategory type) {
	unsigned int tex_count = 0;

	aiTextureType tex_type;
	switch (type) {
#define X(MatType, aiMatType) case MatType: tex_type = aiMatType; break;

		MAT_SELECTION_HELPER
#undef X
	}

	std::string mat_string;
	switch (type) {
#define X(MatType, MatString) case MatType: mat_string = #MatString; break;

		MAT_SERIALIZATION
#undef X
	}

	switch(type){
#define X(MatType, aiMatType) \
	case MatType: \
		tex_count = mat.GetTextureCount(aiMatType); \
		break;
		
		MAT_SELECTION_HELPER
#undef X
	}

	aiString mat_name;
	mat.Get(AI_MATKEY_NAME, mat_name);
	if (tex_count == 0) {
		LOGW("No {} texture for material {}!", mat_string.c_str(), mat_name.C_Str());
	}
	else {
		LOGI("Totally {} {} textures for material {}.", std::to_string(tex_count).c_str(), mat_string.c_str(), mat_name.C_Str());
	}

	for (unsigned int i = 0; i < tex_count; i++) {
		LOGI("Start for No.{} {} texture loading...", std::to_string(i).c_str(), mat_string.c_str());
		SceneGraph::TextureInfo info;

		aiString pPath;
		if (mat.GetTexture(tex_type, i, &pPath) == aiReturn_SUCCESS) {
			info.m_path = std::string(pPath.C_Str());
			mat.Get(AI_MATKEY_TEXBLEND(tex_type, i), info.m_strength);

			mat.Get(AI_MATKEY_UVWSRC(tex_type, i), info.m_uv_channel);
			aiUVTransform transform;
			if (info.m_uv_channel >= 0 && (mat.Get(AI_MATKEY_UVTRANSFORM(tex_type, i), transform) == AI_SUCCESS)) {
				info.m_uvtransform_rotate = transform.mRotation;
				info.m_uvtransform_scale = glm::vec2(transform.mScaling.x, transform.mScaling.y);
				info.m_uvtransform_translate = glm::vec2(transform.mTranslation.x, transform.mTranslation.y);
			}

			aiTextureFlags flag;
			if (mat.Get(AI_MATKEY_TEXFLAGS(tex_type, i), flag) == AI_SUCCESS) {
				if (flag & aiTextureFlags_Invert) {
					info.m_textureflag |= SceneGraph::TextureInfo::m_flagmap.at(aiTextureFlags_Invert);
				}
				if (flag & aiTextureFlags_IgnoreAlpha) {
					info.m_textureflag |= SceneGraph::TextureInfo::m_flagmap.at(aiTextureFlags_IgnoreAlpha);
				}
				else if (flag & aiTextureFlags_UseAlpha) {
					info.m_textureflag |= SceneGraph::TextureInfo::m_flagmap.at(aiTextureFlags_UseAlpha);
				}
			}

			aiTextureOp op;
			if (mat.Get(AI_MATKEY_TEXOP(tex_type, i), op) == AI_SUCCESS) {
				info.m_textureop = SceneGraph::TextureInfo::m_opmap[op];
			}

			aiTextureMapMode mode;
			if (mat.Get(AI_MATKEY_MAPPINGMODE_U(tex_type, i), mode) == AI_SUCCESS) {
				info.m_wrapmode[0] = SceneGraph::TextureInfo::m_mapmodemap[mode];
			}
			if (mat.Get(AI_MATKEY_MAPPINGMODE_V(tex_type, i), mode) == AI_SUCCESS) {
				info.m_wrapmode[1] = SceneGraph::TextureInfo::m_mapmodemap[mode];
			}

			aiTextureMapping mapping;
			if (mat.Get(AI_MATKEY_MAPPING(tex_type, i), mapping) == AI_SUCCESS) {
				info.m_mapping = SceneGraph::TextureInfo::m_mappingmap[mapping];
			}

			LOGI("No.{} {} texture loading successful!Local texture path is {}.", std::to_string(i).c_str(), mat_string.c_str(), pPath.C_Str());

			target.AddTexture(type, info);
		}
		else {
			LOGE("Failed to load {} texture No.{}", mat_string.c_str(), std::to_string(i).c_str());
		}
	}
}

void AssimpLoader::parse_material(const aiMaterial& mat, SceneGraph::Material& target) {
	aiColor3D color;
	if(mat.Get(AI_MATKEY_COLOR_DIFFUSE, color) == AI_SUCCESS)
		target.SetDiffuse(color.r, color.g, color.b);
	if(mat.Get(AI_MATKEY_COLOR_SPECULAR, color) == AI_SUCCESS)
		target.SetSpecular(color.r, color.g, color.b);
	if(mat.Get(AI_MATKEY_COLOR_AMBIENT, color) == AI_SUCCESS)
		target.SetAmbient(color.r, color.g, color.b);
	if(mat.Get(AI_MATKEY_COLOR_EMISSIVE, color) ==AI_SUCCESS)
		target.SetEmissive(color.r, color.g, color.b);
	if(mat.Get(AI_MATKEY_COLOR_TRANSPARENT, color) ==AI_SUCCESS)
		target.SetTransparent(color.r, color.g, color.b);

	bool var = true;
	mat.Get(AI_MATKEY_TWOSIDED, var);
	target.SetTwoSided(var);
	
	float tar = 0.0;
	if(mat.Get(AI_MATKEY_OPACITY, tar) == AI_SUCCESS)
		target.SetOpacity(tar);
	if(mat.Get(AI_MATKEY_SHININESS, tar) ==AI_SUCCESS)
		target.SetShininess(tar);
	if (mat.Get(AI_MATKEY_SHININESS_STRENGTH, tar) == AI_SUCCESS)
		target.SetShiniStength(tar);

	aiBlendMode mode;
	if (mat.Get(AI_MATKEY_BLEND_FUNC, mode) == AI_SUCCESS)
		target.SetBlendMode(SceneGraph::ExtraProperties::m_blendmodemap[mode]);
	aiShadingMode shading;
	if (mat.Get(AI_MATKEY_SHADING_MODEL, shading) == AI_SUCCESS)
		target.SetShadingMode(SceneGraph::ExtraProperties::m_shadingmap[shading]);
}

SceneGraph::Node& AssimpLoader::parse_node(size_t& ID, const aiNode& node, const aiScene& model, SceneGraph::Scene& scene) {
	std::string node_name = node.mName.C_Str();
	LOGI("Parsing node {}...", node_name.c_str());

	auto transform = node.mTransformation;
	aiVector3D translation, scaling;
	aiQuaternion rotate;
	transform.Decompose(scaling, rotate, translation);

	std::unique_ptr<SceneGraph::EntityNode> new_node(new SceneGraph::EntityNode(ID++, node_name));
	new_node->SetScaling(glm::vec3(scaling.x, scaling.y, scaling.z));
	new_node->SetRotation(glm::vec4(rotate.x, rotate.y, rotate.z, rotate.w));
	new_node->SetTranslation(glm::vec3(translation.x, translation.y, translation.z));

	int mesh_num = node.mNumMeshes;
	for (int i = 0; i < mesh_num; i++) {
		aiMesh* mesh = model.mMeshes[node.mMeshes[i]];
		aiMaterial* material = model.mMaterials[mesh->mMaterialIndex];
		std::unique_ptr<DrawItems::Drawable> item(new DrawItems::ModelMesh(*mesh));
		std::unique_ptr<SceneGraph::Material> mat = parse_material(*material);

		new_node->AddDrawable(*item);
		new_node->AddMaterial(*mat);

		scene.AddDrawable(typeid(DrawItems::ModelMesh), std::move(item));
		scene.AddMaterial(std::move(mat));
	}

	int child_num = node.mNumChildren;
	for (int i = 0; i < child_num; i++) {
		SceneGraph::Node& child = parse_node(ID, *(node.mChildren[i]), model, scene);
		child.SetParent(*new_node);
		new_node->AddChild(child);
	}

	scene.AddNode(std::move(new_node));
	LOGI("Finished parsing node {}!", node_name.c_str());
	return *scene.GetNodes().back();
}

glm::mat4 AssimpLoader::AimatToGLM(const aiMatrix4x4& aiMat) {
	return glm::transpose(glm::mat4(
		aiMat.a1, aiMat.a2, aiMat.a3, aiMat.a4,
		aiMat.b1, aiMat.b2, aiMat.b3, aiMat.b4,
		aiMat.c1, aiMat.c2, aiMat.c3, aiMat.c4,
		aiMat.d1, aiMat.d2, aiMat.d3, aiMat.d4
	));
}