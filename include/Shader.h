#include <iostream>
#include <fstream>
#include <vector>
#include "glad/glad.h"
#include <GLFW/glfw3.h>

using namespace std;

#pragma once

class Shader{
private:
    unsigned int shaderProgram;
public:
    /// @brief constructs a shader with the shader's file name and compiles it
    /// @param shaderName the file name of the shader
    Shader(string shaderName);

    /// @brief Destructor for the Shader class
    ~Shader();

    /// @brief Get the shader program's ID
    /// @return the shader program's ID
    unsigned int getShaderProgram();
};