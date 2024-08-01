#include <buffer_objects/IBufferObject.h>
#include <buffer_objects/VertexBufferObject.h>

#pragma once

class VertexArrayObject : public IBufferObject {
public:
    /// @brief Creates a Vertex Array Object (VAO)
    VertexArrayObject();

    /// @brief Links a VBO to the VAO
    /// @param VBO The VBO to link
    /// @param layout The layout number of the VBO
    /// @param numComponents The number of components in the VBO
    /// @param type The data type of the VBO
    /// @param stride The byte offset between consecutive generic vertex attributes
    /// @param offset The offset of the first component of the first vertex attribute in the array
    void LinkAttribute(VertexBufferObject& VBO, unsigned int layout, unsigned int numComponents, GLenum type, unsigned int stride, void* offset);

    /// @brief Binds the VAO
    void Bind() override;

    /// @brief Unbinds the VAO
    void Unbind() override;

    /// @brief Deletes the VAO
    void Delete() override;
};