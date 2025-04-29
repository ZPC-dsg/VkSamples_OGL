#include <Dynamic/shader_reflection.h>

#include <algorithm>

namespace Dynamic {
	namespace Dsr {
#define ELEMENT_SIZE \
	X(GL_FLOAT, float) \
	X(GL_FLOAT_VEC2, glm::vec2) \
	X(GL_FLOAT_VEC3, glm::vec3) \
	X(GL_FLOAT_VEC4, glm::vec4) \
	X(GL_DOUBLE, double) \
	X(GL_DOUBLE_VEC2, glm::dvec2) \
	X(GL_DOUBLE_VEC3, glm::dvec3) \
	X(GL_DOUBLE_VEC4, glm::dvec4) \
	X(GL_INT, int) \
	X(GL_INT_VEC2, glm::ivec2) \
	X(GL_INT_VEC3, glm::ivec3) \
	X(GL_INT_VEC4, glm::ivec4) \
	X(GL_UNSIGNED_INT, unsigned int) \
	X(GL_UNSIGNED_INT_VEC2, glm::uvec2) \
	X(GL_UNSIGNED_INT_VEC3, glm::uvec3) \
	X(GL_UNSIGNED_INT_VEC4, glm::uvec4) \
	X(GL_BOOL, bool) \
	X(GL_BOOL_VEC2, glm::bvec2) \
	X(GL_BOOL_VEC3, glm::bvec3) \
	X(GL_BOOL_VEC4, glm::bvec4) \
	X(GL_FLOAT_MAT2, glm::mat2) \
	X(GL_FLOAT_MAT3, glm::mat3) \
	X(GL_FLOAT_MAT4, glm::mat4) \
	X(GL_DOUBLE_MAT2, glm::dmat2) \
	X(GL_DOUBLE_MAT3, glm::dmat3) \
	X(GL_DOUBLE_MAT4, glm::dmat4)

#define X(OGL_Type, Type) \
	sizeMap[OGL_Type] = sizeof(Type);

		std::unordered_map<GLenum, size_t> ShaderReflection::sizeMap;

		void ShaderReflection::InitializeSizeMap() {
			ELEMENT_SIZE
		}
	
		ShaderReflection::ShaderReflection(std::shared_ptr<Bind::ShaderProgram> program)
			:m_program(program)
		{
		}

		ShaderReflection::ShaderReflection(std::shared_ptr<Shader> shader)
			:m_program(std::make_shared<Bind::ShaderProgram>(shader->ID))
		{
		}

		std::vector<VertexAttrib> ShaderReflection::GetVertexAttribs() noxnd {
			std::vector<VertexAttrib> attribs;

			GLint active_attribs;
			glGetProgramiv(m_program->get_program(), GL_ACTIVE_ATTRIBUTES, &active_attribs);
			attribs.reserve(active_attribs);

			const size_t buff_size = 100;
			for (GLuint i = 0; i < (GLuint)active_attribs; i++) {
				VertexAttrib element;

				GLsizei length;
				char name[buff_size];

				glGetActiveAttrib(m_program->get_program(), i, buff_size, &length, &element.size, &element.type, name);
				element.name = std::string(name);
				element.location = glGetAttribLocation(m_program->get_program(), name);

				attribs.push_back(element);
			}

			//按location从小到大排列
			std::ranges::sort(attribs, [](const VertexAttrib& lhs, const VertexAttrib& rhs)->bool {return lhs.location < rhs.location; });

			return attribs;
		}

		std::unordered_map<std::string, std::vector<ConstantAttrib>> ShaderReflection::GetConstantAttribs() noxnd {
			std::unordered_map<std::string, std::vector<ConstantAttrib>> attribs;
			GLuint ID = m_program->get_program();

			GLint active_blocks;
			glGetProgramiv(ID, GL_ACTIVE_UNIFORM_BLOCKS, &active_blocks);

			for (int i = 0; i < active_blocks; i++) {
				GLchar block_name[100];
				GLsizei length;
				glGetActiveUniformBlockName(ID, i, sizeof(block_name), &length, block_name);
				attribs[std::string(block_name)] = std::vector<ConstantAttrib>();

				GLint num_uniforms;
				glGetActiveUniformBlockiv(ID, i, GL_UNIFORM_BLOCK_ACTIVE_UNIFORMS, &num_uniforms);

				std::vector<GLint> uniform_indices(num_uniforms);
				glGetActiveUniformBlockiv(ID, i, GL_UNIFORM_BLOCK_ACTIVE_UNIFORM_INDICES, uniform_indices.data());

				std::vector<GLuint> indices(uniform_indices.begin(), uniform_indices.end());
				std::vector<GLint> uniform_types(num_uniforms);
				glGetActiveUniformsiv(ID, num_uniforms, indices.data(), GL_UNIFORM_TYPE, uniform_types.data());
				std::vector<GLint> uniform_offsets(num_uniforms);
				glGetActiveUniformsiv(ID, num_uniforms, indices.data(), GL_UNIFORM_OFFSET, uniform_offsets.data());
				std::vector<GLint> uniform_ele_counts(num_uniforms);
				glGetActiveUniformsiv(ID, num_uniforms, indices.data(), GL_UNIFORM_SIZE, uniform_ele_counts.data());

				for (int j = 0; j < num_uniforms; j++) {
					GLchar uniform_name[100];
					glGetActiveUniformName(ID, indices[j], sizeof(uniform_name), &length, uniform_name);
					std::string ini_name = std::string(uniform_name);

					for (int k = 0; k < uniform_ele_counts[j]; k++) {
						ConstantAttrib attr;
						attr.block_index = i;
						attr.offset = uniform_offsets[j] + k * sizeMap[uniform_types[j]];
						attr.type = uniform_types[j];

						std::string real_name = uniform_ele_counts[j] == 1 ? ini_name : ini_name.substr(0, ini_name.length() - 2) + std::to_string(k) + "]";
						attr.name = real_name;

						attribs[block_name].push_back(attr);
					}
				}

				std::ranges::sort(attribs[block_name], [](const ConstantAttrib& lhs, const ConstantAttrib& rhs)->bool {return lhs.offset < rhs.offset; });
				//按照offset顺序排列
			}

			return attribs;
		}

		//ConstantEntryPoint
		ConstantEntryPoint::ConstantEntryPoint(std::string name, std::vector<ConstantAttrib> attribs)
			:m_attribs(std::move(attribs))
		{
			m_root = std::make_shared<ConstantTreeNode>(std::pair<int, int>{0, m_attribs.size() - 1});
			m_root->SetName(true, name);//根节点一定是一个结构体，名称就是uniform buffer的名称
			MakeTree(0, m_attribs.size(), m_root);
		}

		const ConstantAttrib& ConstantEntryPoint::operator[](size_t index) const noxnd {
			assert(index < m_attribs.size());
			return m_attribs[index];
		}

		void ConstantEntryPoint::MakeTree(size_t beg, size_t end, std::shared_ptr<ConstantTreeNode> root) {
			for (size_t i = beg; i < end; i++) {
				int first_dot, first_bracket;
				int type = IsArrayStruct(m_attribs[i].name, first_dot, first_bracket);

				if (type == 0) {
					std::shared_ptr<ConstantTreeNode> child = std::make_shared<ConstantTreeNode>(std::pair<int, int>{i, i});
					root->AppendChild(child);
				}
				else if (type == 1) {
					int l_beg = i;
					std::string cur = m_attribs[i].name.substr(0, first_dot + 1);
					while (i < end && m_attribs[i].name.substr(0, cur.size()) == cur) {
						ReviseName(m_attribs[i].name, false, first_dot);
						i++;
					}
					i--;
					std::shared_ptr<ConstantTreeNode> child = std::make_shared<ConstantTreeNode>(std::pair{ l_beg,i });
					cur.pop_back();
					child->SetName(true, cur);
					root->AppendChild(child);
					MakeTree(l_beg, i + 1, child);
				}
				else {
					int l_beg = i;
					int ele_count = 0;
					std::string cur = m_attribs[i].name.substr(0, first_bracket + 1);
					while (i < end && m_attribs[i].name.substr(0, cur.size()) == cur) {
						if (m_attribs[i].name[cur.size()] == '0') {
							ele_count++;
						}
						ReviseName(m_attribs[i].name, true, first_bracket);
						i++;
					}
					std::shared_ptr<ConstantTreeNode> child = std::make_shared<ConstantTreeNode>(std::pair{ l_beg,i - 1 });
					cur.pop_back();
					child->SetName(false, cur);
					root->AppendChild(child);
					for (int j = l_beg; j < i; j += ele_count) {
						auto t = std::find(m_attribs[j].name.begin(), m_attribs[j].name.end(), ']');
						int t_sz = t - m_attribs[j].name.begin();
						for (int k = 0; k < ele_count; k++) {
							m_attribs[j + k].name = m_attribs[j + k].name.substr(t_sz + 1, std::string::npos);
						}
						MakeTree(j, j + ele_count, child);
					}
					i--;
				}
			}
		}

		int ConstantEntryPoint::IsArrayStruct(std::string name, int& first_dot, int& first_bracket) {
			auto l_first_dot = std::find(name.begin(), name.end(), '.');
			auto l_first_bracket = std::find(name.begin(), name.end(), '[');

			first_dot = (l_first_dot == name.end()) ? -1 : l_first_dot - name.begin();
			first_bracket = (l_first_bracket == name.end()) ? -1 : l_first_bracket - name.begin();

			if (first_dot == -1 && first_bracket == -1)
				return 0;
			else if (first_dot == -1 || (first_bracket != -1 && first_bracket < first_dot))
				return -1;
			else
				return 1;
		}

		std::string ConstantEntryPoint::ReviseName(std::string& name, bool is_array, int first_char) {
			std::string cur_name = name.substr(0, first_char);
			name = is_array ? name.substr(first_char, std::string::npos) : name.substr(first_char + 1, std::string::npos);
			return cur_name;
		}

		//ConstantTreeNode
		ConstantTreeNode::ConstantTreeNode(std::pair<int, int> range)
			:m_range(range)
		{
		}

		void ConstantTreeNode::AppendChild(std::shared_ptr<ConstantTreeNode> child) {
			m_children.push_back(child);
		}

		void ConstantTreeNode::SetName(bool isStruct, std::string name) {
			m_name = std::pair<bool, std::string>{ isStruct,name };
		}

		bool ConstantTreeNode::IsStruct(std::string& name) const noexcept {
			assert(m_name.has_value());
			name = m_name.value().second;
			return m_name.value().first;
		}

		const ConstantTreeNode& ConstantTreeNode::operator[](size_t index) const noxnd {
			assert(index < ChildrenAmount());
			return *m_children[index];
		}
	}
}

std::ostream& operator<<(std::ostream& os, const Dynamic::Dsr::ConstantAttrib& attrib) {
	os << "name:" << "  " << attrib.name << "\n";
	os << "offset:" << "  " << std::to_string(attrib.offset) << "\n";
	os << "type:" << "  " << std::to_string(attrib.type) << "\n";

	return os;
}