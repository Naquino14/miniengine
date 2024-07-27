cmake_minimum_required(VERSION 3.0.0)

project(miniengine)

find_package(OpenGL REQUIRED)

include_directories(include)

add_executable( miniengine 
    src/main.cpp 
    src/glad.c
)

target_link_libraries(miniengine 
    glfw
    OpenGL::GL
)