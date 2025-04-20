#pragma once

#include <Bindables/vertexbuffer.h>
#include <Bindables/indexbuffer.h>

namespace Bind {
	class InputLayout :public Bindable {
	public:
		InputLayout(std::vector<std::shared_ptr<VertexBuffer>> vertex, std::shared_ptr<IndexBuffer> index = nullptr);
		~InputLayout() = default;

		void Bind() noxnd override;
		static std::shared_ptr<InputLayout> Resolve(std::vector<std::shared_ptr<VertexBuffer>> vertex, std::shared_ptr<IndexBuffer> index);
		static std::string GenerateUID(std::vector<std::shared_ptr<VertexBuffer>> vertex, std::shared_ptr<IndexBuffer> index);
		std::string GetUID() const noexcept override;

	private:
		void bind_impl() noxnd;

	private:
		GLuint m_VAO;
		std::vector<std::shared_ptr<VertexBuffer>> m_vertex;//可能会绑定多个buffer，比如一个逐顶点缓冲，一个逐实例缓冲
		std::shared_ptr<IndexBuffer> m_index;
	};
}