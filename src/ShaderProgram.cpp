#include <ShaderProgram.h>

// private members

void ShaderProgram::CreateShaderProgram() {
    shaderProgram = glCreateProgram();

    if (vertShader)
        glAttachShader(shaderProgram, vertShader->getShaderProgram());
    
    if (fragShader)
        glAttachShader(shaderProgram, fragShader->getShaderProgram());

    if (geomShader)
        glAttachShader(shaderProgram, geomShader->getShaderProgram());
    
    if (compShader)
        glAttachShader(shaderProgram, compShader->getShaderProgram());

    glLinkProgram(shaderProgram);

    // check if creating and linking the shader program was successful
    int success;
    char infoLog[512];
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shaderProgram, 512, nullptr, infoLog);
        printf("Failed to link shader program:\n%s\n", infoLog);
    } else if (programName == "") 
        printf("Linked shader program\n");
    else    
        printf("Linked shader program: %s\n", programName.c_str());
}

// public members

ShaderProgram::ShaderProgram(string vertShaderName, string fragShaderName) {
    vertShader = new Shader(vertShaderName);
    fragShader = new Shader(fragShaderName);

    CreateShaderProgram();
}

ShaderProgram::ShaderProgram(string vertShaderName, string fragShaderName, string geomShaderName) {
    vertShader = new Shader(vertShaderName);
    fragShader = new Shader(fragShaderName);
    geomShader = new Shader(geomShaderName);

    CreateShaderProgram();
}

ShaderProgram::ShaderProgram(string compShaderName) {
    compShader = new Shader(compShaderName);

    CreateShaderProgram();
}

ShaderProgram::ShaderProgram(Shader* vertShader, Shader* fragShader, Shader* geomShader, Shader* compShader, string programName) {
    this->vertShader = vertShader;
    this->fragShader = fragShader;
    this->geomShader = geomShader;
    this->compShader = compShader;

    this->programName = programName;

    CreateShaderProgram();
}

ShaderProgram::~ShaderProgram() {
  glDeleteProgram(shaderProgram);

  if (fragShader) delete fragShader;

  if (vertShader) delete vertShader;

  if (geomShader) delete geomShader;

  if (compShader) delete compShader;
}

unsigned int ShaderProgram::GetShaderProgram() { 
    return shaderProgram;
}

Shader* ShaderProgram::GetFragShader() { 
    return fragShader;
}

Shader* ShaderProgram::GetVertShader() {
    return vertShader;
}

Shader* ShaderProgram::GetGeomShader() {
    return geomShader;
}

Shader* ShaderProgram::GetCompShader() { 
    return compShader;
}

string ShaderProgram::GetProgramName() { 
    return programName;
}

void ShaderProgram::SetProgramName(string programName) {
    this->programName = programName;
}