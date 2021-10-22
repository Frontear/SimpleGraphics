#include <string>
#include <iostream>

#include "window.hpp"

simple_graphics::Window::Window(const char* title, int width, int height) {
    if (glfwInit() == GLFW_TRUE) {
        glfwWindowHint(GLFW_SAMPLES, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);

        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        window = glfwCreateWindow(width, height, title, nullptr, nullptr);
        if (window != nullptr) {
            glfwMakeContextCurrent(window);

            glewExperimental = GL_TRUE;
            if (glewInit() == GLEW_OK) {
                glfwSwapInterval(1);
            }
        }
    }
}

simple_graphics::Window::~Window() {
    glfwTerminate();
}

bool simple_graphics::Window::isAlive() {
    return glfwWindowShouldClose(window) == GLFW_FALSE;
}

void simple_graphics::Window::update() {
    glfwSwapBuffers(window);
    glfwPollEvents();
}