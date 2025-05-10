#include <SceneGraph/node.h>
#include <Bindables/bindable.h>

namespace SceneGraph {
	//Node
	Node::Node(const size_t id, const std::string& name)
		:m_id(id), m_name(name)
	{
	}

	//不设置父亲节点的子节点
	void Node::SetParent(Node& node) {
		m_parent = &node;
	}

	//不设置子节点的父亲节点
	void Node::AddChild(Node& child) {
		m_children.push_back(&child);
	}

	void Node::SetBindable(std::shared_ptr<Bind::Bindable> bindable) {
		auto it = m_bindables.find(bindable->GetTypeInfo());
		if (it != m_bindables.end()) {
			it->second = bindable;
		}
		else {
			m_bindables.insert(std::make_pair(bindable->GetTypeInfo(), bindable));
		}
	}

	std::shared_ptr<Bind::Bindable> Node::GetBindable(const std::type_index& type_info) {
		return m_bindables.at(type_info);
	}

	bool Node::HasComponent(const std::type_index& type_info) const {
		return m_bindables.count(type_info);
	}

	//EntityNode
	EntityNode::EntityNode(const size_t id, const std::string& name)
		:Node(id, name)
	{
	}

	void EntityNode::SetParent(Node& node) {
		m_parent = &node;
		m_transform.SetDirtyFlag(true);
	}

	const glm::mat4& EntityNode::CalculateWorldMatrix() const noexcept {
		return m_transform.GetWorldMatrix();
	}

	void EntityNode::UpdateWorldMatrix() {
		if (m_transform.IsDirty()) {
			m_transform.SetDirtyFlag(false);
			m_world_matrix = m_parent ? m_parent->GetWorldMatrix() * CalculateWorldMatrix() : CalculateWorldMatrix();

			for (auto child : m_children) {
				child->ForceUpdateWorldMatrix();
			}
		}
		else {
			for (auto child : m_children) {
				child->UpdateWorldMatrix();
			}
		}
	}

	void EntityNode::ForceUpdateWorldMatrix() {
		m_transform.SetDirtyFlag(false);
		m_world_matrix = m_parent->GetWorldMatrix() * CalculateWorldMatrix();

		for (auto child : m_children) {
			child->ForceUpdateWorldMatrix();
		}
	}

	void EntityNode::SetTranslation(const glm::vec3& translate) noexcept {
		m_transform.SetTranslation(translate);
	}

	void EntityNode::SetRotation(const glm::vec3& axis, float angle) noexcept {
		m_transform.SetRotation(axis, angle);
	}

	void EntityNode::SetRotation(const glm::vec4& quat) noexcept {
		m_transform.SetRotation(quat);
	}

	void EntityNode::SetScaling(const glm::vec3& scale) noexcept {
		m_transform.SetScale(scale);
	}

	//ControlNode
	ControlNode::ControlNode(const size_t id, const std::string& name)
		:Node(id, name)
	{
	}

	void ControlNode::AddTextureConfig(const std::string& name, GLuint binding, Material::TextureCategory type) {
		m_texture_vector.push_back(std::make_tuple(name, binding, type));
	}
}