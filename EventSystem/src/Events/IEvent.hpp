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

        friend class EventDispatcher;

    protected:
        IEvent()
            : m_Handled(false) {}

    protected:
        bool m_Handled;

    }; // class IEvent

    using Event = IEvent;

    template <typename T>
    concept EventSibling = std::is_base_of_v<Event, T>;

    class EventDispatcher {
    public:
        template <EventSibling T>
        using EventFunc = std::function<bool(T&)>;

        explicit EventDispatcher(Event& event)
            : m_Event(event) {}
        ~EventDispatcher() = default;

        template <EventSibling T>
        bool Dispatch(const EventFunc<T>& eventFunc) {
            if (m_Event.GetEventType() == T::GetStaticEventType()) {
                m_Event.m_Handled = eventFunc(static_cast<T&>(m_Event));
                return true;
            }

            return false;
        }

    private:
        Event& m_Event;

    }; // class eventDispatcher

} // namespace EventSystem