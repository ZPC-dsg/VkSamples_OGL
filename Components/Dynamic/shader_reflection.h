#pragma once

#include <Macros/conditional_noexcept.h>
#include <shader.h>

#include <glad/glad.h>
#include <unordered_map>
#include <optional>

template <GLenum Type> struct GLSLTypeMap;
#define MAPPING_IMPLEMENTATION \
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
#define X(GLSLType, Type) \
	template <> \
	struct GLSLTypeMap<GLSLType> { \
		using ConvType = Type; \
		static constexpr size_t ConvSize = sizeof(Type); \
	};

MAPPING_IMPLEMENTATION
#undef X
#undef MAPPING_IMPLEMENTATION


namespace Dynamic {
	namespace Dsr {
		struct VertexAttrib {
			GLuint location;
			GLenum type;
			GLint size;
			std::string name;
		};

		struct ConstantAttrib {
			std::string name;
			GLenum type;
			GLuint block_index;
			size_t offset;
		};

		struct UniformAttrib {
			std::string name;
			GLenum type;
			GLint location;
		};


		class ShaderReflection {
		public:
			~ShaderReflection() = default;

			static std::vector<VertexAttrib> GetVertexAttribs(GLuint program) noxnd;
			static std::unordered_map<std::string, std::vector<ConstantAttrib>> GetConstantAttribs(GLuint program) noxnd;
			static std::unordered_map<std::string, std::vector<UniformAttrib>> GetUniformAttribs(GLuint program) noxnd;

			static void InitializeSizeMap();

		private:
			ShaderReflection() = default;

			static std::string process_string(const std::string& name) noexcept;

		private:
			static std::unordered_map<GLenum, size_t> sizeMap;
		};

		class ConstantTreeNode;

		//每个常量缓冲区的入口点，保存了该区块内的所有成员信息（在一个vector中）以及常量缓冲区的树形布局的根节点
		//要求： 1.常量缓冲区采用std 430布局
		//       2.常量缓冲区内成员名称中不能包含'.'以及'['和']'，不能包含数字
		class ConstantEntryPoint {
		public:
			ConstantEntryPoint(std::string name, std::vector<ConstantAttrib> attribs);

			inline std::shared_ptr<ConstantTreeNode> RootNode() const noexcept { return m_root; };
			inline size_t AttribAmount() const noexcept { return m_attribs.size(); };

			const ConstantAttrib& operator[](size_t index) const noxnd;

		private:
			void MakeTree(size_t beg, size_t end, std::shared_ptr<ConstantTreeNode> root);
			int IsArrayStruct(std::string name, int& first_dot, int& first_bracket);//返回0代表一般元素，-1代表array，1代表struct
			std::string ReviseName(std::string& name, bool is_array, int first_char);

		private:
			std::vector<ConstantAttrib> m_attribs;
			std::shared_ptr<ConstantTreeNode> m_root;
		};

		class UniformEntryPoint {
		public:
			UniformEntryPoint(std::string name, std::vector<UniformAttrib> attribs);

			inline std::string GetName() const noexcept { return m_name; };
			inline std::shared_ptr<ConstantTreeNode> RootNode() const noexcept { return m_root; };
			inline size_t AttribAmount() const noexcept { return m_attribs.size(); };

			const UniformAttrib& operator[](size_t index) const noxnd;

		private:
			void MakeTree(size_t beg, size_t end, std::shared_ptr<ConstantTreeNode> root);
			int IsArrayStruct(std::string name, int& first_dot, int& first_bracket);//返回0代表一般元素，-1代表array，1代表struct
			std::string ReviseName(std::string& name, bool is_array, int first_char);

		private:
			std::vector<UniformAttrib> m_attribs;
			std::shared_ptr<ConstantTreeNode> m_root;
			std::string m_name;
		};

		class ConstantTreeNode {
		public:
			ConstantTreeNode(std::pair<int, int> range);

			void AppendChild(std::shared_ptr<ConstantTreeNode> child);
			void SetName(bool isStruct, std::string name);

			std::string GetName() const noexcept;
			inline size_t ChildrenAmount() const noexcept { return m_children.size(); };
			inline std::pair<int, int> GetRange() const noexcept { return m_range; };
			bool IsStruct(std::string& name) const noexcept;
			inline bool IsLeaf() const noexcept { return !m_name.has_value(); }

			const ConstantTreeNode& operator[](size_t index) const noxnd;
			std::shared_ptr<ConstantTreeNode> GetChild(size_t index) const noxnd;

		private:
			std::vector<std::shared_ptr<ConstantTreeNode>> m_children;
			std::pair<int, int> m_range;//开始和结束的位置对应于向量中的索引
			std::optional<std::pair<bool, std::string>> m_name;//bool为true表示该节点为一个struct，为false表示为一个array
		};
	}
}

#ifdef _DEBUG
std::ostream& operator<<(std::ostream& os, const Dynamic::Dsr::ConstantAttrib& attrib);
std::ostream& operator<<(std::ostream& os, const Dynamic::Dsr::UniformAttrib& attrib);
#endif