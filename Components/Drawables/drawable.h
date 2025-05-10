#pragma once

#include <memory>
#include <vector>
#include <functional>
#include <glad/glad.h>

#include <Bindables/inputlayout.h>

namespace Bind {
	class InputLayout;
}

namespace DrawItems {
	class Drawable {
	public:
		Drawable() = default;
		Drawable(const std::string& name);
		virtual ~Drawable() = default;

		void SetVertex(std::shared_ptr<Bind::InputLayout> vertex);
		inline std::shared_ptr<Bind::InputLayout> GetVertex() const noexcept { return m_VAO; };
		inline void SetName(const std::string& name) noexcept { m_name = name; };
		inline std::string GetName() const noexcept { return m_name; };

		void Draw();

	private:
		std::string m_name;

		std::shared_ptr<Bind::InputLayout> m_VAO;
		size_t m_render_index = 0;//使用哪个渲染函数

		static std::vector<std::function<void(std::shared_ptr<Bind::InputLayout>)>> m_renderfunctions;
	};

	inline void DrawDefault(std::shared_ptr<Bind::InputLayout> VAO) {
		glDrawArrays(GL_TRIANGLES, 0, VAO->GetVertexCount());
	}

	inline void DrawIndexed(std::shared_ptr<Bind::InputLayout> VAO) {
		glDrawElements(GL_TRIANGLES, VAO->GetVertexCount(), GL_UNSIGNED_INT, 0);
	}

	inline void DrawInstanced(std::shared_ptr<Bind::InputLayout> VAO) {
		glDrawArraysInstanced(GL_TRIANGLES, 0, VAO->GetVertexCount(), VAO->GetInstanceCount());
	}

	inline void DrawIndexedInstanced(std::shared_ptr<Bind::InputLayout> VAO) {
		glDrawElementsInstanced(GL_TRIANGLES, VAO->GetVertexCount(), GL_UNSIGNED_INT, 0, VAO->GetInstanceCount());
	}
}