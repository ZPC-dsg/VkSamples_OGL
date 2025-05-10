#pragma once

#include <string>
#include <vector>
#include <unordered_map>
#include <array>
#include <glm/glm.hpp>

#include <assimp/scene.h>

namespace SceneGraph {
	struct TextureInfo {
		enum class MatExtraTextureFlag {
			None,
			Invert,//纹理颜色为1-纹理颜色
			UseAlpha,
			IgnoreAlpha//和UseAlpha互斥
		};

		enum class MatTextureMapMode {
			Wrap,
			Clamp,
			Decal,//If the texture coordinates for a pixel are outside [0...1] the texture is not applied to that pixel.
			Mirror
		};

		enum class MatTextureMapping {//如果纹理本身没有纹理坐标，assimp可以自动生成纹理坐标，该枚举指定坐标生成的映射方式
			None,//纹理本身有坐标
			Sphere,
			Cylinder,
			Box,
			Plane,
			Other
		};

		enum class MatTextureOp {//决定当前纹理怎么和之前层生成的颜色结合，例子参考https://documentation.help/assimp/material_8h.html#a204a0a39264125e160bd8fb2117f06e9
			Multiply,
			Add,
			Subtract,
			Divide,
			SmoothAdd,
			SignedAdd
		};

		std::string m_path;

		float m_strength = 1.0;//纹理颜色强度，在进行任何下一步的处理之前需要将读取的纹理颜色首先乘以这个强度
		int m_uv_channel = -1;//-1代表没有自己的uv channel，要么整个模型只有一个uv坐标系统，要么该纹理没有指定使用哪个坐标系统，此时直接按照它的序号来决定

		float m_uvtransform_rotate = 0.0;
		glm::vec2 m_uvtransform_scale = glm::vec2(1.0);
		glm::vec2 m_uvtransform_translate = glm::vec2(0.0);

		MatExtraTextureFlag m_textureflag = MatExtraTextureFlag::None;
		std::array<MatTextureMapMode, 2> m_wrapmode = { MatTextureMapMode::Clamp,MatTextureMapMode::Clamp };//xy各自的map mode
		MatTextureOp m_textureop = MatTextureOp::Add;
		MatTextureMapping m_mapping = MatTextureMapping::None;

		static std::unordered_map<aiTextureFlags, MatExtraTextureFlag> m_flagmap;
		static std::unordered_map<aiTextureMapMode, MatTextureMapMode> m_mapmodemap;
		static std::unordered_map<aiTextureMapping, MatTextureMapping> m_mappingmap;
		static std::unordered_map<aiTextureOp, MatTextureOp> m_opmap;
	};

	struct ExtraProperties {
		enum class MatBlendMode {
			None,
			Default,//srccolor * alpha + dstcolor * (1 - alpha)
			Additive//srccolor * 1 + dstcolor * 1
		};

		enum class MatShadingMode {//具体含义参考https://documentation.help/assimp/material_8h.html#a204a0a39264125e160bd8fb2117f06e9
			Flat,
			Gouraud,
			Phong,
			Blinn,
			Toon,
			OrenNayar,
			Minnaert,
			CookTorrance,
			NoShading,
			Fresnel,
			PBR,
			Unlit
		};

		MatBlendMode m_blendmode = MatBlendMode::None;
		MatShadingMode m_shadingmode = MatShadingMode::Blinn;

		glm::vec3 m_diffuse = glm::vec3(0.0);
		glm::vec3 m_specular = glm::vec3(0.0);
		glm::vec3 m_ambient = glm::vec3(0.0);
		glm::vec3 m_emissive = glm::vec3(0.0);
		glm::vec3 m_transparent = glm::vec3(0.0);//材质透明色，如果场景中有半透明光，需要用这个颜色乘以光的颜色

		bool m_is_twosided = true;//渲染材质时是否需要禁用背面剔除

		float m_opacity = 1.0;
		float m_shininess = 1.0;//phong光照模型中镜面反射项的幂次系数
		float m_shininess_strength = 1.0;//放缩镜面反射的颜色强度

		static std::unordered_map<aiBlendMode, MatBlendMode> m_blendmodemap;
		static std::unordered_map<aiShadingMode, MatShadingMode> m_shadingmap;
	};

	class Material {
	public:
		enum TextureCategory {
			DIFFUSE,
			SPECULAR,
			AMBIENT,
			EMISSIVE,
			HEIGHT,
			NORMAL,
			SHININESS,
			OPACITY,
			DISPLACEMENT,
			LIGHTMAP,
			REFLECTION
		};

		Material(const std::string& name);
		~Material() = default;

		void AddTexture(TextureCategory type, TextureInfo info);

		inline Material& SetBlendMode(ExtraProperties::MatBlendMode mode) { m_extras.m_blendmode = mode; return *this; };
		inline Material& SetShadingMode(ExtraProperties::MatShadingMode mode) { m_extras.m_shadingmode = mode; return *this; };
		inline Material& SetDiffuse(glm::vec3 diff) { m_extras.m_diffuse = diff; return *this; };
		inline Material& SetDiffuse(float x, float y, float z) { return SetDiffuse(glm::vec3(x, y, z)); };
		inline Material& SetSpecular(glm::vec3 spec) { m_extras.m_specular = spec; return *this; };
		inline Material& SetSpecular(float x, float y, float z) { return SetSpecular(glm::vec3(x, y, z)); };
		inline Material& SetAmbient(glm::vec3 amb) { m_extras.m_ambient = amb; return *this; };
		inline Material& SetAmbient(float x, float y, float z) { return SetAmbient(glm::vec3(x, y, z)); };
		inline Material& SetEmissive(glm::vec3 emi) { m_extras.m_emissive = emi; return *this; };
		inline Material& SetEmissive(float x, float y, float z) { return SetEmissive(glm::vec3(x, y, z)); };
		inline Material& SetTransparent(glm::vec3 trans) { m_extras.m_transparent = trans; return *this; };
		inline Material& SetTransparent(float x, float y, float z) { return SetTransparent(glm::vec3(x, y, z)); };
		inline Material& SetTwoSided(bool two) { m_extras.m_is_twosided = two; return *this; };
		inline Material& SetOpacity(float opa) { m_extras.m_opacity = opa; return *this; };
		inline Material& SetShininess(float shin) { m_extras.m_shininess = shin; return *this; };
		inline Material& SetShiniStength(float stren) { m_extras.m_shininess_strength = stren; return *this; };

		inline bool HasTextureType(TextureCategory type) const noexcept { return m_textures.contains(type); };

		const std::vector<TextureInfo>& GetTextures(TextureCategory type) const;
		const TextureInfo& GetTexture(TextureCategory type, size_t index) const;

		inline const std::string& GetName() const noexcept { return m_name; };
		inline const ExtraProperties& GetExtraInformation() const noexcept { return m_extras; };

	private:
		std::string m_name;

		std::unordered_map<TextureCategory, std::vector<TextureInfo>> m_textures;
		ExtraProperties m_extras;
	};

	template <typename Enum>
	typename std::enable_if<std::is_enum<Enum>::value, Enum>::type operator|(Enum a, Enum b) {
		using underlying = typename std::underlying_type<Enum>::type;
		return static_cast<Enum>(static_cast<underlying>(a) | static_cast<underlying>(b));
	}

	template <typename Enum>
	typename std::enable_if<std::is_enum<Enum>::value, Enum>::type& operator|=(Enum& a, Enum b) {
		using underlying = typename std::underlying_type<Enum>::type;
		a = static_cast<Enum>(static_cast<underlying>(a) | static_cast<underlying>(b));
		return a;
	}
}