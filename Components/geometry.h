#pragma once

#include <vector>
#include <string>
#include <map>
#include <glm/glm.hpp>
#include <functional>
#include <iostream>

#include <nocopyable.h>
#include <glad/glad.h>
#include <init.h>

class Shader;

struct GeometryData
{
    std::vector<glm::vec3> vertices;
    std::vector<glm::vec3> normals;
    std::vector<glm::vec2> texcoords;
    std::vector<glm::vec4> tangents;
    std::vector<uint32_t> indices32;
};

class GeometryBase : private NoCopyable {
public:
    GeometryBase() = default;
    virtual ~GeometryBase();

    void Draw();

    inline void set_model(const glm::mat4& model)
    {
        m_model = model;
    }
    inline glm::mat4 get_model() const
    {
        return m_model;
    }

    inline const GeometryData& get_data() const noexcept { return m_data; }

protected:
    void genBuffers();

    GeometryData m_data;

    glm::mat4 m_model;

    GLuint m_VAO;
    GLuint m_VBO;
    GLuint m_EBO;
};

class Sphere :public GeometryBase {
public:
    Sphere(float radius = 1.0f, uint32_t levels = 20, uint32_t slices = 20);

private:
    GeometryData CreateSphere(float radius = 1.0f, uint32_t levels = 20, uint32_t slices = 20);
};

class Box :public GeometryBase {
public:
    Box(float width = 2.0f, float height = 2.0f, float depth = 2.0f);

private:
    GeometryData CreateBox(float width = 2.0f, float height = 2.0f, float depth = 2.0f);
};

class Cylinder :public GeometryBase {
public:
    Cylinder(float radius = 1.0f, float height = 2.0f, uint32_t slices = 20, uint32_t stacks = 10, float texU = 1.0f, float texV = 1.0f);

private:
    GeometryData CreateCylinder(float radius = 1.0f, float height = 2.0f, uint32_t slices = 20, uint32_t stacks = 10, float texU = 1.0f, float texV = 1.0f);
};

class Cone :public GeometryBase {
public:
    Cone(float radius = 1.0f, float height = 2.0f, uint32_t slices = 20);

private:
    GeometryData CreateCone(float radius = 1.0f, float height = 2.0f, uint32_t slices = 20);
};

class Plane :public GeometryBase {
public:
    Plane(const glm::vec2& planeSize, const glm::vec2& maxTexCoord = { 1.0f, 1.0f });
    Plane(float width = 10.0f, float depth = 10.0f, float texU = 1.0f, float texV = 1.0f);

private:
    GeometryData CreatePlane(const glm::vec2& planeSize, const glm::vec2& maxTexCoord = { 1.0f, 1.0f });
    GeometryData CreatePlane(float width = 10.0f, float depth = 10.0f, float texU = 1.0f, float texV = 1.0f);
};