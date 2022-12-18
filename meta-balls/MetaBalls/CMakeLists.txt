find_package(ImGui-SFML REQUIRED)

file(GLOB HEADER_FILES
    "src/Application/*.hpp"
    "src/Entities/*.hpp"
    "src/States/*.hpp"
    "src/ThreadPool/*.hpp"
)

file(GLOB SOURCE_FILES
    "src/*.cpp"
    "src/Application/*.cpp"
    "src/Entities/*.cpp"
    "src/States/*.cpp"
    "src/ThreadPool/*.cpp"
)

include_directories(src)

MESSAGE(STATUS ${SOURCE_FILES})

add_executable(${PROJECT_NAME} ${HEADER_FILES} ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} PRIVATE NgRandom)
target_link_libraries(${PROJECT_NAME} PRIVATE Engine)
target_link_libraries(${PROJECT_NAME} PRIVATE ImGui-SFML::ImGui-SFML)
