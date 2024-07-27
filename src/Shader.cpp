#include <Shader.h>

Shader::Shader(string shaderName) {
    char ext = shaderName.c_str()[shaderName.find(".") + 1];
    unsigned int shaderType;
    switch (ext) {
        case 'v':
            shaderType = GL_VERTEX_SHADER;
            break;
        case 'f':
            shaderType = GL_FRAGMENT_SHADER;
            break;
        case 'g':
            shaderType = GL_GEOMETRY_SHADER;
            break;
        case 'c':
            shaderType = GL_COMPUTE_SHADER;
            break;
        default:
            return;
    }
    shaderProgram = glCreateShader(GL_VERTEX_SHADER);
    
    ifstream file(shaderName);
    if (!file.is_open()) {
        printf("Failed to open file: %s\n", shaderName.c_str());
        return;
    }
    // get file size, then rewind the file pointer
    streamsize fileSize = file.tellg();
    file.seekg(0, ios::end);
    
    char* fileBuff = (char*)malloc(fileSize * sizeof(char) + 1);
    fileBuff[fileSize] = '\0';
    file.read(fileBuff, fileSize);

    // compile shader
    glShaderSource(shaderProgram, 1, &fileBuff, nullptr);
    glCompileShader(shaderProgram);

    // check shader compilation log
    int success;
    char infoLog[512];
    glGetShaderiv(shaderProgram, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(shaderProgram, 512, nullptr, infoLog);
        printf("Failed to compile shader:\n%s\n", infoLog);
    }

    printf("Compiled shader: %s\n", shaderName.c_str());
}

Shader::~Shader() 
{
    glDeleteShader(shaderProgram);
}

unsigned int Shader::getShaderProgram() {
    return shaderProgram;
}