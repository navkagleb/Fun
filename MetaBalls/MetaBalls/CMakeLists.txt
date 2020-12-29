find_package(ImGui-SFML REQUIRED)

set(FILES
    src/main.cpp src/Application/Application.hpp src/Application/Application.cpp
    src/States/MetaBallState.cpp src/States/MetaBallState.hpp
    src/Entities/MetaBall.cpp src/Entities/MetaBall.hpp
    )

include_directories(src)

add_executable(${PROJECT_NAME} ${FILES})

target_link_libraries(${PROJECT_NAME} PRIVATE NgRandom)
target_link_libraries(${PROJECT_NAME} PRIVATE Engine)
target_link_libraries(${PROJECT_NAME} PRIVATE ImGui-SFML::ImGui-SFML)
