#include <vector>
#include <string>
#include <glm/glm.hpp>
#include <ShaderProgram.h>
#include <Mesh.h>

#pragma once

using namespace std;
using namespace glm;

class Object {
private:
    // object data
    string objectName;

    // material data

    /// @brief The object's material's shader program
    ShaderProgram* shaderProgram;

    /// @brief The object's mesh 
    Mesh* mesh;
    
    // transform data

    /// @brief The obkect's position in the world
    vec3 position;
    /// @brief The object's rotation in the world
    vec3 rotation;
    /// @brief The object's scale
    vec3 scale;

public:
    /// @brief Constructs an Object with a name, shader program, mesh, and vertex color array
    /// @param objectName the object's name
    /// @param shaderProgram the object's shader program
    /// @param mesh the object's mesh
    Object(ShaderProgram* shaderProgram, Mesh* mesh);

    /// @brief Full constructor for the Object class
    /// @param objectName the object's name
    /// @param shaderProgram the object's shader program
    /// @param mesh the object's mesh
    /// @param position the object's position in the world  
    /// @param rotation the object's rotation in the world
    /// @param scale the object's scale
    Object(ShaderProgram* shaderProgram, Mesh* mesh, vec3 position, vec3 rotation, vec3 scale);

    /// @brief Clone constructor for the Object class
    /// @param object the object to clone
    Object(Object* object);


    /// @brief Destructor for the Object class
    ~Object();

    /// @brief Get the object's shader program
    /// @return the object's shader program
    ShaderProgram* GetShaderProgram();

    /// @brief The update callback for this Object
    void Update();

    /// @brief Get the object's name
    /// @return the object's name
    string GetObjectName();

    /// @brief Get the object's mesh
    /// @return the object's mesh
    Mesh* GetMesh();

    /// @brief Get the object's position
    /// @return the object's position
    vec3 GetPosition();

    /// @brief Get the object's rotation
    /// @return the object's rotation
    vec3 GetRotation();

    /// @brief Get the object's scale
    /// @return the object's scale
    vec3 GetScale();

    /// @brief Set the object's position
    /// @param position the object's new position
    void SetPosition(vec3 position);

    /// @brief Set the object's rotation
    /// @param rotation the object's new rotation
    void SetRotation(vec3 rotation);

    /// @brief Set the object's scale
    /// @param scale the object's new scale
    void SetScale(vec3 scale);    

    /// @brief Draw the object
    void Draw();
};