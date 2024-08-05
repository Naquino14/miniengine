#include <glad/glad.h>
#include <glm/glm.hpp>
#include <vector>

using namespace std;
using namespace glm;

#pragma once


class BufferObject {
public:
    unsigned int ID; 
    virtual void Bind() = 0;
    virtual void Unbind() = 0;
    virtual void Delete() = 0;
};