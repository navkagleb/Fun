#pragma once

#include <vector>

#include <Engine/States/State.hpp>

#include <SFML/Graphics/Texture.hpp>
#include <SFMl/Graphics/Image.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include "Entities/MetaBall.hpp"
#include "ThreadPool/ThreadPool.hpp"

namespace Meta {

    class MetaBallState : public Ng::Engine::State {
    public:
        // Constructor / Destructor
        MetaBallState();
        ~MetaBallState() override = default;

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

        void OnUpdateImage(std::size_t left, std::size_t right);

        sf::Color GetColor(int factor) const;

        // Member data
        std::vector<MetaBall> m_MetaBalls;
        sf::Image             m_Image;
        sf::Texture           m_Texture;
        sf::Sprite            m_Sprite;
        ThreadPool            m_ThreadPool;
        float                 m_Scale;
        bool                  m_IsColored;
        bool                  m_IsImGui;
        bool                  m_IsMetaBallOutline;

    }; // class MetaBallState

} // namespace Meta