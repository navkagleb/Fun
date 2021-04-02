#pragma once

namespace EventSystem {

#define EVENT_CLASS_TYPE(ClassName)                                                                      \
    static EventType GetStaticEventType() { return EventType::ClassName; }                               \
    [[nodiscard]] inline EventType GetEventType() const override { return GetStaticEventType(); }        \
    [[nodiscard]] inline std::string GetName() const override { return #ClassName; }

    enum class EventType {
        MouseMovedEvent = 0,
        MouseScrolledEvent,
        MouseButtonPressedEvent,
        MouseButtonReleasedEvent,

        KeyPressedEvent,
        KeyReleasedEvent,
        KeyTypedEvent,

        WindowResizeEvent,
        WindowCloseEvent,
        WindowMaximizedEvent,
        WindowMinimizedEvent,
        WindowFocusedEvent,
        WindowUnfocusedEvent
    };

    class IEvent {
    public:
        virtual ~IEvent() = default;

        [[nodiscard]] virtual inline EventType GetEventType() const = 0;
        [[nodiscard]] virtual inline std::string GetName() const = 0;
        [[nodiscard]] virtual std::string ToString() const = 0;

    protected:
        IEvent()
            : m_Handled(false) {}

    protected:
        bool m_Handled;

    }; // class IEvent

    using Event = IEvent;

} // namespace EventSystem