#include <SceneGraph/transform.h>

#include <glm/gtx/matrix_decompose.hpp>

namespace SceneGraph {
	Transform& Transform::SetTranslation(const glm::vec3& translation) {
		m_translation = translation;
		m_is_dirty = true;
		return *this;
	}

	Transform& Transform::SetTranslation(float x, float y, float z) {
		m_translation = glm::vec3(x, y, z);
		m_is_dirty = true;
		return *this;
	}

	Transform& Transform::SetRotation(const glm::quat& quatenion) {
		m_rotation = quatenion;
		m_is_dirty = true;
		return *this;
	}

	//angle是角度
	Transform& Transform::SetRotation(const glm::vec3& axis, float angle) {
		return SetRotation(glm::angleAxis(glm::radians(angle), axis));
	}

	//输入参数为角度
	Transform& Transform::SetRotation(const glm::vec3& axis_angles) {
		return SetRotation(glm::quat(glm::radians(axis_angles)));
	}

	Transform& Transform::SetRotation(float x_angle, float y_angle, float z_angle) {
		return SetRotation(glm::vec3(x_angle, y_angle, z_angle));
	}

	Transform& Transform::SetScale(const glm::vec3& scale) {
		m_scale = scale;
		m_is_dirty = true;
		return *this;
	}

	Transform& Transform::SetScale(float x, float y, float z) {
		return SetScale(glm::vec3(x, y, z));
	}

	const glm::mat4& Transform::GetWorldMatrix() const noexcept {
		return glm::translate(glm::mat4(1.0), m_translation) *
			glm::mat4_cast(m_rotation) *
			glm::scale(glm::mat4(1.0), m_scale);
	}

	void Transform::SetWorldMatrix(const glm::mat4& mat) {
		glm::vec3 skew;
		glm::vec4 perspective;
		glm::decompose(mat, m_scale, m_rotation, m_translation, skew, perspective);

		m_is_dirty = true;
	}
}