#include "array.hpp"

simple_graphics::Array::Array() {
    glGenVertexArrays(1, &vao);
}

simple_graphics::Array::~Array() {
    glDeleteVertexArrays(1, &vao);
}

void simple_graphics::Array::bind() {
    glBindVertexArray(vao);
}

void simple_graphics::Array::enable() {
    glEnableVertexAttribArray(0);
}