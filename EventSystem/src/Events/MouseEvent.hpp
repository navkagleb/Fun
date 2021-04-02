#pragma once

#include "IEvent.hpp"

namespace EventSystem {

    class MouseMovedEvent : public IEvent {
    public:
        MouseMovedEvent(int x, int y)
            : m_X(x)
            , m_Y(y) {}
        ~MouseMovedEvent() override = default;

        [[nodiscard]] inline int GetX() const { return m_X; }
        [[nodiscard]] inline int GetY() const { return m_Y; }
        [[nodiscard]] std::string ToString() const override;

        EVENT_CLASS_TYPE(MouseMovedEvent)

    private:
        int m_X;
        int m_Y;

    }; // class MouseMovedEvent

    class MouseScrolledEvent : public IEvent {
    public:
        MouseScrolledEvent(int offsetX, int offsetY)
            : m_OffsetX(offsetX)
            , m_OffsetY(offsetY) {}
        ~MouseScrolledEvent() override = default;

        [[nodiscard]] inline int GetOffsetX() const { return m_OffsetX; }
        [[nodiscard]] inline int GetOffsetY() const { return m_OffsetY; }
        [[nodiscard]] std::string ToString() const override;

        EVENT_CLASS_TYPE(MouseScrolledEvent)

    private:
        int m_OffsetX;
        int m_OffsetY;

    }; // MouseScrolledEvent

    class MouseButtonPressedEvent : public IEvent {
    public:
        explicit MouseButtonPressedEvent(int button)
            : m_Button(button) {}
        ~MouseButtonPressedEvent() override = default;

        [[nodiscard]] inline int GetButton() const { return m_Button; }
        [[nodiscard]] std::string ToString() const override;

        EVENT_CLASS_TYPE(MouseButtonPressedEvent)

    private:
        int m_Button;

    }; // MouseButtonPressedEvent

    class MouseButtonReleasedEvent : public IEvent {
    public:
        explicit MouseButtonReleasedEvent(int button)
            : m_Button(button) {}
        ~MouseButtonReleasedEvent() override = default;

        [[nodiscard]] inline int GetButton(int button) const { return m_Button; }
        [[nodiscard]] std::string ToString() const override;

        EVENT_CLASS_TYPE(MouseButtonReleasedEvent);

    private:
        int m_Button;

    }; // class MouseButtonReleasedEvent

} // namespace EventSystem