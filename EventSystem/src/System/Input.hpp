#pragma once

#include <glm/vec2.hpp>

#include "Core/ButtonCodes.hpp"
#include "Core/KeyCodes.hpp"

namespace EventSystem {

    class Input {
    public:
        // Mouse
        static bool IsButtonPressed(ButtonCode buttonCode);

        static glm::vec<2, int> GetMousePosition();
        static inline int GetMouseX() { return GetMousePosition().x; };
        static inline int GetMouseY() { return GetMousePosition().y; };

        // Keyboard
        static bool IsKeyPressed(KeyCode keyCode);

    }; // class Input

} // namespace EventSystem