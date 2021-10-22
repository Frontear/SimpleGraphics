#ifndef GRAPHICS_WINDOW
#define GRAPHICS_WINDOW

#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace simple_graphics {
    class Window {
    private:
        GLFWwindow* window = nullptr;
    public:
        Window(const char* title, int width, int height);
        ~Window();

        bool isAlive();
        void update();
    };
}

#endif