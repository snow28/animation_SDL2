#ifndef SWARM_H_
#define SWARM_H_

#include "particle.h"
namespace caveprogramming{

class Swarm{
public:
    const static int NPARTICLES=60000;
private:
    Particle *m_pParticles;
    int lastTime;
public:
    Swarm();
    ~Swarm();
    void update(int elapsed);
    const Particle * const get_Particles(){return m_pParticles;}

};


}//namespace cave*
#endif // PARTICLE_H_

