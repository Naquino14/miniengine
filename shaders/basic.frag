#version 450 core

in vec4 vertexColor;

out vec4 FragColor;

void main() {
    FragColor = vertexColor;
}