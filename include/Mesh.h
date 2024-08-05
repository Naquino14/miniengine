#include <buffer_objects/ElementBufferObject.h> 
#include <buffer_objects/VertexArrayObject.h>
#include <Texture.h>

#pragma once

class Mesh {
public:
    /// @brief The VAO of the mesh
    VertexArrayObject* vertexArrayObject;

    /// @brief The EBO of the mesh
    ElementBufferObject* elementBufferObject;

    /// @brief The constructor of the mesh
    Mesh(vector<Vertex> vertices, vector<unsigned int> indices, vector<Texture> textures);

    /// @brief The destructor of the mesh
    ~Mesh();

    /// @brief Draw the mesh's vertices
    void Draw();
};