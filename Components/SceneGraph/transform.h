#pragma once

#define GLM_ENABLE_EXPERIMENTAL

#include <glm/glm.hpp>
#include <glm/gtx/rotate_vector.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtx/quaternion.hpp>

namespace SceneGraph {
	class Transform {
	public:
		Transform() = default;
		~Transform() = default;

		Transform& SetTranslation(const glm::vec3& translation);
		Transform& SetTranslation(float x, float y, float z);
		Transform& SetRotation(const glm::quat& quatenion);
		Transform& SetRotation(const glm::vec3& axis, float angle);
		Transform& SetRotation(const glm::vec3& axis_angles);//按照x-y-z的顺序设置旋转角
		Transform& SetRotation(float x_angle, float y_angle, float z_angle);
		Transform& SetScale(const glm::vec3& scale);
		Transform& SetScale(float x, float y, float z);

		inline const glm::vec3& GetTranslation() const noexcept { return m_translation; };
		inline const glm::quat& GetRotationQuat() const noexcept { return m_rotation; };
		inline const glm::vec3& GetScale() const noexcept { return m_scale; };

		void SetWorldMatrix(const glm::mat4& mat);
		const glm::mat4& GetWorldMatrix() const noexcept;

		inline bool IsDirty() const noexcept { return m_is_dirty; };
		inline void SetDirtyFlag(bool is_dirty) noexcept { m_is_dirty = is_dirty; };

	private:
		glm::vec3 m_translation = glm::vec3(0.0, 0.0, 0.0);
		glm::quat m_rotation = glm::quat(0.0, 0.0, 0.0, 0.0);
		glm::vec3 m_scale = glm::vec3(1.0, 1.0, 1.0);

		bool m_is_dirty = false;
	};
}