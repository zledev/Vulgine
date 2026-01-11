#pragma once

#include <iostream>
#include <GLFW/glfw3.h>

namespace Vulgine
{
    class WindowManager
    {
        GLFWwindow *window;

    public:
        void initWindow(int w, int h, std::string app_title);
        void closeWindow();
        GLFWwindow *getWindow();
    };
}