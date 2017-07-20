#ifndef SCREEN_H_
#define SCREEN_H_
#include <iostream>
#include "SDL.h"
#include <windows.h>

namespace caveprogramming{
class Screen{
public:
    const static int SCREEN_WIDTH=800;
    const static int SCREEN_HEIGHT=600;
private:
    SDL_Window *m_window;//m_ because it is member variables
    SDL_Renderer *m_renderer;
    SDL_Texture *m_texture;
    Uint32 *m_buffer;
public:
    bool init();
    bool processEvents();
    Screen();
    void close();
    void update();
    void setPixel(int x,int y,Uint8 red,Uint8 green,Uint8 blue);
    void cleaner();
};


}



#endif // SCREEN_H_
