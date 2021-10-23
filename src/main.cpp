#include <GL/glew.h>
#include <GLFW/glfw3.h>

GLFWwindow* create_window(int width, int height, const char* title);
void destroy();

int main(int, char**) {
    GLFWwindow* window = create_window(640, 360, "SimpleGraphics");

    if (window != nullptr) {
        while (glfwWindowShouldClose(window) == GLFW_FALSE) {
            glClear(GL_COLOR_BUFFER_BIT);

            glfwSwapBuffers(window);
            glfwPollEvents();
        }
    }

    destroy();

    return 0;
}

GLFWwindow* create_window(int width, int height, const char* title) {
    if (glfwInit() == GLFW_TRUE) {
        glfwWindowHint(GLFW_SAMPLES, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        GLFWwindow* window = glfwCreateWindow(width, height, title, nullptr, nullptr);
        if (window != nullptr) {
            glfwMakeContextCurrent(window);

            glewExperimental = GL_TRUE;
            if (glewInit() == GLEW_OK) {
                glfwSwapInterval(1);

                return window;
            }
        }
    }

    return nullptr;
}

void destroy() {
    glfwTerminate();
}