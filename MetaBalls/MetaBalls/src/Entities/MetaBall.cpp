#include "MetaBall.hpp"

#include <cmath>

#include <Random/Random.hpp>

namespace Meta {

    // Constructor / Destructor
    MetaBall::MetaBall(float x, float y, float radius) {
        // Init circle
        m_Circle.setPosition(x, y);
        m_Circle.setRadius(radius);
        m_Circle.setFillColor(sf::Color::Transparent);
        m_Circle.setOutlineThickness(2.0f);
        m_Circle.setOutlineColor(sf::Color::Black);
        m_Circle.setOrigin(radius, radius);

        // Init velocity
        m_Velocity = {
            Ng::Random::Get(50.0f, 100.0f) * (Ng::Random::Get<bool>(0.5f) ? -1.0f : 1.0f),
            Ng::Random::Get(50.0f, 100.0f) * (Ng::Random::Get<bool>(0.5f) ? -1.0f : 1.0f)
        };
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

    void MetaBall::OnUpdate(float dt) {
        m_Circle.setPosition(m_Circle.getPosition() + m_Velocity * dt);

        if (m_Circle.getPosition().x < 0.0f || m_Circle.getPosition().x > 1080.0f)
            m_Velocity.x *= -1.0f;

        if (m_Circle.getPosition().y < 0.0f || m_Circle.getPosition().y > 720.0f)
            m_Velocity.y *= -1.0f;
    }

    void MetaBall::OnRender(sf::RenderTarget& target) const {
        target.draw(m_Circle);
    }

} // namespace Meta