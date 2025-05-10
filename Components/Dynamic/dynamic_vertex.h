#pragma once

#include <Macros/conditional_noexcept.h>
#include <Dynamic/shader_reflection.h>
#include <ogl_structures.h>

#include <vector>
#include <string>
#include <glm/glm.hpp>
#include <glad/glad.h>


#define LAYOUT_ELEMENT_TYPES \
	X( GL_FLOAT ) \
	X( GL_FLOAT_VEC2 ) \
	X( GL_FLOAT_VEC3 ) \
	X( GL_FLOAT_VEC4 ) \
	X( GL_FLOAT_MAT2 ) \
	X( GL_FLOAT_MAT3 ) \
	X( GL_FLOAT_MAT4 )

namespace Dynamic {
	namespace Dvtx {
		/*
		class Vertex {
			friend class CPUVertexBuffer;

		public:
			Vertex(char* bytes, const VertexLayout& layout) noxnd;

			template <GLenum Type>
			auto& Attr(std::string name) noxnd {
				auto pAttribute = m_data + m_layout.Resolve<Type>(name).GetOffset();
				return *reinterpret_cast<typename VertexLayout::Map<Type>::SysType*>(pAttribute);
			}

			template <typename T>
			void SetAttributeByIndex(size_t i, T&& val) noxnd {
				const auto& element = m_layout.ResolveByIndex(i);
				auto pAttribute = m_data + element.GetOffset();
				VertexLayout::Bridge<AttributeSetting>(element.GetType(), this, pAttribute, std::forward<T>(val));
			}

		private:
			template <typename First, typename ...Rest>
			void SetAttributeByIndex(size_t i, First&& first, Rest&&... rest) noxnd {
				SetAttributeByIndex(i, std::forward<First>(first));
				SetAttributeByIndex(i + 1, std::forward<Rest>(rest)...);
			}

			template<GLenum DestLayoutType, typename SrcType>
			void SetAttribute(char* pAttribute, SrcType&& val) noxnd {
				using Dest = typename VertexLayout::Map<DestlayoutType>::SysType;
				if constexpr (std::is_assignable(Dest, SrcType)::value) {
					*reinterpret_cast<Dest*>(pAttribute) = val;
				}
				else {
					assert("Parameter attribute type mismatch!" && false);
				}
			}

			template <GLenum type>
			struct AttributeSetting {
				template <typename T>
				static constexpr auto Exec(std::string name, Vertex* vertex, char* pAttribute, T&& val) noxnd {
					return vertex->SetAttribute<type>(pAttribute, std::forward<T>(val));
				}
			};

		private:
			char* m_data = nullptr;
			const VertexLayout& m_layout;
		};

		class ConstVertex
		{
		public:
			ConstVertex( const Vertex& v ) noxnd;
			template<GLenum Type>
			const auto& Attr(std::string name) const noxnd
			{
				return const_cast<Vertex&>(vertex).Attr<Type>(name);
			}
		private:
			Vertex m_vertex;
		};
		*/

		class VertexLayout {
		public:
			template<GLenum> struct Map;//需要前置声明

			template<> struct Map<GL_FLOAT>
			{
				using SysType = float;
				static constexpr GLenum ele_format = GL_FLOAT;
				static constexpr int row_ele_count = 1;
				static constexpr int col_ele_count = 1;
				static constexpr const char* code = "Float";
			};
			template<> struct Map<GL_FLOAT_VEC2>
			{
				using SysType = glm::vec2;
				static constexpr GLenum ele_format = GL_FLOAT;
				static constexpr int row_ele_count = 2;
				static constexpr int col_ele_count = 1;
				static constexpr const char* code = "Vec2";
			};
			template<> struct Map<GL_FLOAT_VEC3>
			{
				using SysType = glm::vec3;
				static constexpr GLenum ele_format = GL_FLOAT;
				static constexpr int row_ele_count = 3;
				static constexpr int col_ele_count = 1;
				static constexpr const char* code = "Vec3";
			};
			template<> struct Map<GL_FLOAT_VEC4>
			{
				using SysType = glm::vec4;
				static constexpr GLenum ele_format = GL_FLOAT;
				static constexpr int row_ele_count = 4;
				static constexpr int col_ele_count = 1;
				static constexpr const char* code = "Vec4";
			};
			template<> struct Map<GL_FLOAT_MAT2>
			{
				using SysType = glm::mat2;
				static constexpr GLenum ele_format = GL_FLOAT;
				static constexpr int row_ele_count = 2;
				static constexpr int col_ele_count = 2;
				static constexpr const char* code = "Mat2";
			};
			template<> struct Map<GL_FLOAT_MAT3>
			{
				using SysType = glm::mat3;
				static constexpr GLenum ele_format = GL_FLOAT;
				static constexpr int row_ele_count = 3;
				static constexpr int col_ele_count = 3;
				static constexpr const char* code = "Mat3";
			};
			template<> struct Map<GL_FLOAT_MAT4>
			{
				using SysType = glm::vec3;
				static constexpr GLenum ele_format = GL_FLOAT;
				static constexpr int row_ele_count = 4;
				static constexpr int col_ele_count = 4;
				static constexpr const char* code = "Mat4";
			};

			template<template<GLenum> class F, typename... Args>
			static constexpr auto Bridge(GLenum type, std::string name, Args&&... args) noxnd {
				switch (type) {
					#define X(el) case el : return F<el>::Exec(name, std::forward<Args>(args)... );
					LAYOUT_ELEMENT_TYPES
					#undef X
				}
				assert("Invalid element type!" && false);//一定触发断言
				return F<GL_FLOAT>::Exec(name, std::forward<Args>(args)...);
			}

			enum InputClassification {
				PerVertex,
				PerInstance
			};

			enum InputSteppingType {
				Interleaved,
				Continuous
			};

			class Element
			{
			public:
				Element(const Dynamic::Dsr::VertexAttrib& attrib, size_t offset);
				size_t GetOffsetAfter() const noxnd;
				size_t GetOffset() const;
				size_t Size() const noxnd;
				static constexpr size_t SizeOf(GLenum type) noxnd;

				inline GLenum GetType() const noexcept { return m_attrib.type; }
				inline std::string GetName() const noexcept { return m_attrib.name; }
				inline GLuint GetLocation() const noexcept { return m_attrib.location; }

				OGL_INPUT_ELEMENT_DESC GetDesc() const noxnd;
				const char* GetCode() const noexcept;
			private:
				Dynamic::Dsr::VertexAttrib m_attrib;
				size_t m_offset;
			};

			template<GLenum Type>
			const Element& Resolve(std::string name) const noxnd
			{
				for (auto& e : m_elements)
				{
					if (e.GetType() == Type && e.GetName() == name)
					{
						return e;
					}
				}
				assert("Could not resolve element type" && false);
				return Element({}, 0);
			}
			const Element& ResolveByIndex(size_t i) const noxnd;
			VertexLayout& Append(Dynamic::Dsr::VertexAttrib attrib) noxnd;
			inline VertexLayout& SetInputClassification(InputClassification input) noexcept { m_input_classification = input; return *this; }
			inline VertexLayout& SetInputSteppingType(InputSteppingType type) noexcept { m_input_steppingtype = type; return *this; }
			inline VertexLayout& SetVertexCount(unsigned int vertices) noexcept { m_vertex_count = vertices; return *this; }
			size_t InterleavedSize() const noxnd;
			size_t ContinuousSize() const noxnd;
			size_t VertexSize() const noxnd;
			inline size_t GetElementCount() const noexcept { return m_elements.size(); }
			std::vector<OGL_INPUT_ELEMENT_DESC> GetOGLLayout() const noxnd;
			std::string GetCode() const noxnd;
			bool Has(GLenum type, std::string name) const noexcept;

			inline InputClassification GetInputClassification() const noexcept { return m_input_classification; }
			inline InputSteppingType GetInputSteppingType() const noexcept { return m_input_steppingtype; }
			inline size_t GetCount() const noexcept { return m_vertex_count; }

		private:
			std::vector<Element> m_elements;
			unsigned int m_vertex_count;
			InputClassification m_input_classification;
			InputSteppingType m_input_steppingtype;
		};

		class CPUVertexBuffer {
		public:
			//构造实例缓冲的时候vertices代表实例数
			CPUVertexBuffer(std::vector<Dynamic::Dsr::VertexAttrib> attribs, unsigned int vertices, VertexLayout::InputClassification classification = VertexLayout::InputClassification::PerVertex,
				VertexLayout::InputSteppingType type = VertexLayout::InputSteppingType::Interleaved) noxnd;

			inline const VertexLayout& get_layout() const noexcept { return m_layout; }
			inline void* get_data() const noexcept { return (void*)m_buffer.data(); }

			//void Resize(size_t newSize) noxnd;
			//暂且不支持顶点缓冲的大小变化

			inline size_t Count() const noxnd { return m_layout.GetCount(); }
			inline size_t BufferSize() const noxnd { return m_buffer.size(); }

			template <typename First, typename ...Rest>
			void InitializeData(int offset, const std::vector<First>& first, const std::vector<Rest>&... rest) noxnd;
			/*
			template <typename ...Params>
			void EmplaceBack(Params&&... params) noxnd {
				assert(sizeof...(params) == m_layout.GetElementCount() && "Param count doesn't match number of vertex elements");
				buffer.resize(buffer.size() + m_layout.Size());
				Back().SetAttributeByIndex(0u, std::forward<Params>(params)...);
			}
			*/

			//仅限对于Interleaved布局可用
			/*
			Vertex Back() noxnd;
			ConstVertex Back() const noxnd;
			Vertex Front() noxnd;
			ConstVertex Front() const noxnd;
			Vertex operator[](size_t i) noxnd;
			ConstVertex operator[](size_t i) const noxnd;
			*/

		private:
			template <typename First, typename ...Rest>
			void InitializeInterleaved(int offset, const std::vector<First>& first, const std::vector<Rest>&... rest) noxnd;
			template <typename First, typename ...Rest>
			void InitializeContinuous(int offset, const std::vector<First>& first, const std::vector<Rest>&... rest) noxnd;
			template <typename T>
			void InitializeInterleaved(const std::vector<T>& data, int offset) noxnd;
			template <typename T>
			void InitializeContinuous(const std::vector<T>& data, int offset) noxnd;
			void InitializeInterleaved(int offset) noexcept { return; }
			void InitializeContinuous(int offset) noexcept { return; }

		private:
			std::vector<char> m_buffer;
			VertexLayout m_layout;
		};

		template <typename First, typename ...Rest>
		void CPUVertexBuffer::InitializeData(int offset, const std::vector<First>& first, const std::vector<Rest>&... rest) noxnd {
			m_layout.GetInputSteppingType() == VertexLayout::InputSteppingType::Interleaved ? InitializeInterleaved(offset, first, rest...) : InitializeContinuous(offset, first, rest...);
			return;
		}

		template <typename First, typename ...Rest>
		void CPUVertexBuffer::InitializeInterleaved(int offset, const std::vector<First>& first, const std::vector<Rest>&... rest) noxnd {
			InitializeInterleaved(first, offset);
			offset += sizeof(First);
			InitializeInterleaved(rest..., offset);
		}

		template <typename T>
		void CPUVertexBuffer::InitializeInterleaved(const std::vector<T>& data, int offset) noxnd {
			assert(data.size() == m_layout.GetCount());

			int l_offset = offset;
			for (int i = 0; i < data.size(); i++) {
				*reinterpret_cast<T*>(m_buffer.data() + l_offset) = data[i];
				l_offset += m_layout.InterleavedSize();
			}

			return;
		}

		template <typename First, typename ...Rest>
		void CPUVertexBuffer::InitializeContinuous(int offset, const std::vector<First>& first, const std::vector<Rest>&... rest) noxnd {
			InitializeContinuous(first, offset);
			offset += first.size() * sizeof(First);
			InitializeContinuous(rest..., offset);
		}

		template <typename T>
		void CPUVertexBuffer::InitializeContinuous(const std::vector<T>& data, int offset) noxnd {
			assert(data.size() == m_layout.GetCount());

			int l_offset = offset;
			for (int i = 0; i < data.size(); i++) {
				*reinterpret_cast<T*>(m_buffer.data() + l_offset) = data[i];
				l_offset += sizeof(T);
			}

			return;
		}
	}
}

#ifndef DVTX_SOURCE_FILE
#undef LAYOUT_ELEMENT_TYPES
#endif