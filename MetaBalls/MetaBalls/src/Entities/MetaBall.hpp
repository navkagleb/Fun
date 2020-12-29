#pragma once

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/CircleShape.hpp>

namespace Meta {

    class MetaBall {
    public:
        // Constructor / Destructor
        MetaBall(float x, float y, float radius, const sf::Vector2f& velocity);
        virtual ~MetaBall() noexcept = default;

        // Accessors
        float GetRadius() const { return m_Circle.getRadius(); }

        // Public methods
        float GetDistance(float x, float y) const;

        void OnUpdate(float dt);
        void OnRender(sf::RenderTarget& target) const;

    private:
        // Member methods

        // Member data
        sf::CircleShape m_Circle;
        sf::Vector2f    m_Velocity;

    }; // class MetaBall

} // namespace Meta
