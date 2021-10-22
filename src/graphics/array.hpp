#ifndef GRAPHICS_ARRAY
#define GRAPHICS_ARRAY

#include <GL/glew.h>

namespace simple_graphics {
    class Array {
    private:
        GLuint vao;
    public:
        Array();
        ~Array();

        void bind();
        void enable();
    };
}

#endif