#include "KeyEvent.hpp"

namespace EventSystem {

    KeyPressedEvent::KeyPressedEvent(int key, int count)
        : KeyEvent(key)
        , m_Count(count) {}

    std::string KeyPressedEvent::ToString() const {
        return GetName() + ": " + static_cast<char>(m_Key) + "(" + std::to_string(m_Key) + ", " + std::to_string(m_Count) + ")";
    }

    KeyReleasedEvent::KeyReleasedEvent(int key)
        : KeyEvent(key) {}

    std::string KeyReleasedEvent::ToString() const {
        return GetName() + ": " + static_cast<char>(m_Key) + "(" + std::to_string(m_Key) + ")";
    }

} // namespace EventSystem