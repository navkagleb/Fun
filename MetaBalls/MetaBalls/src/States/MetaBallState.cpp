#include "MetaBallState.hpp"

#include <Random/Random.hpp>

namespace Meta {

    // Constructor / Destructor
    MetaBallState::MetaBallState() {
        m_MetaBalls.reserve(Ng::Random::Get(2, 3));

        for (std::size_t i = 0; i < m_MetaBalls.capacity(); ++i)
            m_MetaBalls.emplace_back(
                Ng::Random::Get(0.0f, 1080.0f),
                Ng::Random::Get(0.0f, 720.0f),
                50.0f
            );
    }

    MetaBallState::~MetaBallState() {

    }

    // Public methods
    void MetaBallState::OnUpdate(float dt) {
        for (auto& metaBall : m_MetaBalls)
            metaBall.OnUpdate(dt);



        m_Texture.update(m_Pixels.data());
        m_Sprite.setTexture(m_Texture);
    }

    void MetaBallState::OnRender(sf::RenderTarget& target) const {
        for (auto& metaBall : m_MetaBalls)
            metaBall.OnRender(target);

        target.draw(m_Sprite);
    }

} // namespace Meta