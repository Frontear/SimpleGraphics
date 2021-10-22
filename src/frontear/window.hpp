#ifndef FRONTEAR_GRAPHICS
#define FRONTEAR_GRAPHICS

namespace simple_graphics {
    class Window {
    public:
        Window(const char* title, int width, int height);
        ~Window();

        bool isAlive();
        void update();
    };
}

#endif