#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <Engine/engine.hpp>
#include <Engine/engine_info.hpp>

namespace Vulgine
{
    Engine::Engine(WINDOW_SIZE size, std::string app_name, VERSION version)
        : applicationName(app_name),
          appVersion(version)
    {
        this->WINDOW_MANAGER.initWindow(size.width, size.height, app_name);
    }

    void Engine::initVulkan()
    {

        VkInstance instance;

        VkApplicationInfo appInfo{};
        appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
        appInfo.pApplicationName = this->applicationName.c_str();
        appInfo.applicationVersion = VK_MAKE_VERSION(this->appVersion.major,
                                                     this->appVersion.minor,
                                                     this->appVersion.patch);
        appInfo.pEngineName = "Vulgine";
        appInfo.engineVersion = VK_MAKE_VERSION(EngineInfo::EngineVersion.major,
                                                EngineInfo::EngineVersion.minor,
                                                EngineInfo::EngineVersion.patch);
        appInfo.apiVersion = VK_API_VERSION_1_0;

        VkInstanceCreateInfo createInfo{};
        createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
        createInfo.pApplicationInfo = &appInfo;
        createInfo.enabledExtensionCount = 0;
        createInfo.ppEnabledExtensionNames = nullptr;

        createInfo.enabledLayerCount = 0;

        if (vkCreateInstance(&createInfo, nullptr, &instance) != VK_SUCCESS)
            throw std::runtime_error("Failed to create Vulkan Instance!");

        vkDestroyInstance(instance, nullptr);
    }

    void Engine::mainLoop()
    {
        while (!glfwWindowShouldClose(this->WINDOW_MANAGER.getWindow()))
        {
            glfwPollEvents();
        }
    }

    void Engine::start()
    {
        // initVulkan();
        mainLoop();
        cleanUp();
    }

    void Engine::cleanUp()
    {
        this->WINDOW_MANAGER.closeWindow();
    }
}