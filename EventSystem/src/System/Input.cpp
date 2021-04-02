#include "Input.hpp"

#include "Window.hpp"

namespace EventSystem {

    bool Input::IsButtonPressed(ButtonCode buttonCode) {
        return glfwGetMouseButton(Window::Get().GetHandle(), buttonCode) == GLFW_PRESS;
    }

    glm::vec<2, int> Input::GetMousePosition() {
        glm::vec<2, int> result(0);

        glfwGetCursorPos(
            Window::Get().GetHandle(),
            reinterpret_cast<double *>(&result.x),
            reinterpret_cast<double *>(&result.y)
        );

        return result;
    }

    bool Input::IsKeyPressed(KeyCode keyCode) {
        return glfwGetKey(Window::Get().GetHandle(), keyCode) == GLFW_PRESS;
    }

} // namespace EventSystem