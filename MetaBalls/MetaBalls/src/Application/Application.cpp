#include "Application.hpp"

#include <filesystem>

#include <imgui-SFML.h>

#include "States/MetaBallState.hpp"

namespace Meta {

    // Destructor
    Application::~Application() {
        ImGui::SFML::Shutdown();
    }

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

        // Init icon
        if (!m_Icon.loadFromFile("../../MetaBalls/media/Images/MainIcon.png"))
            throw std::invalid_argument("Meta::Application::Application: Failed to load the icon");

        // Init RenderWindow context
        Ng::Engine::Application::GetContext().SetFramerateLimit(120u);
        Ng::Engine::Application::GetContext().SetVerticalSyncEnabled(true);
        Ng::Engine::Application::GetContext().SetKeyRepeatEnabled(false);
        Ng::Engine::Application::GetContext().GetRenderWindow()->setIcon(
            m_Icon.getSize().x,
            m_Icon.getSize().y,
            m_Icon.getPixelsPtr()
        );

        // Init ImGui-SFML
        ImGui::SFML::Init(m_RenderWindow);

        // Init states
        Ng::Engine::Application::GetStateStack().Push(std::make_unique<MetaBallState>());
    }

    // Member methods
    void Application::OnPollEvent() {
        sf::Event event{};

        while (m_RenderWindow.pollEvent(event)) {
            ImGui::SFML::ProcessEvent(event);

            if (event.type == sf::Event::Closed)
                m_RenderWindow.close();

            if (event.type == sf::Event::MouseMoved)
                Ng::Engine::Application::GetStateStack().OnMouseMoved(event);

            if (event.type == sf::Event::MouseButtonPressed)
                Ng::Engine::Application::GetStateStack().OnMouseButtonPressed(event);

            if (event.type == sf::Event::MouseButtonReleased)
                Ng::Engine::Application::GetStateStack().OnMouseButtonReleased(event);

            if (event.type == sf::Event::KeyPressed)
                Ng::Engine::Application::GetStateStack().OnKeyPressed(event);
        }
    }

    void Application::OnUpdate() {
        ImGui::SFML::Update(m_RenderWindow, m_ElapsedTime);

        Ng::Engine::Application::GetStateStack().OnUpdate(m_ElapsedTime.asSeconds());
    }

    void Application::OnRender() {
        m_RenderWindow.clear();

        Ng::Engine::Application::GetStateStack().OnRender(m_RenderWindow);
        ImGui::SFML::Render(m_RenderWindow);
        m_RenderWindow.display();
    }

} // namespace Meta