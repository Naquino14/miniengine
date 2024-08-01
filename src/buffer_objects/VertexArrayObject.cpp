#include <buffer_objects/VertexArrayObject.h>

VertexArrayObject::VertexArrayObject() {
    glGenVertexArrays(1, &ID);
}

void VertexArrayObject::LinkAttribute(VertexBufferObject& VBO, unsigned int layout, unsigned int numComponents, GLenum type, unsigned int stride, void* offset) {
    VBO.Bind();
    glVertexAttribPointer(layout, numComponents, type, GL_FALSE, stride, offset);
    glEnableVertexAttribArray(layout);
    VBO.Unbind();
}

void VertexArrayObject::Bind() {
    glBindVertexArray(ID);
}

void VertexArrayObject::Unbind() {
    glBindVertexArray(0);
}

void VertexArrayObject::Delete() {
    glDeleteVertexArrays(1, &ID);
}