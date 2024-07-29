#include <iostream>
#include <string>
#include "glad/glad.h"
#include <GLFW/glfw3.h>

#include <Shader.h>
#include <ShaderProgram.h>
#include <unistd.h>

#define RESX 800
#define RESY 800

using namespace std;

static float verts[] = {
    -0.5f, -0.5f, 0.0f,
    0.5f, -0.5f, 0.0f,
    0.0f, 0.5f, 0.0f
};

// gotta be seprate from the class or compiler gets angry :(
void on_window_resize(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

class Program {
public: 
    GLFWwindow* window;

    int main(int argc, char** argv) {
        printf("Starting engine\n");

        if (!glfwInit()) 
            return -1;

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        window = glfwCreateWindow(RESX, RESY, "miniengine", NULL, NULL);
        if (!window) {
            printf("failed to create GLFW wibdow\n");
            glfwTerminate();
            return -1;
        }
        glfwMakeContextCurrent(window);

        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
            cout << "failed to init glad" << endl;
            glfwTerminate();
            return -1;
        }

        // register window resize callback
        glfwSetFramebufferSizeCallback(window, on_window_resize);

        glClearColor(0.25f, 0.5f, 0.75f, 1.0f);

        // create shaders
        Shader* basicVert = new Shader("shaders/basic.vert");
        Shader* basicFrag = new Shader("shaders/basic.frag");

        // create shader program
        ShaderProgram* basicProgram = new ShaderProgram(basicVert, basicFrag, nullptr, nullptr, "basicProgram");

        // create vertex array
        unsigned int vertexArray;
        glGenVertexArrays(1, &vertexArray);
        
        // create vertex buffer
        unsigned int vertexBuffer;
        glGenBuffers(1, &vertexBuffer);

        // bind vao, bind and copy vertex data, then configure vertex attributes
        glBindVertexArray(vertexArray);
        glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
        glBufferData(GL_ARRAY_BUFFER, sizeof(verts), verts, GL_STATIC_DRAW);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);

        // enable vertex attributes
        glEnableVertexAttribArray(0);

        // unbind buffer, then unbind vao
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindVertexArray(0);

        while (!glfwWindowShouldClose(window)) {
            // input
            process_input(window);

            // render
            glClear(GL_COLOR_BUFFER_BIT);
            glUseProgram(basicProgram->GetShaderProgram());
            glBindVertexArray(vertexArray);
            glDrawArrays(GL_TRIANGLES, 0, 3);

            // swap buffers
            glfwPollEvents();
            glfwSwapBuffers(window);
        }

        delete basicVert;

        glfwTerminate();

        return 0;
    }

    // temporary method, im still learning
    void process_input(GLFWwindow* window) {
        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
            glfwSetWindowShouldClose(window, true);
        }
    }
};

int main(int argc, char** argv) {
    return (new Program())->main(argc, argv);
}