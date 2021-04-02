#include "Mouse.hpp"

#include <GLFW/glfw3.h>

#include "Window.hpp"

namespace EventSystem {

    bool Mouse::IsButtonPressed(ButtonCode buttonCode) {
        return glfwGetMouseButton(Window::Get().GetHandle(), buttonCode) == GLFW_PRESS;
    }

    glm::vec<2, int> Mouse::GetMousePosition() {
        glm::vec<2, int> result(0);

        glfwGetCursorPos(
            Window::Get().GetHandle(),
            reinterpret_cast<double *>(&result.x),
            reinterpret_cast<double *>(&result.y)
        );

        return result;
    }

} // namespace EventSystem