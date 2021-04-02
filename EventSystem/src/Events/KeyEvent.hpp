#pragma once

#include "IEvent.hpp"

namespace EventSystem {

    class KeyEvent : public IEvent {
    public:
        ~KeyEvent() override = default;

        [[nodiscard]] inline int GetKey() const { return m_Key; }

    protected:
        explicit KeyEvent(int key)
            : m_Key(key) {}

    protected:
        int m_Key;

    }; // class KeyCode

    class KeyPressedEvent : public KeyEvent {
    public:
        KeyPressedEvent(int key, int count);
        ~KeyPressedEvent() override = default;

        [[nodiscard]] inline int GetCount() const { return m_Count; }
        [[nodiscard]] std::string ToString() const override;

        EVENT_CLASS_TYPE(KeyPressedEvent)

    private:
        int m_Count;

    }; // class KeyPressedEvent

    class KeyReleasedEvent : public KeyEvent {
    public:
        explicit KeyReleasedEvent(int key);
        ~KeyReleasedEvent() override = default;

        [[nodiscard]] std::string ToString() const override;

        EVENT_CLASS_TYPE(KeyReleasedEvent)

    }; // class KeyReleasedEvent

} // namespace EventSystem