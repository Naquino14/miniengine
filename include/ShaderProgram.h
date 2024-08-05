#include <Shader.h>
#include <iostream>
#include <fstream>
#include <vector>
#include "glad/glad.h"
#include <GLFW/glfw3.h>

using namespace std;

#pragma once

class ShaderProgram {
private:
    unsigned int shaderProgram;
    
    Shader* fragShader;
    Shader* vertShader;
    Shader* geomShader;
    Shader* compShader;

    string programName;

    void CreateShaderProgram();
public:
    /// @brief constructs a shader program with the shaders' file names and compiles it
    /// @param vertShaderName the file name of the vertex shader
    /// @param fragShaderName the file name of the fragment shader
    ShaderProgram(string vertShaderName, string fragShaderName);

    /// @brief constructs a shader program with the shaders' file names and compiles it
    /// @param vertShaderName the file name of the vertex shader
    /// @param fragShaderName the file name of the fragment shader
    /// @param geomShaderName the file name of the geometry shader
    ShaderProgram(string vertShaderName, string fragShaderName, string geomShaderName);

    /// @brief constructs a shader program with a compute shader's file name and compiles it
    /// @param compShaderName the file name of the compute shader
    ShaderProgram(string compShaderName);

    /// @brief constructs a shader program with the shaders and compiles it
    /// @param vertShader the vertex shader
    /// @param fragShader the fragment shader
    /// @param geomShader the geometry shader
    /// @param compShader the compute shader
    /// @param programName the program name
    ShaderProgram(Shader* vertShader, Shader* fragShader, Shader* geomShader, Shader* compShader, string programName);

    /// @brief Destructor for the ShaderProgram class
    ~ShaderProgram();

    /// @brief Get the shader program's ID
    /// @return the shader program's ID
    unsigned int GetShaderProgram();

    /// @brief Get the fragment shader
    /// @return the fragment shader
    Shader* GetFragShader();

    /// @brief Get the vertex shader
    /// @return the vertex shader
    Shader* GetVertShader();

    /// @brief Get the geometry shader
    /// @return the geometry shader
    Shader* GetGeomShader();

    /// @brief Get the compute shader
    /// @return the compute shader
    Shader* GetCompShader();

    /// @brief Get the program name
    /// @return the program name
    string GetProgramName();

    /// @brief Set the program name
    /// @param programName the program name
    void SetProgramName(string programName);

    /// @brief Activate the shader program
    void Activate();
};