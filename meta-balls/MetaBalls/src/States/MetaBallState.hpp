#pragma once

#include <vector>

#include <SFML/Graphics/Texture.hpp>
#include <SFMl/Graphics/Image.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include <Engine/States/State.hpp>

#include <Random/Random.hpp>

#include "Entities/MetaBall.hpp"
#include "ThreadPool/ThreadPool.hpp"

namespace Meta {

    class MetaBallState : public Ng::Engine::State {
    public:
        // Constructor / Destructor
        MetaBallState();
        ~MetaBallState() override = default;

        // Public methods
        void OnMouseMoved(const sf::Event& event) override;
        void OnMouseButtonPressed(const sf::Event& event) override;
        void OnMouseButtonReleased(const sf::Event& event) override;
        void OnKeyPressed(const sf::Event& event) override;

        void OnUpdate(float dt) override;
        void OnRender(sf::RenderTarget& target) const override;

    private:
        // Member static methods
        static sf::Color GetRGBFromHSV(int hue, float saturation, float value);

        // Member methods
        void PushMetaBall(
            float x = Ng::Random::Get<float>(0.0f, Ng::Engine::State::GetContext().GetRenderWindow()->getSize().x),
            float y = Ng::Random::Get<float>(0.0f, Ng::Engine::State::GetContext().GetRenderWindow()->getSize().y),
            const sf::Vector2f& velocity = sf::Vector2f(
                Ng::Random::Get(50.0f, 100.0f) * (Ng::Random::Get<bool>(0.5f) ? -1.0f : 1.0f),
                Ng::Random::Get(50.0f, 100.0f) * (Ng::Random::Get<bool>(0.5f) ? -1.0f : 1.0f)
            )
        );
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
        bool                  m_IsPressed;
        bool                  m_IsPaused;

    }; // class MetaBallState

} // namespace Meta