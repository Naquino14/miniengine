#include <Object.h>

Object::Object(ShaderProgram* shaderProgram, Mesh* mesh) {
    this->shaderProgram = shaderProgram;
    this->mesh = mesh;
}

Object::Object(ShaderProgram* shaderProgram, Mesh* mesh, vec3 position, vec3 rotation, vec3 scale) {
    this->shaderProgram = shaderProgram;
    this->mesh = mesh;
    this->position = position;
    this->rotation = rotation;
    this->scale = scale;
}

Object::Object(Object* object) {
    this->objectName = object->objectName;
    this->shaderProgram = object->shaderProgram;
    this->mesh = mesh;
    this->position = vec3(object->position);
    this->rotation = vec3(object->rotation);
    this->scale = vec3(object->scale);
}

Object::~Object() {
    delete shaderProgram;
}

ShaderProgram* Object::GetShaderProgram() {
    return shaderProgram;
}

void Object::Update() {
    return;
}

string Object::GetObjectName() {
    return objectName;
}

Mesh* Object::GetMesh() {
    return mesh;
}

vec3 Object::GetPosition() { 
    return position;
}

vec3 Object::GetRotation() { 
    return rotation;
}

vec3 Object::GetScale() { 
    return scale;
}

void Object::SetPosition(vec3 position) {
    this->position = position;
}

void Object::SetRotation(vec3 rotation) {
    this->rotation = rotation;
}

void Object::SetScale(vec3 scale) {
    this->scale = scale;
}

void Object::Draw() {
    shaderProgram->Activate();
    mesh->vertexArrayObject->Bind();

    // upload stuff to uniforms

    
    mesh->Draw();
}