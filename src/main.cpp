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
            GLuint array[1];
            glGenVertexArrays(1, array);
            glBindVertexArray(array[0]);

            GLfloat vertices[] = {
                -1.0f, -1.0f, 0.0f,
                 1.0f, -1.0f, 0.0f,
                 0.0f,  1.0f, 0.0f
            };

            GLuint buffer[1];
            glGenBuffers(1, buffer);
            glBindBuffer(GL_ARRAY_BUFFER, buffer[0]);
            glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

            glfwSwapInterval(1);
            while (glfwWindowShouldClose(window) == GLFW_FALSE) {
                glClear(GL_COLOR_BUFFER_BIT);

                glEnableVertexAttribArray(0);

                glBindBuffer(GL_ARRAY_BUFFER, buffer[0]);
                glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);

                glDrawArrays(GL_TRIANGLES, 0, 3);

                glDisableVertexAttribArray(0);

                glfwSwapBuffers(window);
                glfwPollEvents();
            }
        }
    }

    glfwTerminate();

    return 0;
}
