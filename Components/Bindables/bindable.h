#pragma once

#include <Macros/conditional_noexcept.h>
#include <nocopyable.h>

#include <string>
#include <cassert>
#include <glad/glad.h>
#include <unordered_set>
#include <typeindex>

class TechniqueProbe;
class Drawable;

namespace Bind {
	class Bindable : public NoCopyable {
	public:
		virtual void Bind() noxnd = 0;
		virtual void InitializeParentReference(const Drawable&) noexcept
		{
		}
		virtual void Accept(TechniqueProbe&)
		{
		}
		virtual std::string GetUID() const noexcept
		{
			assert(false);
			return "";
		}
		virtual ~Bindable() = default;
		Bindable() = default;

		virtual std::type_index GetTypeInfo() const noexcept = 0;

		static int AllocateID(std::unordered_set<int>& id_set);
	};
}