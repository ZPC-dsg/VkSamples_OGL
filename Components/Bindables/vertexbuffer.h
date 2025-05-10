#pragma once

#include <Bindables/includer.h>
#include <Dynamic/dynamic_vertex.h>
#include <resourcefactory.h>

namespace Bind {
	class VertexBuffer {
	public:
		VertexBuffer(const std::string& tag, const Dynamic::Dvtx::CPUVertexBuffer& buffer);
		VertexBuffer(const Dynamic::Dvtx::CPUVertexBuffer& layout, std::shared_ptr<RawBuffer> buffer);
		~VertexBuffer() = default;

		void Bind() noxnd;
		template <typename... Ignore>//该模板参数只是为了适配bindable_resolver中的解析函数形式要求
		static std::string GenerateUID(const std::string& tag, Ignore... ignore) {
			return genID_impl(tag);
		}
		std::string GetUID() const noexcept;

		const Dynamic::Dvtx::VertexLayout& get_layout() const noexcept;
		inline std::string resource_name() const noexcept { return m_buffer->ResourceName(); }

		unsigned int VertexCount() const noexcept;

	private:
		static std::string genID_impl(const std::string& tag);

	private:
		std::shared_ptr<RawBuffer> m_buffer;
		Dynamic::Dvtx::VertexLayout m_layout;
	};
}