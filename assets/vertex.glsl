#version 330 core

layout(location = 0) in vec3 coordinate

void main() {
    gl_Position.xyz = coordinate;
    gl_Position.w = 1.0;
}