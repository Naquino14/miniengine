#include <buffer_objects/IBufferObject.h>

#pragma once

/// @brief Element Buffer Object (EBO) class. Contains ordered indices for vertices.
class ElementBufferObject : public BufferObject {
private: 
    unsigned int elementCount;

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

    /// @brief Returns the number of elements in the EBO
    /// @return The number of elements in the EBO
    unsigned int GetElementCount();
};