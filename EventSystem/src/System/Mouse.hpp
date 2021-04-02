#pragma once

#include <glm/vec2.hpp>

#include "Core/ButtonCodes.hpp"

namespace EventSystem {

    class Mouse {
    public:

        static bool IsButtonPressed(ButtonCode buttonCode);

        static glm::vec<2, int> GetMousePosition();
        static inline int GetX() { return GetMousePosition().x; };
        static inline int GetY() { return GetMousePosition().y; };

    }; // class Mouse

} // namespace EventSystem