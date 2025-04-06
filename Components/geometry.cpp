#include <geometry.h>

void GeometryBase::Draw() {
    glBindVertexArray(m_VAO);
    if (m_data.indices32.size()) {
        glDrawElements(GL_TRIANGLES, m_data.indices32.size(), GL_UNSIGNED_INT, 0);
    }
    else {
        throw std::runtime_error("Vertex data failed to generate properly!");
    }
    glBindVertexArray(0);
}

void GeometryBase::genBuffers() {
    glGenVertexArrays(1, &m_VAO); 
    glBindVertexArray(m_VAO);

    glGenBuffers(1, &m_VBO);
    glGenBuffers(1, &m_EBO);
    glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
    glBufferData(GL_ARRAY_BUFFER, m_data.vertices.size() * (2 * sizeof(glm::vec3) + sizeof(glm::vec2) + sizeof(glm::vec4)), NULL, GL_STATIC_DRAW);

    int offset = 0;
    glBufferSubData(GL_ARRAY_BUFFER, offset, sizeof(glm::vec3) * m_data.vertices.size(), m_data.vertices.data());
    offset += sizeof(glm::vec3) * m_data.vertices.size();
    glBufferSubData(GL_ARRAY_BUFFER, offset, sizeof(glm::vec3) * m_data.normals.size(), m_data.normals.data());
    offset += sizeof(glm::vec3) * m_data.normals.size();
    glBufferSubData(GL_ARRAY_BUFFER, offset, sizeof(glm::vec2) * m_data.texcoords.size(), m_data.texcoords.data());
    offset += sizeof(glm::vec2) * m_data.texcoords.size();
    glBufferSubData(GL_ARRAY_BUFFER, offset, sizeof(glm::vec4) * m_data.tangents.size(), m_data.tangents.data());

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO);
    if (m_data.indices32.size()) {
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(uint32_t) * m_data.indices32.size(), m_data.indices32.data(), GL_STATIC_DRAW);
    }

    offset = 0;
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(glm::vec3), (void*)0);
    offset += sizeof(glm::vec3) * m_data.vertices.size();
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(glm::vec3), (void*)offset);
    offset += sizeof(glm::vec3) * m_data.normals.size();
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(glm::vec2), (void*)offset);
    offset += sizeof(glm::vec2) * m_data.texcoords.size();
    glEnableVertexAttribArray(3);
    glVertexAttribPointer(3, 4, GL_FLOAT, GL_FALSE, sizeof(glm::vec4), (void*)offset);

    glBindVertexArray(0);
}

GeometryBase::~GeometryBase() {
    glBindVertexArray(0);
    glDeleteVertexArrays(1, &m_VAO);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glDeleteBuffers(1, &m_VBO);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    glDeleteBuffers(1, &m_EBO);
}

Sphere::Sphere(float radius, uint32_t levels, uint32_t slices) {
    m_data = CreateSphere(radius, levels, slices);
    genBuffers();
}

GeometryData Sphere::CreateSphere(float radius, uint32_t levels, uint32_t slices)
{
    GeometryData geoData;

    uint32_t vertexCount = 2 + (levels - 1) * (slices + 1);
    uint32_t indexCount = 6 * (levels - 1) * slices;
    geoData.vertices.resize(vertexCount);
    geoData.normals.resize(vertexCount);
    geoData.texcoords.resize(vertexCount);
    geoData.tangents.resize(vertexCount);
    geoData.indices32.resize(indexCount);

    uint32_t vIndex = 0, iIndex = 0;

    float phi = 0.0f, theta = 0.0f;
    float per_phi = glm::pi<float>() / levels;
    float per_theta = 2 * glm::pi<float>() / slices;
    float x, y, z;

    // 放入顶端点
    geoData.vertices[vIndex] = glm::vec3(0.0f, radius, 0.0f);
    geoData.normals[vIndex] = glm::vec3(0.0f, 1.0f, 0.0f);
    geoData.tangents[vIndex] = glm::vec4(1.0f, 0.0f, 0.0f, 1.0f);
    geoData.texcoords[vIndex++] = glm::vec2(0.0f, 0.0f);


    for (uint32_t i = 1; i < levels; ++i)
    {
        phi = per_phi * i;
        // 需要slices + 1个顶点是因为 起点和终点需为同一点，但纹理坐标值不一致
        for (uint32_t j = 0; j <= slices; ++j)
        {
            theta = per_theta * j;
            x = radius * sinf(phi) * cosf(theta);
            y = radius * cosf(phi);
            z = radius * sinf(phi) * sinf(theta);
            // 计算出局部坐标、法向量、Tangent向量和纹理坐标
            glm::vec3 pos(x, y, z);

            geoData.vertices[vIndex] = pos;
            geoData.normals[vIndex] = glm::normalize(pos);
            geoData.tangents[vIndex] = glm::vec4(-sinf(theta), 0.0f, cosf(theta), 1.0f);
            geoData.texcoords[vIndex++] = glm::vec2(theta / 2 / glm::pi<float>(), phi / glm::pi<float>());
        }
    }

    // 放入底端点
    geoData.vertices[vIndex] = glm::vec3(0.0f, -radius, 0.0f);
    geoData.normals[vIndex] = glm::vec3(0.0f, -1.0f, 0.0f);
    geoData.tangents[vIndex] = glm::vec4(-1.0f, 0.0f, 0.0f, 1.0f);
    geoData.texcoords[vIndex++] = glm::vec2(0.0f, 1.0f);


    // 放入索引
    if (levels > 1)
    {
        for (uint32_t j = 1; j <= slices; ++j)
        {
            geoData.indices32[iIndex++] = 0;
            geoData.indices32[iIndex++] = j % (slices + 1) + 1;
            geoData.indices32[iIndex++] = j;
        }
    }


    for (uint32_t i = 1; i < levels - 1; ++i)
    {
        for (uint32_t j = 1; j <= slices; ++j)
        {
            geoData.indices32[iIndex++] = (i - 1) * (slices + 1) + j;
            geoData.indices32[iIndex++] = (i - 1) * (slices + 1) + j % (slices + 1) + 1;
            geoData.indices32[iIndex++] = i * (slices + 1) + j % (slices + 1) + 1;

            geoData.indices32[iIndex++] = i * (slices + 1) + j % (slices + 1) + 1;
            geoData.indices32[iIndex++] = i * (slices + 1) + j;
            geoData.indices32[iIndex++] = (i - 1) * (slices + 1) + j;
        }
    }

    // 逐渐放入索引
    if (levels > 1)
    {
        for (uint32_t j = 1; j <= slices; ++j)
        {
            geoData.indices32[iIndex++] = (levels - 2) * (slices + 1) + j;
            geoData.indices32[iIndex++] = (levels - 2) * (slices + 1) + j % (slices + 1) + 1;
            geoData.indices32[iIndex++] = (levels - 1) * (slices + 1) + 1;
        }
    }

    return geoData;
}

Box::Box(float width, float height, float depth) {
    m_data = CreateBox(width, height, depth);
    genBuffers();
}

GeometryData Box::CreateBox(float width, float height, float depth)
{
    GeometryData geoData;

    geoData.vertices.resize(24);
    geoData.normals.resize(24);
    geoData.tangents.resize(24);
    geoData.texcoords.resize(24);

    float w2 = width / 2, h2 = height / 2, d2 = depth / 2;

    // 右面(+X面)
    geoData.vertices[0] = glm::vec3(w2, -h2, -d2);
    geoData.vertices[1] = glm::vec3(w2, h2, -d2);
    geoData.vertices[2] = glm::vec3(w2, h2, d2);
    geoData.vertices[3] = glm::vec3(w2, -h2, d2);
    // 左面(-X面)
    geoData.vertices[4] = glm::vec3(-w2, -h2, d2);
    geoData.vertices[5] = glm::vec3(-w2, h2, d2);
    geoData.vertices[6] = glm::vec3(-w2, h2, -d2);
    geoData.vertices[7] = glm::vec3(-w2, -h2, -d2);
    // 顶面(+Y面)
    geoData.vertices[8] = glm::vec3(-w2, h2, -d2);
    geoData.vertices[9] = glm::vec3(-w2, h2, d2);
    geoData.vertices[10] = glm::vec3(w2, h2, d2);
    geoData.vertices[11] = glm::vec3(w2, h2, -d2);
    // 底面(-Y面)
    geoData.vertices[12] = glm::vec3(w2, -h2, -d2);
    geoData.vertices[13] = glm::vec3(w2, -h2, d2);
    geoData.vertices[14] = glm::vec3(-w2, -h2, d2);
    geoData.vertices[15] = glm::vec3(-w2, -h2, -d2);
    // 背面(+Z面)
    geoData.vertices[16] = glm::vec3(w2, -h2, d2);
    geoData.vertices[17] = glm::vec3(w2, h2, d2);
    geoData.vertices[18] = glm::vec3(-w2, h2, d2);
    geoData.vertices[19] = glm::vec3(-w2, -h2, d2);
    // 正面(-Z面)
    geoData.vertices[20] = glm::vec3(-w2, -h2, -d2);
    geoData.vertices[21] = glm::vec3(-w2, h2, -d2);
    geoData.vertices[22] = glm::vec3(w2, h2, -d2);
    geoData.vertices[23] = glm::vec3(w2, -h2, -d2);

    for (size_t i = 0; i < 4; ++i)
    {
        // 右面(+X面)
        geoData.normals[i] = glm::vec3(1.0f, 0.0f, 0.0f);
        geoData.tangents[i] = glm::vec4(0.0f, 0.0f, 1.0f, 1.0f);
        // 左面(-X面)
        geoData.normals[i + 4] = glm::vec3(-1.0f, 0.0f, 0.0f);
        geoData.tangents[i + 4] = glm::vec4(0.0f, 0.0f, -1.0f, 1.0f);
        // 顶面(+Y面)
        geoData.normals[i + 8] = glm::vec3(0.0f, 1.0f, 0.0f);
        geoData.tangents[i + 8] = glm::vec4(1.0f, 0.0f, 0.0f, 1.0f);
        // 底面(-Y面)
        geoData.normals[i + 12] = glm::vec3(0.0f, -1.0f, 0.0f);
        geoData.tangents[i + 12] = glm::vec4(-1.0f, 0.0f, 0.0f, 1.0f);
        // 背面(+Z面)
        geoData.normals[i + 16] = glm::vec3(0.0f, 0.0f, 1.0f);
        geoData.tangents[i + 16] = glm::vec4(-1.0f, 0.0f, 0.0f, 1.0f);
        // 正面(-Z面)
        geoData.normals[i + 20] = glm::vec3(0.0f, 0.0f, -1.0f);
        geoData.tangents[i + 20] = glm::vec4(1.0f, 0.0f, 0.0f, 1.0f);
    }

    for (size_t i = 0; i < 6; ++i)
    {
        geoData.texcoords[i * 4] = glm::vec2(0.0f, 1.0f);
        geoData.texcoords[i * 4 + 1] = glm::vec2(0.0f, 0.0f);
        geoData.texcoords[i * 4 + 2] = glm::vec2(1.0f, 0.0f);
        geoData.texcoords[i * 4 + 3] = glm::vec2(1.0f, 1.0f);
    }

    geoData.indices32.resize(36);

    uint16_t indices[] = {
        0, 1, 2, 2, 3, 0,		// 右面(+X面)
        4, 5, 6, 6, 7, 4,		// 左面(-X面)
        8, 9, 10, 10, 11, 8,	// 顶面(+Y面)
        12, 13, 14, 14, 15, 12,	// 底面(-Y面)
        16, 17, 18, 18, 19, 16, // 背面(+Z面)
        20, 21, 22, 22, 23, 20	// 正面(-Z面)
    };
    geoData.indices32 = std::vector<uint32_t>(indices, indices + 36);

    return geoData;
}

Cylinder::Cylinder(float radius, float height, uint32_t slices, uint32_t stacks, float texU, float texV) {
    m_data = CreateCylinder(radius, height, slices, stacks, texU, texV);
    genBuffers();
}

GeometryData Cylinder::CreateCylinder(float radius, float height, uint32_t slices, uint32_t stacks, float texU, float texV)
{
    GeometryData geoData;
    uint32_t vertexCount = (slices + 1) * (stacks + 3) + 2;
    uint32_t indexCount = 6 * slices * (stacks + 1);

    geoData.vertices.resize(vertexCount);
    geoData.normals.resize(vertexCount);
    geoData.tangents.resize(vertexCount);
    geoData.texcoords.resize(vertexCount);
    geoData.indices32.resize(indexCount);

    float h2 = height / 2;
    float theta = 0.0f;
    float per_theta = 2 * glm::pi<float>() / slices;
    float stackHeight = height / stacks;
    //
    // 侧面部分
    //
    {
        // 自底向上铺设侧面端点
        size_t vIndex = 0;
        for (size_t i = 0; i < stacks + 1; ++i)
        {
            float y = -h2 + i * stackHeight;
            // 当前层顶点
            for (size_t j = 0; j <= slices; ++j)
            {
                theta = j * per_theta;
                float u = theta / 2 / glm::pi<float>();
                float v = 1.0f - (float)i / stacks;

                geoData.vertices[vIndex] = glm::vec3(radius * cosf(theta), y, radius * sinf(theta)), glm::vec3(cosf(theta), 0.0f, sinf(theta));
                geoData.normals[vIndex] = glm::vec3(cosf(theta), 0.0f, sinf(theta));
                geoData.tangents[vIndex] = glm::vec4(-sinf(theta), 0.0f, cosf(theta), 1.0f);
                geoData.texcoords[vIndex++] = glm::vec2(u * texU, v * texV);
            }
        }

        // 放入索引
        size_t iIndex = 0;
        for (uint32_t i = 0; i < stacks; ++i)
        {
            for (uint32_t j = 0; j < slices; ++j)
            {
                geoData.indices32[iIndex++] = i * (slices + 1) + j;
                geoData.indices32[iIndex++] = (i + 1) * (slices + 1) + j;
                geoData.indices32[iIndex++] = (i + 1) * (slices + 1) + j + 1;

                geoData.indices32[iIndex++] = i * (slices + 1) + j;
                geoData.indices32[iIndex++] = (i + 1) * (slices + 1) + j + 1;
                geoData.indices32[iIndex++] = i * (slices + 1) + j + 1;
            }
        }
    }

    //
    // 顶盖底盖部分
    //
    {
        size_t vIndex = (slices + 1) * (stacks + 1), iIndex = 6 * slices * stacks;
        uint32_t offset = static_cast<uint32_t>(vIndex);

        // 放入顶端圆心
        geoData.vertices[vIndex] = glm::vec3(0.0f, h2, 0.0f);
        geoData.normals[vIndex] = glm::vec3(0.0f, 1.0f, 0.0f);
        geoData.tangents[vIndex] = glm::vec4(1.0f, 0.0f, 0.0f, 1.0f);
        geoData.texcoords[vIndex++] = glm::vec2(0.5f, 0.5f);

        // 放入顶端圆上各点
        for (uint32_t i = 0; i <= slices; ++i)
        {
            theta = i * per_theta;
            float u = cosf(theta) * radius / height + 0.5f;
            float v = sinf(theta) * radius / height + 0.5f;
            geoData.vertices[vIndex] = glm::vec3(radius * cosf(theta), h2, radius * sinf(theta));
            geoData.normals[vIndex] = glm::vec3(0.0f, 1.0f, 0.0f);
            geoData.tangents[vIndex] = glm::vec4(1.0f, 0.0f, 0.0f, 1.0f);
            geoData.texcoords[vIndex++] = glm::vec2(u, v);
        }

        // 放入底端圆心
        geoData.vertices[vIndex] = glm::vec3(0.0f, -h2, 0.0f);
        geoData.normals[vIndex] = glm::vec3(0.0f, -1.0f, 0.0f);
        geoData.tangents[vIndex] = glm::vec4(-1.0f, 0.0f, 0.0f, 1.0f);
        geoData.texcoords[vIndex++] = glm::vec2(0.5f, 0.5f);

        // 放入底部圆上各点
        for (uint32_t i = 0; i <= slices; ++i)
        {
            theta = i * per_theta;
            float u = cosf(theta) * radius / height + 0.5f;
            float v = sinf(theta) * radius / height + 0.5f;
            geoData.vertices[vIndex] = glm::vec3(radius * cosf(theta), -h2, radius * sinf(theta));
            geoData.normals[vIndex] = glm::vec3(0.0f, -1.0f, 0.0f);
            geoData.tangents[vIndex] = glm::vec4(-1.0f, 0.0f, 0.0f, 1.0f);
            geoData.texcoords[vIndex++] = glm::vec2(u, v);
        }


        // 放入顶部三角形索引
        for (uint32_t i = 1; i <= slices; ++i)
        {
            geoData.indices32[iIndex++] = offset;
            geoData.indices32[iIndex++] = offset + i % (slices + 1) + 1;
            geoData.indices32[iIndex++] = offset + i;
        }

        // 放入底部三角形索引
        offset += slices + 2;
        for (uint32_t i = 1; i <= slices; ++i)
        {
            geoData.indices32[iIndex++] = offset;
            geoData.indices32[iIndex++] = offset + i;
            geoData.indices32[iIndex++] = offset + i % (slices + 1) + 1;
        }
    }


    return geoData;
}

Cone::Cone(float radius, float height, uint32_t slices) {
    m_data = CreateCone(radius, height, slices);
    genBuffers();
}

GeometryData Cone::CreateCone(float radius, float height, uint32_t slices)
{
    GeometryData geoData;

    uint32_t vertexCount = 3 * slices + 1;
    uint32_t indexCount = 6 * slices;
    geoData.vertices.resize(vertexCount);
    geoData.normals.resize(vertexCount);
    geoData.tangents.resize(vertexCount);
    geoData.texcoords.resize(vertexCount);
    geoData.indices32.resize(indexCount);

    float h2 = height / 2;
    float theta = 0.0f;
    float per_theta = 2 * glm::pi<float>() / slices;
    float len = sqrtf(height * height + radius * radius);

    //
    // 圆锥侧面
    //
    {
        size_t iIndex = 0;
        size_t vIndex = 0;

        // 放入圆锥尖端顶点(每个顶点位置相同，但包含不同的法向量和切线向量)
        for (uint32_t i = 0; i < slices; ++i)
        {
            theta = i * per_theta + per_theta / 2;
            geoData.vertices[vIndex] = glm::vec3(0.0f, h2, 0.0f);
            geoData.normals[vIndex] = glm::vec3(radius * cosf(theta) / len, height / len, radius * sinf(theta) / len);
            geoData.tangents[vIndex] = glm::vec4(-sinf(theta), 0.0f, cosf(theta), 1.0f);
            geoData.texcoords[vIndex++] = glm::vec2(0.5f, 0.5f);
        }

        // 放入圆锥侧面底部顶点
        for (uint32_t i = 0; i < slices; ++i)
        {
            theta = i * per_theta;
            geoData.vertices[vIndex] = glm::vec3(radius * cosf(theta), -h2, radius * sinf(theta));
            geoData.normals[vIndex] = glm::vec3(radius * cosf(theta) / len, height / len, radius * sinf(theta) / len);
            geoData.tangents[vIndex] = glm::vec4(-sinf(theta), 0.0f, cosf(theta), 1.0f);
            geoData.texcoords[vIndex++] = glm::vec2(cosf(theta) / 2 + 0.5f, sinf(theta) / 2 + 0.5f);
        }

        // 放入索引
        for (uint32_t i = 0; i < slices; ++i)
        {
            geoData.indices32[iIndex++] = i;
            geoData.indices32[iIndex++] = slices + (i + 1) % slices;
            geoData.indices32[iIndex++] = slices + i % slices;
        }
    }

    //
    // 圆锥底面
    //
    {
        size_t iIndex = 3 * (size_t)slices;
        size_t vIndex = 2 * (size_t)slices;

        // 放入圆锥底面顶点
        for (uint32_t i = 0; i < slices; ++i)
        {
            theta = i * per_theta;

            geoData.vertices[vIndex] = glm::vec3(radius * cosf(theta), -h2, radius * sinf(theta)),
                geoData.normals[vIndex] = glm::vec3(0.0f, -1.0f, 0.0f);
            geoData.tangents[vIndex] = glm::vec4(-1.0f, 0.0f, 0.0f, 1.0f);
            geoData.texcoords[vIndex++] = glm::vec2(cosf(theta) / 2 + 0.5f, sinf(theta) / 2 + 0.5f);
        }
        // 放入圆锥底面圆心
        geoData.vertices[vIndex] = glm::vec3(0.0f, -h2, 0.0f),
            geoData.normals[vIndex] = glm::vec3(0.0f, -1.0f, 0.0f);
        geoData.texcoords[vIndex++] = glm::vec2(0.5f, 0.5f);

        // 放入索引
        uint32_t offset = 2 * slices;
        for (uint32_t i = 0; i < slices; ++i)
        {
            geoData.indices32[iIndex++] = offset + slices;
            geoData.indices32[iIndex++] = offset + i % slices;
            geoData.indices32[iIndex++] = offset + (i + 1) % slices;
        }
    }


    return geoData;
}

Plane::Plane(float width, float depth, float texU, float texV) {
    m_data = CreatePlane(width, depth, texU, texV);
    genBuffers();
}

Plane::Plane(const glm::vec2& planeSize, const glm::vec2& maxTexCoord) {
    m_data = CreatePlane(planeSize, maxTexCoord);
    genBuffers();
}

GeometryData Plane::CreatePlane(const glm::vec2& planeSize, const glm::vec2& maxTexCoord)
{
    return CreatePlane(planeSize.x, planeSize.y, maxTexCoord.x, maxTexCoord.y);
}

GeometryData Plane::CreatePlane(float width, float depth, float texU, float texV)
{
    GeometryData geoData;

    geoData.vertices.resize(4);
    geoData.normals.resize(4);
    geoData.tangents.resize(4);
    geoData.texcoords.resize(4);


    uint32_t vIndex = 0;
    geoData.vertices[vIndex] = glm::vec3(-width / 2, 0.0f, -depth / 2);
    geoData.normals[vIndex] = glm::vec3(0.0f, 1.0f, 0.0f);
    geoData.tangents[vIndex] = glm::vec4(1.0f, 0.0f, 0.0f, 1.0f);
    geoData.texcoords[vIndex++] = glm::vec2(0.0f, texV);

    geoData.vertices[vIndex] = glm::vec3(-width / 2, 0.0f, depth / 2);
    geoData.normals[vIndex] = glm::vec3(0.0f, 1.0f, 0.0f);
    geoData.tangents[vIndex] = glm::vec4(1.0f, 0.0f, 0.0f, 1.0f);
    geoData.texcoords[vIndex++] = glm::vec2(0.0f, 0.0f);

    geoData.vertices[vIndex] = glm::vec3(width / 2, 0.0f, depth / 2);
    geoData.normals[vIndex] = glm::vec3(0.0f, 1.0f, 0.0f);
    geoData.tangents[vIndex] = glm::vec4(1.0f, 0.0f, 0.0f, 1.0f);
    geoData.texcoords[vIndex++] = glm::vec2(texU, 0.0f);

    geoData.vertices[vIndex] = glm::vec3(width / 2, 0.0f, -depth / 2);
    geoData.normals[vIndex] = glm::vec3(0.0f, 1.0f, 0.0f);
    geoData.tangents[vIndex] = glm::vec4(1.0f, 0.0f, 0.0f, 1.0f);
    geoData.texcoords[vIndex++] = glm::vec2(texU, texV);

    geoData.indices32 = { 0, 1, 2, 2, 3, 0 };

    return geoData;
}