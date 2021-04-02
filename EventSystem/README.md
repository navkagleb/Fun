# FileSystem

## Code excursion

> Event Categories:
> - Window
> - Input
> - Keyboard
> - Mouse
> - MouseButton
___
> WindowEvent classes:
> - WindowResizeEvent
> - WindowCloseEvent
> - WindowMaximizedEvent
> - WindowMinimizedEvent
> - WindowFocusedEvent
> - WindowUnfocusedEvent
> - WindowCursorEnteredEvent
> - WindowCursorLeftEvent
___
> KeyEvent classes:
> - KeyPressedEvent
> - KeyReleasedEvent
> - KeyTypedEvent
___
> MouseEvent classes:
> - MouseMovedEvent
> - MouseScrolledEvent
> - MouseButtonPressedEvent
> - MouseButtonReleasedEvent
___
> Subsidiary classes:
> - Input
> - EventDispatcher

## Usage 
```c++
    #include "WindowEvent.hpp"
    #include "MouseEvent.hpp"
    #include "KeyEvent.hpp"
        
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
            
            if (EventSystem::Input::IsKeyPressed(EventSystem::Key::E))
                std::cout << "Event!" << std::endl;
            
            window.SwapBuffers();
        }
        
        EventSystem::Window::Destroy();
        
        return 0;
    }
```