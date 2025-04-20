#pragma once

#include <Bindables/bindable.h>
#include <Bindables/bindable_resolver.h>
#include <resourcefactory.h>

namespace Bind {
	class IndexBuffer {
	public:
		IndexBuffer(const std::string& tag, const std::vector<uint32_t>& indices);
		IndexBuffer(const std::string& tag, int count, std::shared_ptr<RawBuffer> buffer);
		~IndexBuffer() = default;

		void Bind() noxnd;
		template <typename... Ignore>
		static std::string GenerateUID(const std::string& tag, Ignore... ignore) {
			return genID_impl(tag);
		}
		std::string GetUID() const noexcept;

		inline unsigned int get_count() const noexcept { return m_count; }

	private:
		static std::string genID_impl(const std::string& tag);

	private:
		std::string m_tag;
		unsigned int m_count;
		std::shared_ptr<RawBuffer> m_buffer;
	};
}