#pragma once

namespace EventSystem {

#define EVENT_CLASS_TYPE(ClassName)                                                                      \
    static EventType GetStaticEventType() { return EventType::ClassName; }                               \
    [[nodiscard]] inline EventType GetEventType() const override { return GetStaticEventType(); }        \
    [[nodiscard]] inline std::string GetName() const override { return #ClassName; }

#define EVENT_CLASS_CATEGORY(category)                                                                   \
    [[nodiscard]] inline int GetCategoryFlags() const override { return category; }

    enum class EventType : int {
        None = 0,

        WindowResizeEvent,
        WindowCloseEvent,
        WindowMaximizedEvent,
        WindowMinimizedEvent,
        WindowFocusedEvent,
        WindowUnfocusedEvent,
        WindowCursorEnteredEvent,
        WindowCursorLeftEvent,

        MouseMovedEvent,
        MouseScrolledEvent,
        MouseButtonPressedEvent,
        MouseButtonReleasedEvent,

        KeyPressedEvent,
        KeyReleasedEvent,
        KeyTypedEvent,
    };

    enum EventCategory : int {
        None                     = 0,

        EventCategoryWindow      = 1 << 0,
        EventCategoryInput       = 1 << 1,
        EventCategoryMouse       = 1 << 2,
        EventCategoryKeyboard    = 1 << 3,
        EventCategoryMouseButton = 1 << 4
    };

    class IEvent {
    public:
        virtual ~IEvent() = default;

        [[nodiscard]] virtual EventType GetEventType() const = 0;
        [[nodiscard]] virtual std::string GetName() const = 0;
        [[nodiscard]] virtual int GetCategoryFlags() const = 0;
        [[nodiscard]] virtual std::string ToString() const = 0;

        [[nodiscard]] inline bool IsInCategory(EventCategory category) const { return GetCategoryFlags() & category; }

        friend class EventDispatcher;

    protected:
        IEvent()
            : m_Handled(false) {}

    protected:
        bool m_Handled;

    }; // class IEvent

    using Event = IEvent;

} // namespace EventSystem