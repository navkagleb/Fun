#include "MetaBall.hpp"

#include <Random/Random.hpp>

namespace Meta {

    // Constructor / Destructor
    MetaBall::MetaBall(float x, float y, float radius) {
        // Init circle
        m_Circle.setPosition(x, y);
        m_Circle.setRadius(radius);
        m_Circle.setFillColor(sf::Color::Green);

        // Init velocity
        m_Velocity = { Ng::Random::Get(0.5f, 10.0f), Ng::Random::Get(0.5f, 10.0f) };
    }

    // Public methods
    void MetaBall::OnUpdate(float dt) {
        m_Circle.setPosition(m_Circle.getPosition() + m_Velocity);

        if (m_Circle.getPosition().x < 0.0f || m_Circle.getPosition().x > 1080.0f)
            m_Velocity.x *= -1.0f;

        if (m_Circle.getPosition().y < 0.0f || m_Circle.getPosition().y > 720.0f)
            m_Velocity.y *= -1.0f;
    }

    void MetaBall::OnRender(sf::RenderTarget& target) const {
        target.draw(m_Circle);
    }

} // namespace Meta