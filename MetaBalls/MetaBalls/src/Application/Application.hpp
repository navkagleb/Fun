#pragma once

#include <Engine/Application/Application.hpp>

namespace Meta {

    class Application : public Ng::Engine::Application {
    public:
        // Constructor / Destructor
        Application(const Application& other) = delete;
        ~Application() override = default;

        // Public static methods
        static Application& GetInstance();

        // Operators
        Application& operator=(const Application& other) = delete;

    private:
        // Member constructor
        Application();

        // Member methods
        void OnUpdate() override;
        void OnRender() override;

    }; // class Application

} // namespace Meta
