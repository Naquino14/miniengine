#pragma once

class IBufferObject {
public:
    virtual void Bind() = 0;
    virtual void Unbind() = 0;
    virtual void Delete() = 0;
};