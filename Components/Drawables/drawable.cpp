#include <Drawables/drawable.h>

namespace DrawItems {
	Drawable::Drawable(const std::string& name):m_name(name){}

	std::vector<std::function<void(std::shared_ptr<Bind::InputLayout>)>> Drawable::m_renderfunctions = {
		DrawDefault,DrawIndexed,DrawInstanced,DrawIndexedInstanced
	};

	void Drawable::Draw() {
		m_VAO->Bind();
		m_renderfunctions[m_render_index](m_VAO);
	}

	void Drawable::SetVertex(std::shared_ptr<Bind::InputLayout> VAO) {
		m_VAO = VAO;
		m_render_index = m_VAO->HasIndexBuffer() + ((m_VAO->IsInstanceDraw()) << 1);
	}
}