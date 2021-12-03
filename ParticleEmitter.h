

#include "Particle.h"

#ifndef PARTICLEEMITTER_H
#define PARTICLEEMITTER_H

class ParticleEmitter
{

   public:

    ParticleEmitter(const char* graphic, SDL_Renderer* ren, int X, int Y, int W, int H);
      
    ParticleEmitter();

    ~ParticleEmitter();

    void draw(SDL_Renderer* ren);

    void update();

    void set_x(int x);

    void set_y(int y);

    void finished(bool f);

    bool finished();

    bool compute_finished();



   private:

    Particle particle[50];
       
    int pos_x;
    int pos_y;
    int part_type;

    int max_parts;

    SDL_Renderer* renderer;

    bool finishedEmitting;

    

};
 
#endif

