#pragma once

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/CircleShape.hpp>

namespace Meta {

    class MetaBall {
    public:
        // Constructor / Destructor
        MetaBall(float x, float y, float radius);
        virtual ~MetaBall() noexcept = default;

        // Public methods
        void OnUpdate(float dt);
        void OnRender(sf::RenderTarget& target) const;

    private:
        // Member methods

        // Member data
        sf::CircleShape m_Circle;
        sf::Vector2f    m_Velocity;

    }; // class MetaBall

} // namespace Meta
