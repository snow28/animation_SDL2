#include <iostream>
#include "SDL.h"
#include <windows.h>
#include "Screen.h"
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "Swarm.h"
#include "particle.h"
using namespace std;
using namespace caveprogramming;


int main(int argc, char* args[]){
    srand(time(NULL));

    Screen screen;
    if(screen.init()==false){
        cout<<"Error initialising SDL"<<endl;
    }

    Swarm swarm;
    const Particle *const pParticles=swarm.get_Particles();

    while(true){
        int elapsed=SDL_GetTicks();//getting ticks

        screen.cleaner();
        swarm.update(elapsed);
        unsigned char red=(unsigned char)((1+sin(elapsed*0.001))*128);//unsigned char to get only values in range [0,255]
        unsigned char green=(unsigned char)((1+sin(elapsed*0.002))*128);
        unsigned char blue=(unsigned char)((1+sin(elapsed*0.003))*128);


        for(int i=0;i<Swarm::NPARTICLES;i++){
            Particle particle=pParticles[i];
            int x=(particle.m_x+1)*Screen::SCREEN_WIDTH/2;
            int y=(particle.m_y+1)*Screen::SCREEN_WIDTH/2-100;

            screen.setPixel(x,y,red,green,blue);
        }
        screen.update();
        if(screen.processEvents()==false){
            break;
        }
    }

    screen.close();
    return 0;
}
