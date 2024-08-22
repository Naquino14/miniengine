cmake_minimum_required(VERSION 3.0.0)

project(miniengine)

# Ensure build directory exists
file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/shaders)

# Find OpenGL package
find_package(OpenGL REQUIRED)

# Include directories
include_directories(include)

# Collect source files
file(GLOB sources 
    src/*.cpp
    src/*.c
    src/buffer_objects/*.cpp
    src/buffer_objects/*.c
)

# Add executable target
add_executable(miniengine ${sources})

# Add custom target to copy shaders
add_custom_target(copy_shaders ALL
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/shaders
        ${CMAKE_BINARY_DIR}/shaders
)

# Ensure that copy_shaders runs before building the executable
add_dependencies(miniengine copy_shaders)

# Link libraries
target_link_libraries(miniengine 
    glfw
    OpenGL::GL
)
