#include <GL/glew.h>
#include <GLFW/glfw3.h>

int main(int, char**) {
    if (glfwInit() == GLFW_FALSE) {
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);

    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(640, 360, "SimpleGraphics", nullptr, nullptr);
    if (window != nullptr) {
        glfwMakeContextCurrent(window);

        glewExperimental = GL_TRUE;
        if (glewInit() == GLEW_OK) {

            glfwSwapInterval(1);
            while (glfwWindowShouldClose(window) == GLFW_FALSE) {
                glClear(GL_COLOR_BUFFER_BIT);

                glfwSwapBuffers(window);
                glfwPollEvents();
            }
        }
    }

    glfwTerminate();

    return 0;
}
