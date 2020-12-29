#include "MetaBallState.hpp"

#include <iostream>

#include <imgui.h>

#include <Random/Random.hpp>

namespace Meta {

    // Constructor / Destructor
    MetaBallState::MetaBallState() :
        m_Scale(150.0f),
        m_IsColored(false),
        m_IsImGui(false),
        m_IsMetaBallOutline(false) {

        // Init MetaBalls
        m_MetaBalls.reserve(Ng::Random::Get(4, 6));

        for (std::size_t i = 0; i < m_MetaBalls.capacity(); ++i)
            PushMetaBall();

        // Init SFML
        m_Image.create(
            Ng::Engine::State::GetContext().GetRenderWindow()->getSize().x,
            Ng::Engine::State::GetContext().GetRenderWindow()->getSize().y
        );
        m_Texture.loadFromImage(m_Image);
    }

    MetaBallState::~MetaBallState() {

    }

    // Public methods
    void MetaBallState::OnKeyPressed(const sf::Event& event) {
        if (event.key.code == sf::Keyboard::Escape)
            m_IsImGui = !m_IsImGui;
    }

    void MetaBallState::OnUpdate(float dt) {
        for (auto& metaBall : m_MetaBalls)
            metaBall.OnUpdate(dt);

        for (std::size_t x = 0; x < Ng::Engine::State::GetContext().GetRenderWindow()->getSize().x; ++x) {
            for (std::size_t y = 0; y < Ng::Engine::State::GetContext().GetRenderWindow()->getSize().y; ++y) {
                int factor = std::accumulate(
                    m_MetaBalls.begin(),
                    m_MetaBalls.end(),
                    0.0f,
                    [&](float init, const MetaBall& ball) {
                        return init + ball.GetRadius() * m_Scale / ball.GetDistance(x, y);
                    }
                );

                m_Image.setPixel(x, y, GetColor(factor));
            }
        }

        m_Texture.update(m_Image);
        m_Sprite.setTexture(m_Texture);

        // ImGui
        if (m_IsImGui) {
            ImGui::Begin("Settings");

            if (ImGui::Button("Push MetaBall"))
                PushMetaBall();

            ImGui::SameLine();

            if (ImGui::Button("Pop MetaBall"))
                PopMetaBall();

            ImGui::Checkbox("IsColored", &m_IsColored);
            ImGui::SameLine();
            ImGui::Checkbox("IsMetaBallOutline", &m_IsMetaBallOutline);

            ImGui::SliderFloat("Scale", &m_Scale, 10.0f, 300.0f);

            ImGui::End();
        }
    }

    void MetaBallState::OnRender(sf::RenderTarget& target) const {
        target.draw(m_Sprite);

        if (m_IsMetaBallOutline)
            for (auto& ball : m_MetaBalls)
                ball.OnRender(target);
    }

    // Member static methods
    sf::Color MetaBallState::GetRGBFromHSV(int hue, float saturation, float value) {
        hue %= 360;
        
        while (hue < 0) 
            hue += 360;

        saturation = std::min(1.0f, std::max(0.f, saturation));
        value      = std::min(1.0f, std::max(0.f, value));

        float f    = static_cast<float>(hue) / 60.0f - std::floor(static_cast<float>(hue) / 60.0f);
        float p    = value * (1.0f - saturation);
        float q    = value * (1.0f - saturation * f);
        float t    = value * (1.0f - saturation * (1.0f - f));

        switch (hue / 60) {
            default:
            case 0:
                return sf::Color::Transparent;

            case 1:
                return sf::Color(q * 255, value * 255, p * 255);

            case 2:
                return sf::Color(p * 255, value * 255, t * 255);

            case 3:
                return sf::Color(p * 255, q * 255, value * 255);

            case 4:
                return sf::Color(t * 255, p * 255, value * 255);

            case 5:
                return sf::Color(value * 255, p * 255, q * 255);

            case 6:
                return sf::Color(value * 255, t * 255, p * 255);
        }
    }

    // Member methods
    void MetaBallState::PushMetaBall() {
        m_MetaBalls.emplace_back(
            Ng::Random::Get(0.0f, 1080.0f),
            Ng::Random::Get(0.0f, 720.0f),
            Ng::Random::Get(20.0f, 100.0f),
            sf::Vector2f(
                Ng::Random::Get(50.0f, 100.0f) * (Ng::Random::Get<bool>(0.5f) ? -1.0f : 1.0f),
                Ng::Random::Get(50.0f, 100.0f) * (Ng::Random::Get<bool>(0.5f) ? -1.0f : 1.0f)
            )
        );
    }

    void MetaBallState::PopMetaBall() {
        if (!m_MetaBalls.empty())
            m_MetaBalls.pop_back();
    }

    sf::Color MetaBallState::GetColor(int factor) const {
        if (!m_IsColored) {
            factor = std::max(0, std::min(factor, 240));
            return sf::Color(factor, factor, factor);
        }

        return GetRGBFromHSV(std::max(0, std::min(factor, 359)), 1.0f, 1.0f);
    }

} // namespace Meta