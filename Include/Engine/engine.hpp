#pragma once

#include <iostream>
#include <Window/window.hpp>
#include <Structs/engine_structs.hpp>

namespace Vulgine
{
    class Engine
    {
        std::string applicationName;
        VERSION appVersion;
        WindowManager WINDOW_MANAGER;

        void initVulkan();
        void mainLoop();
        void cleanUp();

    public:
        Engine(WINDOW_SIZE size, std::string app_name, VERSION version);

        void start();
    };
}