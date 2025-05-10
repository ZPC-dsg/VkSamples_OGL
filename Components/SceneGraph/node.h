#pragma once

#include <SceneGraph/transform.h>
#include <SceneGraph/material.h>

#include <vector>
#include <string>
#include <memory>
#include <typeindex>
#include <unordered_map>
#include <functional>
#include <tuple>
#include <glad/glad.h>

namespace Bind {
	class Bindable;
}

namespace DrawItems {
	class Drawable;
}

//TODO ��������nodeӦ����Ҫ�����ӽڵ㣬һ����ͨ��node���洢��drawable�Լ�transform��Ϣ����һ��û��drawable��node�������ڱ���һЩ�Ӵ��ڵ㶼��Ҫʹ�õ���bindable��
//�����������һϵ�еĺ����������ھ�����transform����ڵ����ϢӦ����ô�����ݵ���ɫ���С�
namespace SceneGraph {
	class Node {
	public:
		Node(const size_t id, const std::string& name);
		virtual ~Node() = default;

		virtual void UpdateWorldMatrix() = 0;
		virtual void ForceUpdateWorldMatrix() = 0;

		inline const size_t GetID() const noexcept { return m_id; };
		inline const std::string& GetName() const noexcept { return m_name; };
		inline const std::vector<Node*>& GetChildren() const { return m_children; };
		inline const glm::mat4& GetWorldMatrix() const noexcept { return m_world_matrix; };

		virtual void SetParent(Node& parent);
		inline Node* GetParent() { return m_parent; };

		void AddChild(Node& child);
		
		void SetBindable(std::shared_ptr<Bind::Bindable> bindable);

		std::shared_ptr<Bind::Bindable> GetBindable(const std::type_index& type_info);
		template <typename T>
		std::shared_ptr<T> GetBindable() {
			return std::dynamic_pointer_cast<T>(GetBindable(typeid(T)));
		}

		bool HasComponent(const std::type_index& type_info) const;
		template <typename T>
		bool HasComponent() {
			return HasComponent(typeid(T));
		}

	protected:
		unsigned int m_id;
		std::string m_name;

		std::unordered_map<std::type_index, std::shared_ptr<Bind::Bindable>> m_bindables;

		Node* m_parent = nullptr;
		std::vector<Node*> m_children;//��ʹ������ָ���Ա���ѭ������

		glm::mat4 m_world_matrix = glm::mat4(1.0);
	};

	class EntityNode : public Node {
	public:
		EntityNode(const size_t id, const std::string& name);
		~EntityNode() = default;

		const glm::mat4& CalculateWorldMatrix() const noexcept;
		void SetTranslation(const glm::vec3& translate) noexcept;
		void SetRotation(const glm::vec3& axis, float angle) noexcept;
		void SetRotation(const glm::vec4& quat) noexcept;
		void SetScaling(const glm::vec3& scale) noexcept;

		void UpdateWorldMatrix() override;
		void SetParent(Node& node) override;

		inline void AddDrawable(DrawItems::Drawable& item) { m_drawables.push_back(&item); };
		inline void AddMaterial(Material& mat) { m_materials.push_back(&mat); };

	private:
		void ForceUpdateWorldMatrix() override;

	private:
		std::vector<DrawItems::Drawable*> m_drawables;
		std::vector<Material*> m_materials;//ֻ��mesh�Ż���material��������Ϣ����������������

		Transform m_transform;
	};

	class TransformFuncBase {
	public:
		virtual void operator()() = 0;
		
		virtual ~TransformFuncBase() = default;
	};

	template <typename Func, typename... Args>
	class TransformFunction :public TransformFuncBase {
	public:
		TransformFunction(Func func, Args&&... args) :m_func(func), m_args(std::make_tuple(std::forward<Args>(args)...)) {}
		~TransformFunction() = default;

		void operator()() override {}//TODO

	private:
		std::function<typename std::invoke_result<Func, Args...>::type(Args...)> m_func;
		std::tuple<Args...> m_args;
	};

	//Ҫ��ú���һ������һ��mat4���͵ı���
	template <typename Func,typename... Args>
	concept AvailableTransformFunc = requires(Func f, Args... args) {
		{ f(args...) }->std::same_as<glm::mat4>;
	};

	class ControlNode :public Node {
	public:
		ControlNode(const size_t id, const std::string& name);
		~ControlNode() = default;

		template <typename Func, typename... Args>
		    requires AvailableTransformFunc<Func, Args...>
		void AddTransformFunc(const std::string& name, Func f, Args&&... args) {
			m_transform_functions.emplace(name, std::make_shared<TransformFunction<Func, Args...>>(f, std::forward<Args>(args)...));
		}

		void AddTextureConfig(const std::string& name, GLuint binding, Material::TextureCategory type);


		void UpdateWorldMatrix() override {}//TODO

	private:
		void ForceUpdateWorldMatrix() override {}//TODO

	private:
		std::unordered_map<std::string, std::shared_ptr<TransformFuncBase>> m_transform_functions;
		std::vector<std::tuple<std::string, GLuint, Material::TextureCategory>> m_texture_vector;
	};
}