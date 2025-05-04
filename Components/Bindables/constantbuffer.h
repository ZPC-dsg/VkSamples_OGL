#pragma once

#include <Bindables/includer.h>
#include <Bindables/shaderprogram.h>
#include <resourcefactory.h>

namespace Bind {
	class ConstantBuffer :public Bindable {
	public:
		ConstantBuffer(const std::string& tag, std::shared_ptr<ShaderProgram> shader, const std::string& buffer_name, unsigned int binding);
		ConstantBuffer(std::shared_ptr<ShaderProgram> shader, const std::string& buffer_name, unsigned int binding, std::shared_ptr<RawBuffer> buffer);
		~ConstantBuffer() = default;

		void Bind() noxnd override;
		static std::shared_ptr<ConstantBuffer> Resolve(const std::string& tag, std::shared_ptr<ShaderProgram> shader, const std::string& buffer_name, unsigned int binding);
		static std::shared_ptr<ConstantBuffer> Resolve(std::shared_ptr<ShaderProgram> shader, const std::string& buffer_name, unsigned int binding, std::shared_ptr<RawBuffer> buffer);
		static std::string GenerateUID(const std::string& tag, std::shared_ptr<ShaderProgram> shader, const std::string& buffer_name, unsigned int binding);
		static std::string GenerateUID(std::shared_ptr<ShaderProgram> shader, const std::string& buffer_name, unsigned int binding, std::shared_ptr<RawBuffer> buffer);
		std::string GetUID() const noexcept override;

		Dynamic::Dcb::ConstantElementRef operator[](const std::string& key) noxnd;
		Dynamic::Dcb::ConstConstantElementRef operator[](const std::string& key) const noxnd;

		Dynamic::Dcb::ConstantElementRef EditConstant(const std::string& key) noxnd;
		Dynamic::Dcb::ConstConstantElementRef DisplayConstant(const std::string& key) const noxnd;

		void Update() noxnd;

	private:
		std::shared_ptr<RawBuffer> m_buffer;
		std::shared_ptr<Dynamic::Dcb::CPUConstantBuffer> m_cpubuffer;
		unsigned int m_binding_point;
		GLuint m_programID;
		std::string m_buffer_name;
	};
}