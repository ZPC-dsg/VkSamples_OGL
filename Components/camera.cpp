#include <camera.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

const glm::vec3 Camera::WorldUp = glm::vec3(0.0, 1.0, 0.0);

Camera::Camera(glm::vec3 position, float yaw, float pitch, float near, float far, float zoom) : m_position(position), m_yaw(yaw), m_pitch(pitch),
zNear(near), zFar(far), fov(zoom)
{
}

void Camera::ProcessMouseScroll(float yoffset)
{
    fov -= (float)yoffset;
    if (fov < 1.0f)
        fov = 1.0f;
    if (fov > 45.0f)
        fov = 45.0f;

    updated = true;
}

void Camera::ProcessKeyboard(Camera_Movement direction, float deltaTime)
{
    float velocity = MovementSpeed * deltaTime;
    if (direction == FORWARD)
        m_position += Front() * velocity;
    if (direction == BACKWARD)
        m_position -= Front() * velocity;
    if (direction == LEFT)
        m_position -= Right() * velocity;
    if (direction == RIGHT)
        m_position += Right() * velocity;

    updateViewMatrix();
}

void Camera::ProcessMouseMovement(float xoffset, float yoffset, GLboolean constrainPitch)
{
    xoffset *= MouseSensitivity;
    yoffset *= MouseSensitivity;

    m_yaw += xoffset;
    m_pitch += yoffset;

    if (constrainPitch)
    {
        if (m_pitch > 89.0f)
            m_pitch = 89.0f;
        if (m_pitch < -89.0f)
            m_pitch = -89.0f;
    }

    updateViewMatrix();
}

void Camera::set_position(const glm::vec3& pos) {
    m_position = pos;
    updateViewMatrix();
}

void Camera::set_perspective(float zoom, unsigned int width, unsigned int height, float near, float far) {
    fov = zoom;
    zNear = near;
    zFar = far;
    matrices.perspective = glm::perspective(glm::radians(fov), static_cast<float>(width) / static_cast<float>(height), near, far);
}

void Camera::translate(const glm::vec3& delta) {
    m_position += delta;
    updateViewMatrix();
}

void Camera::update_aspect_ratio(unsigned int width, unsigned int height) {
    matrices.perspective = glm::perspective(glm::radians(fov), (float)width / (float)height, zNear, zFar);
    updated = true;
}

void Camera::updateViewMatrix()
{
    matrices.view = glm::lookAt(m_position, Front() + m_position, Up());
}

glm::vec3 Camera::Front() const
{
    glm::vec3 front;
    front.x = cos(glm::radians(m_yaw)) * cos(glm::radians(m_pitch));
    front.y = sin(glm::radians(m_pitch));
    front.z = sin(glm::radians(m_yaw)) * cos(glm::radians(m_pitch));

    return glm::normalize(front);
}

glm::vec3 Camera::Right() const
{
    if (m_pitch > 89.0f || m_pitch < -89.0f) {
        return glm::vec3(1.0, 0.0, 0.0);
    }

    return glm::normalize(glm::cross(Front(), WorldUp));
}

glm::vec3 Camera::Up() const
{
    return glm::normalize(glm::cross(Right(), Front()));
}