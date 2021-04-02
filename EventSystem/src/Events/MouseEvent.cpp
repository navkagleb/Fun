#include "MouseEvent.hpp"

namespace EventSystem {

    std::string MouseMovedEvent::ToString() const {
        return GetName() + ": " + std::to_string(m_X) + ", " + std::to_string(m_Y);
    }

    std::string MouseScrolledEvent::ToString() const {
        return GetName() + ": " + std::to_string(m_OffsetX) + ", " + std::to_string(m_OffsetY);
    }

    std::string MouseButtonPressedEvent::ToString() const {
        return GetName() + ": " + std::to_string(m_Button);
    }

    std::string MouseButtonReleasedEvent::ToString() const {
        return GetName() + ": " + std::to_string(m_Button);
    }

} // namespace EventSystem