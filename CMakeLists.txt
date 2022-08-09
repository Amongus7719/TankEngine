cmake_minimum_required(VERSION 3.13 FATAL_ERROR)

set(Project_NAME TankEngine)
project(TankEngine)

add_executable(TankEngine src/main.cpp)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)

add_subdirectory(external/glfw)
target_link_libraries(TankEngine glfw)
