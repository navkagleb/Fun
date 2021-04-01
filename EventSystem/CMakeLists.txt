cmake_minimum_required(VERSION 3.17)
project(EventSystem)

set(CMAKE_CXX_STANDARD 20)

set(HEADER_FILES src/*.hpp)

set(SOURCE_FILES src/*.cpp)

add_subdirectory(external/glfw)

add_executable(${PROJECT_NAME} src/main.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE glfw)