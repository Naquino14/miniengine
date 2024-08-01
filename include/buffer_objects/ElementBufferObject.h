#include <vector>

#include <buffer_objects/IBufferObject.h>

#pragma once

using namespace std;

/// @brief Element Buffer Object (EBO) class. Contains ordered indices for vertices.
class ElementBufferObject : public IBufferObject {
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