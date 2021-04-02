#include <iostream>

#include "System/Window.hpp"

int main() {
    auto& window = EventSystem::Window::Create("EventSystem", 1280, 720);

    while (window.IsOpen()) {
        window.PollEvents();
        window.SwapBuffers();
    }

    return 0;
}
