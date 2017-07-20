#ifndef PARTICLE_H_
#define PARTICLE_H_
#include "Screen.h"

struct Particle{
    double m_x;
    double m_y;

    double m_speed;
    double m_direction;

public:
    Particle();
    void update(int interaval);

};





#endif // PARTICLE_H_
