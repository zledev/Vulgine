#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <Window/window.hpp>

namespace Vulgine
{
    void WindowManager::initWindow(int w, int h, std::string app_title)
    {
        if (!glfwInit())
            throw std::runtime_error("Failed to initialize GLFW!");

        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
        glfwWindowHint(GLFW_VISIBLE, GLFW_TRUE);
        this->window = glfwCreateWindow(w, h, app_title.c_str(), nullptr, nullptr);
    }

    GLFWwindow *WindowManager::getWindow()
    {
        if (this->window == nullptr)
            throw std::runtime_error("Window is not yet initialized! Failed to get Window!");

        return this->window;
    }

    void WindowManager::closeWindow()
    {
        glfwDestroyWindow(window);
        glfwTerminate();
    }
}