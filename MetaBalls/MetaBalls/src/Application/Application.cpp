#include "Application.hpp"

#include "States/MetaBallState.hpp"

namespace Meta {

    // Public static methods
    Application& Application::GetInstance() {
        static Application instance;
        return instance;
    }

    // Member constructor
    Application::Application() :
        Ng::Engine::Application(
            1080, 720,
            "MetaBalls",
            sf::Style::Close,
            sf::ContextSettings(0, 0, 8, 1, 1, sf::ContextSettings::Attribute::Default, false)
        ) {

        // Init RenderWindow context
        Ng::Engine::Application::GetContext().SetFramerateLimit(60u);
        Ng::Engine::Application::GetContext().SetVerticalSyncEnabled(true);
        Ng::Engine::Application::GetContext().SetKeyRepeatEnabled(false);

        // Init states
        Ng::Engine::Application::GetStateStack().Push(std::make_unique<MetaBallState>());
    }

    // Member methods
    void Application::OnUpdate() {
        Ng::Engine::Application::GetStateStack().OnUpdate(m_ElapsedTime.asSeconds());
    }

    void Application::OnRender() {
        m_RenderWindow.clear();
        Ng::Engine::Application::GetStateStack().OnRender(m_RenderWindow);
        m_RenderWindow.display();
    }

} // namespace Meta