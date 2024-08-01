#include <glad/glad.h>

#pragma once

class IBufferObject {
public:
    unsigned int ID; 
    virtual void Bind() = 0;
    virtual void Unbind() = 0;
    virtual void Delete() = 0;
};