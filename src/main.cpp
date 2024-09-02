#include <iostream>
#include <string>
#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include <unistd.h>
#include <vector>

#include <Shader.h>
#include <ShaderProgram.h>
#include <Object.h>

#define RESX 800
#define RESY 800

using namespace std;

static float verts[] = {
    // position, normal, color, texture coord
    -0.5f, -0.5f, 0.0f,    0.0f, 0.0f, 0.0f,    1.0f, 0.0f, 0.0f,    0.0f, 0.0f,
    0.5f, -0.5f, 0.0f,     0.0f, 0.0f, 0.0f,    0.0f, 1.0f, 0.0f,    0.0f, 0.0f,
    0.0f, 0.5f, 0.0f,      0.0f, 0.0f, 0.0f,    0.0f, 0.0f, 1.0f,    0.0f, 0.0f
};

static float verts2[] = {
     0.5,  0.5, 0.0,    0.0f, 0.0f, 0.0f,   1.0f, 1.0f, 0.0f,    1.0f,  1.0f,
    -0.5,  0.5, 0.0,    0.0f, 0.0f, 0.0f,   0.0f, 1.0f, 0.0f,    1.0f, -1.0f,
     0.5, -0.5, 0.0,    0.0f, 0.0f, 0.0f,   1.0f, 0.0f, 0.0f,   -1.0f,  1.0f,
    -0.5, -0.5, 0.0,    0.0f, 0.0f, 0.0f,   0.0f, 0.0f, 0.0f,   -1.0f, -1.0f,
};

static unsigned int elems[] = {
    0, 1, 2
};

static unsigned int elems2[] = {
    1, 0, 2, 
    1, 2, 3
};

vector<Vertex> createVertexBuffer(unsigned long len, const float* pVerts) {
    vector<Vertex> vertices;
    const unsigned long limit = (len / sizeof(Vertex)) * 11;
    for (unsigned long i = 0; i < limit; i += 11) {
        Vertex vertex;
        vertex.position = vec3(pVerts[i], pVerts[i + 1], pVerts[i + 2]);
        vertex.normal = vec3(pVerts[i + 3], pVerts[i + 4], pVerts[i + 5]);
        vertex.color = vec3(pVerts[i + 6], pVerts[i + 7], pVerts[i + 8]);
        vertex.texCoords = vec2(pVerts[i + 9], pVerts[i + 10]);

        vertices.push_back(vertex);
    }
    return vertices;
}

vector<unsigned int> createElementBuffer(unsigned long len, unsigned int* pElems) {
    vector<unsigned int> elements;
    const unsigned long int limit = len / sizeof(unsigned int);
    for (unsigned long i = 0; i < limit; i++)
        elements.push_back(pElems[i]);

    return elements;
}

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

        // create vertex buffer
        vector<Vertex> vertices = createVertexBuffer(sizeof(verts), verts);

        vector<Vertex> vertices2 = createVertexBuffer(sizeof(verts2), verts2);

        // create element buffer
        vector<unsigned int> elements = createElementBuffer(sizeof(elems), elems);

        vector<unsigned int> elements2 = createElementBuffer(sizeof(elems2), elems2);

        // create mesh
        Mesh* mesh = new Mesh(vertices, elements, vector<Texture>());

        Mesh* mesh2 = new Mesh(vertices2, elements2, vector<Texture>()); 

        // create object
        Object* obj = new Object(basicProgram, mesh);

        Object* obj2 = new Object(basicProgram, mesh2);

        while (!glfwWindowShouldClose(window)) {
            // input
            process_input(window);

            // render
            glClear(GL_COLOR_BUFFER_BIT);
            // obj->Draw();
            obj2->Draw();

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