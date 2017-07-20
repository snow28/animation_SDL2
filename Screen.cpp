#include "Screen.h"
#include <iostream>
#include <iomanip>

namespace caveprogramming{
    void Screen::cleaner() {
	memset(m_buffer, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));
}
    void Screen::setPixel(int x,int y,Uint8 red,Uint8 green,Uint8 blue){
    if(x<0||x>799||y<0||y>599){
            return;
    }
    Uint32 color=0;

    color+=red;
    color<<=8;//8 bit=2 bytes
    color+=green;
    color<<=8;
    color+=blue;
    color<<=8;
    color+=255;

    m_buffer[(y*SCREEN_WIDTH)+x]=color;
}
    void Screen::update(){
    SDL_UpdateTexture(m_texture,NULL,m_buffer,SCREEN_WIDTH*sizeof(Uint32));//last argument determined size of the row, number of bits between the rows
    SDL_RenderClear(m_renderer);
    SDL_RenderCopy(m_renderer,m_texture,NULL,NULL);
    SDL_RenderPresent(m_renderer);
    }

    bool Screen::init(){
        if(SDL_Init(SDL_INIT_VIDEO)<0){
        return false;
    }
    m_window=SDL_CreateWindow("Particle Fire explosion",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,SCREEN_WIDTH,SCREEN_HEIGHT,SDL_WINDOW_SHOWN);//first argument is a name of the window
    if(m_window==NULL){
        SDL_Quit();
        return false;
    }
    m_renderer=SDL_CreateRenderer(m_window,-1,SDL_RENDERER_PRESENTVSYNC);//-1 is a default option,last argument is for refreshing pixels
    m_texture=SDL_CreateTexture(m_renderer,SDL_PIXELFORMAT_RGBA8888,SDL_TEXTUREACCESS_STATIC,SCREEN_WIDTH,SCREEN_HEIGHT);
    if(m_renderer==NULL){
        SDL_DestroyWindow(m_window);
        SDL_Quit();
        return false;
    }
    if(m_texture==NULL){
        SDL_DestroyRenderer(m_renderer);
        SDL_DestroyWindow(m_window);
        SDL_Quit();
        return false;
    }
    m_buffer=new Uint32[SCREEN_WIDTH*SCREEN_HEIGHT];//Uint32 because,for every pixel we need 4 byte,red-1 byte,green 1 byte etc.==4*8=32
        return true;
    }

    bool Screen::processEvents(){
        SDL_Event event;
        while(SDL_PollEvent(&event)){
                if(event.type==SDL_QUIT){//to close the window by the
                    return false;
                }
        }
        return true;
    }

    Screen::Screen():
    m_window(NULL),m_renderer(NULL),m_texture(NULL),m_buffer(NULL){//CONSTRUCTOR

    }
    void Screen::close(){
        delete [] m_buffer;
        SDL_DestroyRenderer(m_renderer);
        SDL_DestroyTexture(m_texture);
        SDL_DestroyWindow(m_window);
        SDL_Quit();
    }
}


