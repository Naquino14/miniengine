#include <glad/glad.h>
#include <buffer_objects/IBufferObject.h>
#include <vector>

#pragma once

using namespace std;

class ElementBufferObject : public IBufferObject {
private:
    unsigned int ID;

public:
    /// @brief Creates an EBO with the given indices
    /// @param indices The indices array to copy into the EBO
    ElementBufferObject(vector<unsigned int> indices);

    /// @brief Binds the EBO
    void Bind() override;

    /// @brief Unbinds the EBO
    void Unbind() override;

    /// @brief Deletes the EBO
    void Delete() override;
};