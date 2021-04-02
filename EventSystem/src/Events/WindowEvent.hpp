#pragma once

#include "IEvent.hpp"

namespace EventSystem {

    /////////////////////////////////////////////////////////////////////////////////////////////////
    /// WindowResizeEvent/ //////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////
    class WindowResizeEvent : public IEvent {
    public:
        WindowResizeEvent(int width, int height);
        ~WindowResizeEvent() override = default;

        [[nodiscard]] inline int GetWidth() const { return m_Width; }
        [[nodiscard]] inline int GetHeight() const { return m_Height; }
        [[nodiscard]] std::string ToString() const override;

        EVENT_CLASS_TYPE(WindowResizeEvent);

    private:
        int m_Width;
        int m_Height;

    }; // class WindowResizeEvent

    /////////////////////////////////////////////////////////////////////////////////////////////////
    /// WindowCloseEvent ////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////
    class WindowCloseEvent : public IEvent {
    public:
        WindowCloseEvent() = default;
        ~WindowCloseEvent() override = default;

        [[nodiscard]] inline std::string ToString() const override { return GetName(); }

        EVENT_CLASS_TYPE(WindowCloseEvent);

    }; // class WindowCloseEvent

    /////////////////////////////////////////////////////////////////////////////////////////////////
    /// WindowMaximizedEvent ////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////
    class WindowMaximizedEvent : public IEvent {
    public:
        WindowMaximizedEvent() = default;
        ~WindowMaximizedEvent() override = default;

        [[nodiscard]] inline std::string ToString() const override { return GetName(); }

        EVENT_CLASS_TYPE(WindowMaximizedEvent);

    }; // class WindowMaximizedEvent

    /////////////////////////////////////////////////////////////////////////////////////////////////
    /// WindowMinimizedEvent ////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////
    class WindowMinimizedEvent : public IEvent {
    public:
        WindowMinimizedEvent() = default;
        ~WindowMinimizedEvent() override = default;

        [[nodiscard]] inline std::string ToString() const override { return GetName(); }

        EVENT_CLASS_TYPE(WindowMinimizedEvent);

    }; // class WindowMinimizedEvent

    /////////////////////////////////////////////////////////////////////////////////////////////////
    /// WindowFocusedEvent //////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////
    class WindowFocusedEvent : public IEvent {
    public:
        WindowFocusedEvent() = default;
        ~WindowFocusedEvent() override = default;

        [[nodiscard]] inline std::string ToString() const override { return GetName(); }

        EVENT_CLASS_TYPE(WindowFocusedEvent);

    }; // class WindowFocusedEvent

    /////////////////////////////////////////////////////////////////////////////////////////////////
    /// WindowUnfocusedEvent ////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////
    class WindowUnfocusedEvent : public IEvent {
    public:
        WindowUnfocusedEvent() = default;
        ~WindowUnfocusedEvent() override = default;

        [[nodiscard]] inline std::string ToString() const override { return GetName(); }

        EVENT_CLASS_TYPE(WindowUnfocusedEvent);

    }; // class WindowUnfocusedEvent

} // namespace EventSystem