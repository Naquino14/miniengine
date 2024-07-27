#include <iostream>
#include "glad/glad.h"
#include <GLFW/glfw3.h>

#define RESX 1920
#define RESY 1080

using namespace std;

static float verts[] = {
    -0.5f, -0.5f,
    0.5f, -0.5f,
    0.0f, 0.5f
};

class Program {
public: 
    GLFWwindow* window;

    int Main(int argc, char** argv) {
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

        glClearColor(0.25f, 0.5f, 0.75f, 1.0f);

        // create vertex buffer object
        GLuint vertexBuffer;
        glGenBuffers(1, &vertexBuffer);
        glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);

        // copy vertex buffer data to memory
        glBufferData(GL_ARRAY_BUFFER, sizeof(verts), verts, GL_STATIC_DRAW);

        while (!glfwWindowShouldClose(window)) {
            glfwPollEvents();

            glClear(GL_COLOR_BUFFER_BIT);

            glfwSwapBuffers(window);
        }

        glfwTerminate();

        return 0;
    }
};

int main(int argc, char** argv) {
    return (new Program())->Main(argc, argv);
}