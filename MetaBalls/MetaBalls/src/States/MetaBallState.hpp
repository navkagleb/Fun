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
        void OnKeyPressed(const sf::Event& event) override;

        void OnUpdate(float dt) override;
        void OnRender(sf::RenderTarget& target) const override;

    private:
        // Member static methods
        static sf::Color GetRGBFromHSV(int hue, float saturation, float value);

        // Member methods
        void PushMetaBall();
        void PopMetaBall();
        sf::Color GetColor(int factor) const;

        // Member data
        std::vector<MetaBall> m_MetaBalls;
        sf::Image             m_Image;
        sf::Texture           m_Texture;
        sf::Sprite            m_Sprite;
        float                 m_Scale;
        bool                  m_IsColored;
        bool                  m_IsImGui;

    }; // class MetaBallState

} // namespace Meta