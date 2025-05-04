#include <Bindables/constantbuffer.h>
#include <Dynamic/shader_reflection_resolver.h>

namespace Bind {
	ConstantBuffer::ConstantBuffer(const std::string& tag, std::shared_ptr<ShaderProgram> shader, const std::string& buffer_name, unsigned int binding)
		:m_binding_point(binding), m_programID(shader->get_program()), m_buffer_name(buffer_name)
	{
		const auto& cb = Dynamic::Dsr::ShaderReflectionResolver::ResolveForCBuffer(shader, buffer_name);
		Dynamic::Dsr::ConstantEntryPoint entry(buffer_name, cb);
		m_cpubuffer = std::make_shared<Dynamic::Dcb::CPUConstantBuffer>(entry);

		m_buffer = std::static_pointer_cast<RawBuffer>(ResourceFactory::CreateBuffer(tag, m_cpubuffer->GetSizeInBytes(),
			GL_DYNAMIC_STORAGE_BIT | GL_MAP_WRITE_BIT | GL_MAP_PERSISTENT_BIT | GL_MAP_COHERENT_BIT));
		m_buffer->BindBase(GL_UNIFORM_BUFFER, binding);
	}

	ConstantBuffer::ConstantBuffer(std::shared_ptr<ShaderProgram> shader, const std::string& buffer_name, unsigned int binding, std::shared_ptr<RawBuffer> buffer) 
		:m_binding_point(binding), m_buffer(buffer), m_programID(shader->get_program()), m_buffer_name(buffer_name)
	{
		assert("Buffer cannot satisfy requirements of constant buffer!" && (buffer->HasFlag(GL_DYNAMIC_STORAGE_BIT) && buffer->HasFlag(GL_MAP_WRITE_BIT)
			&& buffer->HasFlag(GL_MAP_PERSISTENT_BIT) && buffer->HasFlag(GL_MAP_COHERENT_BIT)));

		const auto& cb = Dynamic::Dsr::ShaderReflectionResolver::ResolveForCBuffer(shader, buffer_name);
		Dynamic::Dsr::ConstantEntryPoint entry(buffer_name, cb);
		m_cpubuffer = std::make_shared<Dynamic::Dcb::CPUConstantBuffer>(entry);

		m_buffer->BindBase(GL_UNIFORM_BUFFER, binding);
	}

	void ConstantBuffer::Bind() noxnd {
		m_buffer->Bind(GL_UNIFORM_BUFFER);
	}

	std::shared_ptr<ConstantBuffer> ConstantBuffer::Resolve(const std::string& tag, std::shared_ptr<ShaderProgram> shader, const std::string& buffer_name, unsigned int binding) {
		return BindableResolver::Resolve<ConstantBuffer>(tag, shader, buffer_name, binding);
	}

	std::shared_ptr<ConstantBuffer> ConstantBuffer::Resolve(std::shared_ptr<ShaderProgram> shader, const std::string& buffer_name, unsigned int binding, std::shared_ptr<RawBuffer> buffer) {
		return BindableResolver::Resolve<ConstantBuffer>(shader, buffer_name, binding, buffer);
	}

	std::string ConstantBuffer::GenerateUID(const std::string& tag, std::shared_ptr<ShaderProgram> shader, const std::string& buffer_name, unsigned int binding) {
		using namespace std::string_literals;

		return typeid(ConstantBuffer).name() + "#"s + tag + "#"s + std::to_string(shader->get_program()) + "#"s + buffer_name;
	}

	std::string ConstantBuffer::GenerateUID(std::shared_ptr<ShaderProgram> shader, const std::string& buffer_name, unsigned int binding, std::shared_ptr<RawBuffer> buffer) {
		using namespace std::string_literals;

		return typeid(ConstantBuffer).name() + "#"s + buffer->ResourceName() + "#"s + std::to_string(shader->get_program()) + "#"s + buffer_name;
	}

	std::string ConstantBuffer::GetUID() const noexcept {
		using namespace std::string_literals;

		return typeid(ConstantBuffer).name() + "#"s + m_buffer->ResourceName() + "#"s + std::to_string(m_programID) + "#"s + m_buffer_name;
	}

	Dynamic::Dcb::ConstantElementRef ConstantBuffer::operator[](const std::string& key) noxnd {
		return (*m_cpubuffer)[key];
	}

	Dynamic::Dcb::ConstConstantElementRef ConstantBuffer::operator[](const std::string& key) const noxnd {
		return (*m_cpubuffer)[key];
	}

	Dynamic::Dcb::ConstantElementRef ConstantBuffer::EditConstant(const std::string& key) noxnd {
		return (*this)[key];
	}

	Dynamic::Dcb::ConstConstantElementRef ConstantBuffer::DisplayConstant(const std::string& key) const noxnd {
		return (*this)[key];
	}

	void ConstantBuffer::Update() noxnd {
		m_buffer->UpdataMap(m_cpubuffer->GetSizeInBytes(), 0, (void*)m_cpubuffer->GetData());
	}
}