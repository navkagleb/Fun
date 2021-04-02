#include <iostream>

#include "System/Window.hpp"
#include "Events/KeyEvent.hpp"

#include "System/Mouse.hpp"

int main() {
    auto& window = EventSystem::Window::Create("EventSystem", 1280, 720);

    window.SetEventFunc([&](EventSystem::Event& event) {
        std::cout << event.ToString() << std::endl;

        EventSystem::EventDispatcher dispatcher(event);

        dispatcher.Dispatch<EventSystem::KeyPressedEvent>([&](EventSystem::KeyPressedEvent& event) {
            if (event.GetKeyCode() == EventSystem::Key::Escape)
                window.Close();

            return true;
        });
    });

    while (window.IsOpen()) {
        window.PollEvents();

        std::cout << EventSystem::Mouse::IsButtonPressed(EventSystem::Button::ButtonLeft) << std::endl;

        window.SwapBuffers();
    }

    EventSystem::Window::Destroy();

    return 0;
}
