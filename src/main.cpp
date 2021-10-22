#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "frontear/window.hpp"

int main() {
    auto x = simple_graphics::Window("SimpleGraphics", 640, 360);

    // a vertex array object can be thought of as an array for all of our vertex buffer objects
    GLuint array[1];
    glGenVertexArrays(1, array);
    glBindVertexArray(array[0]);

    // vertices of the shape
    GLfloat vertices[] = {
        -1.0f, -1.0f, 0.0f,
         1.0f, -1.0f, 0.0f,
         0.0f,  1.0f, 0.0f
    };

    // our vertex buffer object contains the vertex data for our shape
    GLuint buffer[1];
    glGenBuffers(1, buffer);
    glBindBuffer(GL_ARRAY_BUFFER, buffer[0]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // contains our shader details
    GLuint program = glCreateProgram();

    // vertex shader operates on each vertex
    const GLchar* vertex_shader =
    R"glsl(
    #version 330 core

    layout(location = 0) in vec3 coordinates;

    void main() {
        gl_Position.xyz = coordinates;
        gl_Position.w = 1.0;
    }
    )glsl";

    GLuint v_shader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(v_shader, 1, &vertex_shader, nullptr);
    glCompileShader(v_shader);
    glAttachShader(program, v_shader);

    // fragment shaders operate on each sample (glfwWindowHint GLFW_SAMPLES)
    const GLchar* fragment_shader =
    R"glsl(
    #version 330 core

    out vec3 color;

    void main() {
        color = vec3(1, 1, 1);
    }
    )glsl";

    GLuint f_shader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(f_shader, 1, &fragment_shader, nullptr);
    glCompileShader(f_shader);
    glAttachShader(program, f_shader);

    // set our program to be the current program and use it
    glLinkProgram(program);
    glUseProgram(program);

    // detach our shaders from the program, it has its own copy now.
    glDetachShader(program, v_shader);
    glDeleteShader(v_shader);

    glDetachShader(program, f_shader);
    glDeleteShader(f_shader);

    // enable our vertex array object, we generated 1 so get the 0th array object
    glEnableVertexAttribArray(0);
    // define our buffer vertex data, helps in the rendering. 0 here references the first buffer in our array, of which we only have 1.
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);

    while (x.isAlive()) {
        glClear(GL_COLOR_BUFFER_BIT);

        // render a triangle, reading the 0th coordinate as the first, until the 3rd element.
        glDrawArrays(GL_TRIANGLES, 0, 3);

        x.update();
    }

    // clean up our objects
    glDeleteBuffers(1, buffer);
    glDeleteVertexArrays(1, array);
    glDeleteProgram(program);
}