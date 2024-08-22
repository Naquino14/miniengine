#include <Mesh.h>

Mesh::Mesh(vector<Vertex> vertices, vector<unsigned int> indices, vector<Texture> textures) {
    // create vao
    vertexArrayObject = new VertexArrayObject();
    vertexArrayObject->Bind();

    // create vbo
    VertexBufferObject vertexBufferObject(vertices);
    
    // create ebo
    elementBufferObject = new ElementBufferObject(indices);

    vertexArrayObject->LinkAttribute(vertexBufferObject, 0, 3, GL_FLOAT, sizeof(Vertex), nullptr);
    vertexArrayObject->LinkAttribute(vertexBufferObject, 1, 3, GL_FLOAT, sizeof(Vertex), (void*)offsetof(Vertex, normal));
    vertexArrayObject->LinkAttribute(vertexBufferObject, 2, 3, GL_FLOAT, sizeof(Vertex), (void*)offsetof(Vertex, color));
    vertexArrayObject->LinkAttribute(vertexBufferObject, 3, 2, GL_FLOAT, sizeof(Vertex), (void*)offsetof(Vertex, texCoords));

    vertexArrayObject->Unbind();
    vertexBufferObject.Unbind();
    elementBufferObject->Unbind();
}

Mesh::~Mesh() {
    delete vertexArrayObject;
    delete elementBufferObject;
}

void Mesh::Draw() {
    glDrawElements(GL_TRIANGLES, elementBufferObject->GetElementCount(), GL_UNSIGNED_INT, nullptr);
}
