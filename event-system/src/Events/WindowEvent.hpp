#pragma once

#include "IEvent.hpp"

namespace EventSystem {

    class WindowResizeEvent : public IEvent {
    public:
        WindowResizeEvent(int width, int height);
        ~WindowResizeEvent() override = default;

        [[nodiscard]] inline int GetWidth() const { return m_Width; }
        [[nodiscard]] inline int GetHeight() const { return m_Height; }
        [[nodiscard]] std::string ToString() const override;

        EVENT_CLASS_TYPE(WindowResizeEvent)
        EVENT_CLASS_CATEGORY(EventCategoryWindow)

    private:
        int m_Width;
        int m_Height;

    }; // class WindowResizeEvent

    class WindowCloseEvent : public IEvent {
    public:
        WindowCloseEvent() = default;
        ~WindowCloseEvent() override = default;

        [[nodiscard]] inline std::string ToString() const override { return GetName(); }

        EVENT_CLASS_TYPE(WindowCloseEvent)
        EVENT_CLASS_CATEGORY(EventCategoryWindow)


    }; // class WindowCloseEvent

    class WindowMaximizedEvent : public IEvent {
    public:
        WindowMaximizedEvent() = default;
        ~WindowMaximizedEvent() override = default;

        [[nodiscard]] inline std::string ToString() const override { return GetName(); }

        EVENT_CLASS_TYPE(WindowMaximizedEvent)
        EVENT_CLASS_CATEGORY(EventCategoryWindow)

    }; // class WindowMaximizedEvent

    class WindowMinimizedEvent : public IEvent {
    public:
        WindowMinimizedEvent() = default;
        ~WindowMinimizedEvent() override = default;

        [[nodiscard]] inline std::string ToString() const override { return GetName(); }

        EVENT_CLASS_TYPE(WindowMinimizedEvent)
        EVENT_CLASS_CATEGORY(EventCategoryWindow)

    }; // class WindowMinimizedEvent

    class WindowFocusedEvent : public IEvent {
    public:
        WindowFocusedEvent() = default;
        ~WindowFocusedEvent() override = default;

        [[nodiscard]] inline std::string ToString() const override { return GetName(); }

        EVENT_CLASS_TYPE(WindowFocusedEvent)
        EVENT_CLASS_CATEGORY(EventCategoryWindow)

    }; // class WindowFocusedEvent

    class WindowUnfocusedEvent : public IEvent {
    public:
        WindowUnfocusedEvent() = default;
        ~WindowUnfocusedEvent() override = default;

        [[nodiscard]] inline std::string ToString() const override { return GetName(); }

        EVENT_CLASS_TYPE(WindowUnfocusedEvent)
        EVENT_CLASS_CATEGORY(EventCategoryWindow)

    }; // class WindowUnfocusedEvent

    class WindowCursorEnteredEvent : public IEvent {
    public:
        WindowCursorEnteredEvent() = default;
        ~WindowCursorEnteredEvent() override = default;

        [[nodiscard]] inline std::string ToString() const override { return GetName(); }

        EVENT_CLASS_TYPE(WindowCursorEnteredEvent)
        EVENT_CLASS_CATEGORY(EventCategoryWindow)

    }; // class WindowUnfocusedEvent

    class WindowCursorLeftEvent : public IEvent {
    public:
        WindowCursorLeftEvent() = default;
        ~WindowCursorLeftEvent() override = default;

        [[nodiscard]] inline std::string ToString() const override { return GetName(); }

        EVENT_CLASS_TYPE(WindowCursorLeftEvent)
        EVENT_CLASS_CATEGORY(EventCategoryWindow)

    }; // class WindowUnfocusedEvent

} // namespace EventSystem