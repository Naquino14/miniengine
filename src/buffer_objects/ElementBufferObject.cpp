#include <buffer_objects/ElementBufferObject.h>

ElementBufferObject::ElementBufferObject(vector<unsigned int> indices) {
    glGenBuffers(1, &ID);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), indices.data(), GL_STATIC_DRAW);
}

void ElementBufferObject::Bind() {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
}

void ElementBufferObject::Unbind() {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void ElementBufferObject::Delete() {
    glDeleteBuffers(1, &ID);
}