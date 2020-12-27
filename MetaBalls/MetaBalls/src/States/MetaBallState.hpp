#pragma once

#include <vector>

#include <Engine/States/State.hpp>

#include <SFML/Graphics/Texture.hpp>
#include <SFMl/Graphics/Image.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include "Entities/MetaBall.hpp"

namespace Meta {

    class MetaBallState : public Ng::Engine::State {
    public:
        // Constructor / Destructor
        MetaBallState();
        ~MetaBallState() override;

        // Public methods
        void OnUpdate(float dt) override;
        void OnRender(sf::RenderTarget& target) const override;

    private:
        // Member methods

        // Member data
        std::vector<MetaBall> m_MetaBalls;
        std::vector<uint8_t>  m_Pixels;
        sf::Texture           m_Texture;
        sf::Sprite            m_Sprite;

    }; // class MetaBallState

} // namespace Meta