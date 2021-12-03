

#include <stdlib.h>

#include "ParticleEmitter.h"
#include "Particle.h"
#include <SDL2/SDL.h> 
#include <SDL2/SDL_image.h> 
#include <SDL2/SDL_timer.h>



ParticleEmitter::ParticleEmitter(const char* graphic, SDL_Renderer* ren, int X, int Y, int W, int H)
{
    srand(23);

    max_parts = 50;

    renderer = ren;

    int wAndh = 3; 

    for (int i = 0; i < max_parts; i++)
    {
        wAndh = W + rand() % 3 - 2;

        particle[i].p_init(graphic, ren, X + rand() % 26 - 50, Y + rand() % 26 - 50, wAndh, wAndh);

        particle[i].set_x_vel(3.0 - (rand() % 120 - 60) / 10.0);
        particle[i].set_y_vel(0 - (rand() % 120 - 60) / 10.0);
        particle[i].set_lifetime(25 + rand() % 10);
    }
}
      
ParticleEmitter::ParticleEmitter()
{

}

ParticleEmitter::~ParticleEmitter()
{

}

void ParticleEmitter::draw(SDL_Renderer* ren)
{
    for (int i = 0; i < max_parts; i ++)
    {
        particle[i].draw(ren);
    }
}

void ParticleEmitter::update()
{
    for (int i = 0; i < max_parts; i ++)
    {
        particle[i].update();
    }
}

void ParticleEmitter::set_x(int x)
{
    for (int i = 0; i < max_parts; i ++)
    {
        particle[i].set_x(x);
    }
}

void ParticleEmitter::set_y(int y)
{
    for (int i = 0; i < max_parts; i ++)
    {
        particle[i].set_y(y);
    }
}

void ParticleEmitter::finished(bool f)
{
    finishedEmitting = f;
}

bool ParticleEmitter::finished()
{
    return finishedEmitting;
}

bool ParticleEmitter::compute_finished()
{
    for (int i = 0; i < max_parts; i ++)
    {
        if (particle[i].get_lifetime() > 0)
        {
            return false;
        }
    }

    return true;
}



   


 


