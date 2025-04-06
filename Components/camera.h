#ifndef CAMERA_H
#define CAMERA_H

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

// Defines several possible options for camera movement. Used as abstraction to stay away from window-system specific input methods
enum Camera_Movement {
    FORWARD,
    BACKWARD,
    LEFT,
    RIGHT
};

enum CameraType {
    LookAt,
    FirstPerson,
    ThirdPerson
};
// An abstract camera class that processes input and calculates the corresponding Euler Angles, Vectors and Matrices for use in OpenGL
class Camera
{
public:
    glm::vec3 m_position;
    float m_yaw;
    float m_pitch;

    float MovementSpeed = 2.5f;
    float MouseSensitivity = 0.1f;

    float zNear;
    float zFar;
    float fov;

    CameraType type;
    bool isFree = false;

    struct
    {
        glm::mat4 perspective;
        glm::mat4 view;
    } matrices;

    Camera(glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f), float yaw = -90.0f, float pitch = 0.0f, float near = 0.1f, float far = 100.0f, float zoom = 60.0f);

    inline glm::mat4 get_view()
    {
        return matrices.view;
    }

    inline glm::mat4 get_perspective() 
    {
        return matrices.perspective;
    }

    void set_perspective(float zoom, unsigned int width, unsigned int height, float near, float far);
    void set_position(const glm::vec3& pos);

    void translate(const glm::vec3& delta);

    glm::vec3 Front() const;
    glm::vec3 Right() const;
    glm::vec3 Up() const;

    void update_aspect_ratio(unsigned int width, unsigned int height);
    // processes input received from a mouse scroll-wheel event. Only requires input on the vertical wheel-axis
    void ProcessMouseScroll(float yoffset);
    void ProcessKeyboard(Camera_Movement direction, float deltaTime);
    void ProcessMouseMovement(float xoffset, float yoffset, GLboolean constrainPitch = true);

    bool updated = false;

private:
    void updateViewMatrix();
    static const glm::vec3 WorldUp;//世界空间上方向始终保持为(1,0,0)不变
};
#endif