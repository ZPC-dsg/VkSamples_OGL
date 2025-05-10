#pragma once

#include <SceneGraph/node.h>
#include <Drawables/drawable.h>

#include <memory>
#include <vector>
#include <string>
#include <unordered_map>
#include <typeindex>
#include <algorithm>

namespace Bind {
	class Bindable;
}

namespace SceneGraph {
	class Material;

	class Scene {
	public:
		Scene() = default;
		Scene(const std::string& name);
		~Scene() = default;

		inline void SetName(const std::string& name) noexcept { m_name = name; };
		const std::string& GetName(const std::string& name) noexcept { return m_name; };

		void AddMaterial(std::unique_ptr<Material>&& mat);
		void AddDrawable(const std::type_index& type, std::unique_ptr<DrawItems::Drawable>&& item);

		void SetNodes(std::vector<std::unique_ptr<Node>>&& nodes);
		void AddNode(std::unique_ptr<Node>&& node);
		void AddChild(Node& child);
		void AddBindable(std::shared_ptr<Bind::Bindable> bindable);
		void AddBindable(std::shared_ptr<Bind::Bindable> bindable, Node& node);

		void SetBindables(const std::type_index& type_info, std::vector<std::shared_ptr<Bind::Bindable>> bindables);
		template <typename T>
		void SetComponent(std::vector<std::shared_ptr<Bind::Bindable>> bindables) {
			std::vector<std::shared_ptr<Bind::Bindable>> items(bindables.size());
			std::transform(bindables.begin(), bindables.end(), items.begin(),
				[](std::shared_ptr<T>& item)->std::shared_ptr<Bind::Bindable> {
					return std::static_pointer_cast<Bind::Bindable>(item);
				});
			SetBindables(typeid(T), items);
		}

		template <typename T>
		void ClearBindables() {
			SetBindables(typeid(T), {});
		}

		const std::vector<std::shared_ptr<Bind::Bindable>>& GetBindables(const std::type_index& type_info) const;
		template <typename T>
		std::vector<std::shared_ptr<T>> GetBindables() const {
			std::vector<std::shared_ptr<T>> items;

			if (HasBindable(typeid(T))) {
				auto& res = GetBindables(typeid(T));
				items.resize(res.size());
				std::transform(res.begin(), res.end(), items.begin(), [](const std::shared_ptr<Bind::Bindable>& item)->std::shared_ptr<T> {
					return std::dynamic_pointer_cast<T>(item);
					});
			}

			return items;
		}

		bool HasBindable(const std::type_index& type_info) const noexcept;
		template <typename T>
		bool HasBindable() const {
			return HasBindable(typeid(T));
		}

		Node* FindNode(const std::string& name);
		inline Node& GetRootNode() { return *m_root; };
		inline const std::vector<std::unique_ptr<Node>>& GetNodes() const noexcept { return m_nodes; };

	private:
		void SetupRootNode();//TODO

	private:
		std::string m_name;
		std::vector<std::unique_ptr<Node>> m_nodes;
		ControlNode* m_root = nullptr;//根节点一定是一个控制节点
		std::unordered_map<std::type_index, std::vector<std::shared_ptr<Bind::Bindable>>> m_bindables;
		std::unordered_map<std::type_index, std::vector<std::unique_ptr<DrawItems::Drawable>>> m_drawables;
		std::vector<std::unique_ptr<Material>> m_materials;
	};
}