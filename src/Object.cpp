#include <Object.h>

Object::Object(ShaderProgram* shaderProgram, vector<float> mesh, vector<float> color) {

}

Object::Object(ShaderProgram* shaderProgram, vector<float> mesh, vector<float> color, vec3 position, vec3 rotation, vec3 scale) {
    
}

Object::Object(Object* object) {
    this->objectName = object->objectName;
    this->shaderProgram = object->shaderProgram;
    this->mesh = vector(object->mesh);
    this->color = vector(object->color);
    this->position = vec3(object->position);
    this->rotation = vec3(object->rotation);
    this->scale = vec3(object->scale);
}

Object::~Object() {
    mesh.clear();
    color.clear();
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

vector<float> Object::GetMesh() {
    return mesh;
}

vector<float> Object::GetColor() {
    return color;
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
