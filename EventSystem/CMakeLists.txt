cmake_minimum_required(VERSION 3.17)
project(EventSystem)

set(CMAKE_CXX_STANDARD 20)

file(GLOB HEADER_FILES
    src/*.hpp
    src/Core/*.hpp
    src/Events/*.hpp
    src/System/*.hpp
)
file(GLOB SOURCE_FILES
    src/*.cpp
    src/Core/*.cpp
    src/Events/*.cpp
    src/System/*.cpp
)

include_directories(src)

add_subdirectory(external/glfw)
add_subdirectory(external/glm)

add_executable(${PROJECT_NAME} ${HEADER_FILES} ${SOURCE_FILES})

target_include_directories(${PROJECT_NAME} PRIVATE external/glm)

target_link_libraries(${PROJECT_NAME} PRIVATE glfw glm)

target_precompile_headers(${PROJECT_NAME} PRIVATE src/pch.hpp)