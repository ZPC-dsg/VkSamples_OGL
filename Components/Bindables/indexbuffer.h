#pragma once

#include <Bindables/includer.h>
#include <resourcefactory.h>

namespace Bind {
	class IndexBuffer {
	public:
		IndexBuffer(const std::string& tag, const std::vector<uint32_t>& indices);
		IndexBuffer(int count, std::shared_ptr<RawBuffer> buffer);
		~IndexBuffer() = default;

		void Bind() noxnd;
		template <typename... Ignore>
		static std::string GenerateUID(const std::string& tag, Ignore... ignore) {
			return genID_impl(tag);
		}
		std::string GetUID() const noexcept;

		inline unsigned int get_count() const noexcept { return m_count; }
		inline std::string resource_name() const noexcept { return m_buffer->ResourceName(); }

	private:
		static std::string genID_impl(const std::string& tag);

	private:
		unsigned int m_count;
		std::shared_ptr<RawBuffer> m_buffer;
	};
}