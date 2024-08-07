cmake_minimum_required(VERSION 3.0.0)

project(miniengine)

file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/shaders)

find_package(OpenGL REQUIRED)

include_directories(include)

file(GLOB sources 
    src/*.cpp
    src/*.c
    src/buffer_objects/*.cpp
    src/buffer_objects/*.c
)

add_executable( miniengine 
    ${sources}
)

add_custom_command(TARGET miniengine PRE_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/shaders $<TARGET_FILE_DIR:miniengine>/shaders
)

target_link_libraries(miniengine 
    glfw
    OpenGL::GL
)