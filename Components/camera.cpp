#include <camera.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

Camera::Camera(glm::vec3 position, glm::vec3 rotation, float near, float far, float zoom) : Position(position), Rotation(rotation), zNear(near), zFar(far), fov(zoom)
{}

void Camera::ProcessMouseScroll(float yoffset)
{
    fov -= (float)yoffset;
    if (fov < 1.0f)
        fov = 1.0f;
    if (fov > 45.0f)
        fov = 45.0f;

	updated = true;
}

void Camera::set_position(const glm::vec3& pos) {
    Position = pos;
    updateViewMatrix();
}

void Camera::set_rotation(const glm::vec3& rot) {
    Rotation = rot;
    updateViewMatrix();
}

void Camera::set_perspective(float zoom, unsigned int width, unsigned int height, float near, float far) {
	fov = zoom;
	zNear = near;
	zFar = far;
	matrices.perspective = glm::perspective(glm::radians(fov), static_cast<float>(width) / static_cast<float>(height), near, far);
}

void Camera::translate(const glm::vec3& delta) {
	Position += delta;
	updateViewMatrix();
}

void Camera::rotate(const glm::vec3& delta) {
	Rotation += delta;
	updateViewMatrix();
}

void Camera::update_aspect_ratio(unsigned int width, unsigned int height) {
	matrices.perspective = glm::perspective(glm::radians(fov), (float)width / (float)height, zNear, zFar);
	updated = true;
}

void Camera::updateViewMatrix()
{
	glm::mat4 rotation_matrix = glm::mat4(1.0f);
	glm::mat4 transformation_matrix;

	rotation_matrix = glm::rotate(rotation_matrix, glm::radians(Rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
	rotation_matrix = glm::rotate(rotation_matrix, glm::radians(Rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
	rotation_matrix = glm::rotate(rotation_matrix, glm::radians(Rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));

	transformation_matrix = glm::translate(glm::mat4(1.0f), Position);

	if (type == CameraType::FirstPerson)
	{
		matrices.view = rotation_matrix * transformation_matrix;
	}
	else
	{
		matrices.view = transformation_matrix * rotation_matrix;
	}

}