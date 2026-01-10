#pragma once

namespace Vulgine
{
    class Engine
    {
    public:
        void start()
        {
            initVulkan();
            mainLoop();
            cleanUp();
        }

    private:
        void initVulkan() {}
        void mainLoop() {}
        void cleanUp() {}
    };
}