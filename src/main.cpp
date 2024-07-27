#include <iostream>
#include <string>
#include "glad/glad.h"
#include <GLFW/glfw3.h>

#include <Shader.h>

#define RESX 800
#define RESY 800

using namespace std;

static float verts[] = {
    -0.5f, -0.5f,
    0.5f, -0.5f,
    0.0f, 0.5f
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

        // create vertex buffer object
        GLuint vertexBuffer;
        glGenBuffers(1, &vertexBuffer);
        glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);

        // copy vertex buffer data to memory
        glBufferData(GL_ARRAY_BUFFER, sizeof(verts), verts, GL_STATIC_DRAW);

        // create shaders
        Shader* basicVert = new Shader("shaders/basic.vert");

        while (!glfwWindowShouldClose(window)) {
            // input
            process_input(window);

            // render

            // swap buffers
            glfwPollEvents();
            glClear(GL_COLOR_BUFFER_BIT);
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