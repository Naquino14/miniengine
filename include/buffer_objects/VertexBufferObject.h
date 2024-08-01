#include <buffer_objects/IBufferObject.h>

#pragma once

/// @brief Vertex structure, contains position, normal, and texture coordinates.
struct Vertex {
    vec3 position;
    vec3 normal;
    // vec3 color;
    vec2 texCoords;
};

class VertexBufferObject : public IBufferObject {
public:
    /// @brief Creates a VBO with the given vertices
    /// @param vertices The vertices array to copy into the VBO
    VertexBufferObject(vector<Vertex> vertices);

    /// @brief Binds the VBO
    void Bind() override;

    /// @brief Unbinds the VBO
    void Unbind() override;

    /// @brief Deletes the VBO
    void Delete() override;
};