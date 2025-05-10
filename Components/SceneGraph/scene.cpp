#include <SceneGraph/scene.h>
#include <Bindables/bindable.h>
#include <SceneGraph/material.h>

#include <cassert>
#include <queue>
#include <climits>

namespace SceneGraph {
	Scene::Scene(const std::string& name)
		:m_name(name)
	{
		SetupRootNode();
	}

	void Scene::AddMaterial(std::unique_ptr<Material>&& mat) {
		m_materials.push_back(std::move(mat));
	}

	void Scene::AddDrawable(const std::type_index& type, std::unique_ptr<DrawItems::Drawable>&& item) {
		m_drawables[type].push_back(std::move(item));
	}

	void Scene::SetNodes(std::vector<std::unique_ptr<Node>>&& nodes) {
		assert(m_nodes.empty() && "Nodes have already been set!");
		m_nodes = std::move(nodes);
	}

	void Scene::AddNode(std::unique_ptr<Node>&& node) {
		m_nodes.emplace_back(std::move(node));
	}

	void Scene::AddChild(Node& child) {
		m_root->AddChild(child);
	}

	void Scene::AddBindable(std::shared_ptr<Bind::Bindable> bindable, Node& node) {
		node.SetBindable(bindable);
		if (bindable) {
			m_bindables[bindable->GetTypeInfo()].push_back(bindable);
		}
	}

	void Scene::AddBindable(std::shared_ptr<Bind::Bindable> bindable) {
		if (bindable) {
			m_bindables[bindable->GetTypeInfo()].push_back(bindable);
		}
	}

	void Scene::SetBindables(const std::type_index& type_info, std::vector<std::shared_ptr<Bind::Bindable>> bindables) {
		m_bindables[type_info] = bindables;
	}

	const std::vector<std::shared_ptr<Bind::Bindable>>& Scene::GetBindables(const std::type_index& type_info) const {
		return m_bindables.at(type_info);
	}

	bool Scene::HasBindable(const std::type_index& type_info) const noexcept {
		return m_bindables.count(type_info) && m_bindables.at(type_info).size();
	}

	Node* Scene::FindNode(const std::string& name) {
		for (auto node : m_root->GetChildren()) {
			std::queue<Node*> q{};
			q.push(node);

			while (!q.empty()) {
				auto n = q.front();
				q.pop();

				if (n->GetName() == name) {
					return n;
				}

				for (auto child : n->GetChildren()) {
					q.push(child);
				}
			}
		}

		return nullptr;
	}

	void Scene::SetupRootNode() {
		m_nodes.push_back(std::make_unique<ControlNode>(UINT_MAX, m_name));//根节点编号用最大数代表
		m_root = static_cast<ControlNode*>(m_nodes.back().get());
	}
}