#pragma once

#include <Bindables/vertexbuffer.h>
#include <Bindables/indexbuffer.h>

namespace Bind {
	class InputLayout :public Bindable {
	public:
		InputLayout(const std::string& tag, std::vector<std::shared_ptr<VertexBuffer>> vertex, std::shared_ptr<IndexBuffer> index = nullptr);
		~InputLayout() = default;

		void Bind() noxnd override;
		static std::shared_ptr<InputLayout> Resolve(const std::string& tag, std::vector<std::shared_ptr<VertexBuffer>> vertex, std::shared_ptr<IndexBuffer> index = nullptr);
		static std::string GenerateUID(const std::string& tag, std::vector<std::shared_ptr<VertexBuffer>> vertex, std::shared_ptr<IndexBuffer> index);
		std::string GetUID() const noexcept override;

	private:
		void bind_impl() noxnd;

	private:
		GLuint m_VAO;
		std::string m_tag;
		std::vector<std::shared_ptr<VertexBuffer>> m_vertex;//可能会绑定多个buffer，比如一个逐顶点缓冲，一个逐实例缓冲
		std::shared_ptr<IndexBuffer> m_index;
	};
}