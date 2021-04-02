#pragma once

#include "IEvent.hpp"
#include "Core/ButtonCodes.hpp"

namespace EventSystem {

    /////////////////////////////////////////////////////////////////////////////////////////////////
    /// MouseMovedEvent /////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////
    class MouseMovedEvent : public IEvent {
    public:
        MouseMovedEvent(int x, int y);
        ~MouseMovedEvent() override = default;

        [[nodiscard]] inline int GetX() const { return m_X; }
        [[nodiscard]] inline int GetY() const { return m_Y; }
        [[nodiscard]] std::string ToString() const override;

        EVENT_CLASS_TYPE(MouseMovedEvent)

    private:
        int m_X;
        int m_Y;

    }; // class MouseMovedEvent

    /////////////////////////////////////////////////////////////////////////////////////////////////
    /// MouseScrolledEvent //////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////
    class MouseScrolledEvent : public IEvent {
    public:
        MouseScrolledEvent(int offsetX, int offsetY);
        ~MouseScrolledEvent() override = default;

        [[nodiscard]] inline int GetOffsetX() const { return m_OffsetX; }
        [[nodiscard]] inline int GetOffsetY() const { return m_OffsetY; }
        [[nodiscard]] std::string ToString() const override;

        EVENT_CLASS_TYPE(MouseScrolledEvent)

    private:
        int m_OffsetX;
        int m_OffsetY;

    }; // MouseScrolledEvent

    /////////////////////////////////////////////////////////////////////////////////////////////////
    /// MouseButtonPressed //////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////
    class MouseButtonPressedEvent : public IEvent {
    public:
        explicit MouseButtonPressedEvent(ButtonCode buttonCode);
        ~MouseButtonPressedEvent() override = default;

        [[nodiscard]] inline int GetButtonCode() const { return m_ButtonCode; }
        [[nodiscard]] std::string ToString() const override;

        EVENT_CLASS_TYPE(MouseButtonPressedEvent)

    private:
        int m_ButtonCode;

    }; // MouseButtonPressedEvent

    /////////////////////////////////////////////////////////////////////////////////////////////////
    /// MouseButtonReleasedEvent/////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////
    class MouseButtonReleasedEvent : public IEvent {
    public:
        explicit MouseButtonReleasedEvent(ButtonCode buttonCode);
        ~MouseButtonReleasedEvent() override = default;

        [[nodiscard]] inline int GetButtonCode(int button) const { return m_ButtonCode; }
        [[nodiscard]] std::string ToString() const override;

        EVENT_CLASS_TYPE(MouseButtonReleasedEvent);

    private:
        int m_ButtonCode;

    }; // class MouseButtonReleasedEvent

} // namespace EventSystem