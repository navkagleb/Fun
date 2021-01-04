#include "MetaBall.hpp"

#include <cmath>

namespace Meta {

    // Constructor / Destructor
    MetaBall::MetaBall(float x, float y, float radius, const sf::Vector2f& velocity) :
        m_Velocity(velocity) {

        m_Circle.setPosition(x, y);
        m_Circle.setRadius(radius);
        m_Circle.setFillColor(sf::Color::Transparent);
        m_Circle.setOutlineThickness(3.0f);
        m_Circle.setOutlineColor(sf::Color::Black);
        m_Circle.setOrigin(radius, radius);
    }

    // Modifiers
    void MetaBall::SetPosition(float x, float y) {
        m_Circle.setPosition(x, y);
    }

    // Public methods
    float MetaBall::GetDistance(float x, float y) const {
        return static_cast<float>(
            std::sqrt(
                std::pow(x - m_Circle.getPosition().x, 2) +
                std::pow(y - m_Circle.getPosition().y, 2)
            )
        );
    }

    void MetaBall::OnUpdate(float dt, const sf::Vector2u& windowSize) {
        if (m_Circle.getPosition().x <= 0.0f) {
            m_Circle.setPosition(0.0f, m_Circle.getPosition().y);
            m_Velocity.x *= -1.0f;
        }

        if (m_Circle.getPosition().x >= windowSize.x) {
            m_Circle.setPosition(windowSize.x, m_Circle.getPosition().y);
            m_Velocity.x *= -1.0f;
        }

        if (m_Circle.getPosition().y <= 0.0f) {
            m_Circle.setPosition(m_Circle.getPosition().x, 0.0f);
            m_Velocity.y *= -1.0f;
        }

        if (m_Circle.getPosition().y >= windowSize.y) {
            m_Circle.setPosition(m_Circle.getPosition().x, windowSize.y);
            m_Velocity.y *= -1.0f;
        }

        m_Circle.setPosition(m_Circle.getPosition() + m_Velocity * dt);
    }

    void MetaBall::OnRender(sf::RenderTarget& target) const {
        target.draw(m_Circle);
    }

} // namespace Meta