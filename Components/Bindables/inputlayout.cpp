#include <Bindables/inputlayout.h>

namespace Bind {
	InputLayout::InputLayout(const std::string& tag, std::vector<std::shared_ptr<VertexBuffer>> vertex, std::shared_ptr<IndexBuffer> index)
		:m_vertex(vertex), m_index(index), m_tag(tag) {
		glGenVertexArrays(1, &m_VAO);
		bind_impl();
		glObjectLabel(GL_VERTEX_ARRAY, m_VAO, -1, m_tag.c_str());
	}

	void InputLayout::bind_impl() noxnd {
		using namespace Dynamic::Dvtx;

		glBindVertexArray(m_VAO);

		for (auto v : m_vertex) {
			v->Bind();
			
			const VertexLayout& layout = v->get_layout();
			std::vector<OGL_INPUT_ELEMENT_DESC> descs = layout.GetOGLLayout();
			VertexLayout::InputClassification cl = layout.GetInputClassification();
			VertexLayout::InputSteppingType st = layout.GetInputSteppingType();
			GLsizei stride = st == VertexLayout::InputSteppingType::Interleaved ? layout.VertexSize() : 0;

			for (const auto& d : descs) {
				glEnableVertexAttribArray(d.sementic_location);

				if (d.element_column == 1) {
					glVertexAttribPointer(d.sementic_location, d.element_count, d.element_type, GL_FALSE, stride, (void*)(d.byteoffset));
				}
				else {//假设使用的矩阵都是方阵
					GLsizei new_stride = cl == VertexLayout::InputSteppingType::Interleaved ? stride: d.element_column * d.element_column * sizeof(float);
					for (int i = 0; i < d.element_column; i++) {
						glVertexAttribPointer(d.sementic_location + i, d.element_count, d.element_type, GL_FALSE, new_stride, (void*)(d.byteoffset + i * d.element_column * sizeof(float)));
					}
				}
			}
		}

		if (m_index) {
			m_index->Bind();
		}

		glBindVertexArray(0);
	}

	void InputLayout::Bind() noxnd {
		glBindVertexArray(m_VAO);
	}

	std::shared_ptr<InputLayout> InputLayout::Resolve(const std::string& tag, std::vector<std::shared_ptr<VertexBuffer>> vertex, std::shared_ptr<IndexBuffer> index) {
		return BindableResolver::Resolve<InputLayout>(tag, vertex, index);
	}

	std::string InputLayout::GenerateUID(const std::string& tag, std::vector<std::shared_ptr<VertexBuffer>> vertex, std::shared_ptr<IndexBuffer> index) {
		using namespace std::string_literals;

		std::string uid = typeid(InputLayout).name() + "#"s + tag + "#"s;
		for (auto v : vertex) {
			uid += v->GetUID() + "__"s;
		}
		if (index) {
			uid += index->GetUID();
		}
		else {
			uid += "NoIndex"s;
		}

		return uid;
	}

	std::string InputLayout::GetUID() const noexcept {
		return GenerateUID(m_tag, m_vertex, m_index);
	}
}