#pragma once

#include <Dynamic/shader_reflection.h>

#define TYPE_GENERATOR \
	X(Float,GL_FLOAT,F1) \
	X(Float2,GL_FLOAT_VEC2,F2) \
	X(Float3,GL_FLOAT_VEC3,F3) \
	X(Float4,GL_FLOAT_VEC4,F4) \
	X(Double,GL_DOUBLE,D1) \
	X(Double2,GL_DOUBLE_VEC2,D2) \
	X(Double3,GL_DOUBLE_VEC3,D3) \
	X(Double4,GL_DOUBLE_VEC4,D4) \
	X(Int,GL_INT,I1) \
	X(Int2,GL_INT_VEC2,I2) \
	X(Int3,GL_INT_VEC3,I3) \
	X(Int4,GL_INT_VEC4,I4) \
	X(Uint,GL_UNSIGNED_INT,U1) \
	X(Uint2,GL_UNSIGNED_INT_VEC2,U2) \
	X(Uint3,GL_UNSIGNED_INT_VEC3,U3) \
	X(Uint4,GL_UNSIGNED_INT_VEC4,U4) \
	X(Bool,GL_BOOL,B1) \
	X(Bool2,GL_BOOL_VEC2,B2) \
	X(Bool3,GL_BOOL_VEC3,B3) \
	X(Bool4,GL_BOOL_VEC4,B4) \
	X(FMat2,GL_FLOAT_MAT2,FM2) \
	X(FMat3,GL_FLOAT_MAT3,FM3) \
	X(FMat4,GL_FLOAT_MAT4,FM4) \
	X(Dmat2,GL_DOUBLE_MAT2,DM2) \
	X(DMat3,GL_DOUBLE_MAT3,DM3) \
	X(DMat4,GL_DOUBLE_MAT4,DM4)

namespace Dynamic {
	namespace Dcb {
		enum LeafType {
#define X(Type,GLSLType,Code) Type,
			TYPE_GENERATOR
#undef X
			Struct,
			Array,
			Empty
		};

		template <LeafType Type> struct LeafMap { static constexpr bool valid = false; };
#define X(Type,GLSLType,Code) \
		template <> \
		struct LeafMap<Type> { \
			using SysType = typename GLSLTypeMap<GLSLType>::ConvType; \
			static constexpr size_t SysSize = GLSLTypeMap<GLSLType>::ConvSize; \
			static constexpr const char* SysCode = #Code; \
			static constexpr bool valid = true; \
		};

		TYPE_GENERATOR
#undef X
	    
		template <typename T> struct ReverseLeafMap { static constexpr bool valid = false; };
#define X(Type,GLSLType,Code) \
		template <> \
		struct ReverseLeafMap<typename LeafMap<Type>::SysType> { \
			static constexpr LeafType SysType = Type; \
		    static constexpr bool valid = true; \
		};

		TYPE_GENERATOR
#undef X
		
		class LayoutElement {
		private:
			struct ExtraDataBase {
				ExtraDataBase() = default;
				virtual ~ExtraDataBase() = default;
			};

			friend class Layout;
			friend struct ExtraData;
		
		public:
			std::string GetSignature() const noxnd;
			size_t GetSizeInBytes() const noxnd;
			size_t GetOffsetEnd() const noxnd;
			bool Exists() const noexcept;

			//仅对结构体类型元素适用
			LayoutElement& operator[](const std::string& key) noxnd;
			const LayoutElement& operator[](const std::string& key) const noxnd;
		    //仅对数组类型元素适用
			LayoutElement& operator[](size_t index) noxnd;
			const LayoutElement& operator[](size_t index) const noxnd;

			template<typename T>
			size_t Resolve() const noxnd
			{
				switch (m_type)
				{
#define X(Type,GLSLType,Code) case Type: assert(typeid(LeafMap<Type>::SysType) == typeid(T)); return m_offset.value();
					TYPE_GENERATOR
#undef X
				default:
					assert("Tried to resolve non-leaf element!" && false);
					return 0u;
				}
			}

			static LeafType GLSLTypeToLeafType(GLenum type) noexcept;

		private:
			LayoutElement() = default;
			LayoutElement(LeafType type, size_t offset);

			void AppendChild(const Dynamic::Dsr::ConstantTreeNode& root, const Dynamic::Dsr::ConstantEntryPoint& entry);

			std::string GetSignatureForStruct() const noxnd;
			std::string GetSignatureForArray() const noxnd;

			static LayoutElement& GetEmptyElement() noexcept
			{
				static LayoutElement empty{};
				return empty;
			}

		private:
			std::optional<size_t> m_offset;//Empty元素没有offset
			LeafType m_type = LeafType::Empty;
			std::unique_ptr<ExtraDataBase> m_extradata;
		};

		struct ExtraData {
			struct Struct :public LayoutElement::ExtraDataBase {
				std::vector<std::pair<std::string, LayoutElement>> m_elements;
			};

			struct Array :public LayoutElement::ExtraDataBase {
				std::vector<LayoutElement> m_elements;
			};
		};

		class Layout {
			friend class CPUConstantBuffer;

		public:
			size_t GetSizeInBytes() const noexcept;
			std::string GetSignature() const noxnd;
			inline std::shared_ptr<LayoutElement> ShareRoot() const noexcept { return m_root; };

			LayoutElement& operator[](const std::string& key) noxnd;
			const LayoutElement& operator[](const std::string& key) const noxnd;

		private:
			Layout(const Dynamic::Dsr::ConstantEntryPoint& entry);

		private:
			std::shared_ptr<LayoutElement> m_root;//根节点一定是一个Struct类型的元素
		};

		class ConstElementRef {
			friend class CPUConstantBuffer;
			friend class ElementRef;

		public:
			class Ptr {
				friend class ConstElementRef;

			public:
				template <typename T>
				operator const T* () const noxnd {
					static_assert(ReverseLeafMap<std::remove_const_t<T>>::valid, "Unsupported SysType used in pointer conversion!");
					return &static_cast<const T&>(*m_ref);
				}

			private:
				Ptr(const ConstElementRef* ref) noexcept;

			private:
				const ConstElementRef* m_ref;
			};

		public:
			bool Exists() const noexcept;

			ConstElementRef operator[](const std::string& key) const noxnd;
			ConstElementRef operator[](size_t index) const noxnd;
			Ptr operator&() const noxnd;

			template <typename T>
			operator const T& () const noxnd {
				static_assert(ReverseLeafMap<std::remove_const_t<T>>::valid, "Unsupported SysType used in conversion!");
				return *reinterpret_cast<const T*>(m_data + m_layout->Resolve<T>());
			}

		private:
			ConstElementRef(const LayoutElement* layout, const char* data);

		private:
			const LayoutElement* m_layout;
			const char* m_data;
		};

		class ElementRef {
			friend class CPUConstantBuffer;

		public:
			class Ptr {
				friend class ElementRef;

			public:
				template <typename T>
				operator T* () const noxnd {
					static_assert(ReverseLeafMap<std::remove_const_t<T>>::valid, "Unsupported SysType used in pointer conversion!");
					return &static_cast<T&>(*m_ref);
				}
			private:
				Ptr(ElementRef* ref) noexcept;

			private:
				ElementRef* m_ref;
			};

		public:
			bool Exists() const noexcept;

			template<typename S>
			bool SetIfExists(const S& val) noxnd
			{
				if (Exists())
				{
					*this = val;
					return true;
				}
				return false;
			}

			operator ConstElementRef() const noxnd;
			Ptr operator&() noxnd;
			ElementRef operator[](const std::string& key) noxnd;
			ElementRef operator[](size_t index) noxnd;

			template <typename T>
			operator T& () const noxnd {
				static_assert(ReverseLeafMap<std::remove_const_t<T>>::valid, "Unsupported SysType used in conversion!");
				return *reinterpret_cast<T*>(m_data + m_layout->Resolve<T>());
			}

			template <typename T>
			T& operator=(const T& rhs) noxnd {
				static_assert(ReverseLeafMap<std::remove_const_t<T>>::valid, "Unsupported SysType used in assignment!");
				return static_cast<T&>(*this) = rhs;
			}

		private:
			ElementRef(const LayoutElement* layout, char* data);

		private:
			const LayoutElement* m_layout;
			char* m_data;
		};

		class CPUConstantBuffer {
		public:
			CPUConstantBuffer(const Dynamic::Dsr::ConstantEntryPoint& entry);

			ElementRef operator[](const std::string& key) noxnd;
			ConstElementRef operator[](const std::string& key) const noxnd;
			
			inline const char* GetData() const noexcept { return m_data.data(); };
			inline size_t GetSizeInBytes() const noexcept { return m_data.size(); };
			inline LayoutElement& GetRootElement() const noexcept { return *m_root; };
			inline std::shared_ptr<LayoutElement> ShareRootElement() const noexcept { return m_root; };

			void CopyFrom(const CPUConstantBuffer& rhs) noxnd;

		private:
			std::vector<char> m_data;
			std::shared_ptr<LayoutElement> m_root;
		};
	}
}

#ifndef DYNAMIC_CONSTANT_SOURCE_FILE
#undef TYPE_GENERATOR
#endif