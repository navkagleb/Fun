#include "Window.hpp"

#include "Events/MouseEvent.hpp"
#include "Events/KeyEvent.hpp"

namespace EventSystem {

    void Window_Impl::PollEvents() const {
        glfwPollEvents();
    }

    void Window_Impl::SwapBuffers() const {
        glfwSwapBuffers(m_Handle);
    }

    void Window_Impl::MouseMovedCallback(HandleType* handle, double x, double y) {
        auto& instance = *(Window_Impl*)glfwGetWindowUserPointer(handle);

        MouseMovedEvent event(static_cast<int>(x), static_cast<int>(y));
        instance.m_EventFunc(event);
    }

    void Window_Impl::MouseScrolledCallback(HandleType* handle, double offsetX, double offsetY) {
        auto& instance = *(Window_Impl*)glfwGetWindowUserPointer(handle);

        MouseScrolledEvent event(static_cast<int>(offsetX), static_cast<int>(offsetY));
        instance.m_EventFunc(event);
    }

    void Window_Impl::MouseButtonCallback(HandleType* handle, int button, int action, int mods) {
        auto& instance = *(Window_Impl*)glfwGetWindowUserPointer(handle);

        if (action == GLFW_PRESS) {
            MouseButtonPressedEvent event(button);
            instance.m_EventFunc(event);
        } else if (action == GLFW_RELEASE) {
            MouseButtonReleasedEvent event(button);
            instance.m_EventFunc(event);
        }
    }

    void Window_Impl::KeyCallback(HandleType* handle, int key, int scancode, int action, int mods) {
        auto& instance = *(Window_Impl*)glfwGetWindowUserPointer(handle);

        static int prevKey = -1;
        static int count;

        if (prevKey != key)
            count = 0;

        switch (action) {
            case GLFW_PRESS: {
                KeyPressedEvent event(key, count);
                instance.m_EventFunc(event);
                break;
            }

            case GLFW_RELEASE: {
                count = 0;
                KeyReleasedEvent event(key);
                instance.m_EventFunc(event);
                break;
            }


            case GLFW_REPEAT: {
                ++count;
                KeyPressedEvent event(key, count);
                instance.m_EventFunc(event);
                break;
            }

            default: break;
        }

        prevKey = key;
    }

    Window_Impl::Window_Impl(std::string title, int width, int height)
        : m_Title(std::move(title))
        , m_Width(width)
        , m_Height(height)
        , m_Handle(nullptr) {

        if (!glfwInit())
            throw std::runtime_error("EventSystem::Window_Impl::Ctor: glfw crash in init!");

        m_Handle = glfwCreateWindow(m_Width, m_Height, m_Title.c_str(), nullptr, nullptr);

        if (!m_Handle)
            throw std::runtime_error("EventSystem::Window_Impl::Ctor: m_Handle is nullptr!");

        m_EventFunc = [](Event& event) {
            std::cout << event.ToString() << std::endl;
        };

        glfwMakeContextCurrent(m_Handle);
        glfwSetWindowUserPointer(m_Handle, this);

        glfwSetCursorPosCallback(m_Handle, MouseMovedCallback);
        glfwSetScrollCallback(m_Handle, MouseScrolledCallback);
        glfwSetMouseButtonCallback(m_Handle, MouseButtonCallback);
        glfwSetKeyCallback(m_Handle, KeyCallback);
    }

    Window_Impl::~Window_Impl() {
        glfwTerminate();
    }

} // namespace EventSystem