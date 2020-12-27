#include "MetaBallState.hpp"

#include <cmath>
#include <iostream>

#include <Random/Random.hpp>

namespace Meta {

    // Constructor / Destructor
    MetaBallState::MetaBallState() {
        m_MetaBalls.reserve(Ng::Random::Get(4, 6));

        for (std::size_t i = 0; i < m_MetaBalls.capacity(); ++i)
            m_MetaBalls.emplace_back(
                Ng::Random::Get(0.0f, 1080.0f),
                Ng::Random::Get(0.0f, 720.0f),
                50.0f
            );

        m_Pixels.resize(1080 * 720);
        m_Image.create(1080, 720);
        m_Texture.loadFromImage(m_Image);
    }

    MetaBallState::~MetaBallState() {

    }

    // Public methods
    void MetaBallState::OnUpdate(float dt) {
        for (auto& metaBall : m_MetaBalls)
            metaBall.OnUpdate(dt);

        for (std::size_t i = 0; i < 1080; ++i) {
            for (std::size_t j = 0; j < 720; ++j) {
                float sum = 0.0f;

                for (const auto& metaBall : m_MetaBalls) {
                    const auto& position = metaBall.GetPosition();

                    float dist = std::sqrt(
                        (i - position.x) * (i - position.x) + (j - position.y) * (j - position.y)
                    );

                    sum += 50.f * 150.f / dist;
                }

//                if (sum > 255)
//                    std::cout << "fuck" << std::endl;

//                std::cout << sum << std::endl;

                m_Image.setPixel(i, j, sf::Color(
                    std::max(0, std::min(static_cast<int>(sum), 240)),
                    std::max(0, std::min(static_cast<int>(sum), 240)),
                    std::max(0, std::min(static_cast<int>(sum), 240))
                ));
            }
        }

        m_Texture.update(m_Image);
        m_Sprite.setTexture(m_Texture);
    }

    void MetaBallState::OnRender(sf::RenderTarget& target) const {
        for (auto& metaBall : m_MetaBalls)
            metaBall.OnRender(target);

        target.draw(m_Sprite);
    }

} // namespace Meta