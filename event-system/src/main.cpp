#include <iostream>

#include "System/Window.hpp"
#include "Events/KeyEvent.hpp"

#include "System/Input.hpp"
#include "Events/EventDispatcher.hpp"

int main() {
    auto& window = EventSystem::Window::Create("EventSystem", 1280, 720);

    window.SetEventFunc([&](EventSystem::Event& event) {
        if (event.IsInCategory(EventSystem::EventCategoryWindow))
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
        window.SwapBuffers();
    }

    EventSystem::Window::Destroy();

    return 0;
}
