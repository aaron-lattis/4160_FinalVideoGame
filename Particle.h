#include <SDL2/SDL.h> 
#include <SDL2/SDL_image.h> 
#include <SDL2/SDL_timer.h>

#ifndef PARTICLE_H
#define PARTICLE_H

class Particle
{

   public:

    void p_init(const char* graphic, SDL_Renderer* ren, int X, int Y, int W, int H);
      
    Particle();

    ~Particle();

    void draw(SDL_Renderer* ren);

    void update();

    void set_y_vel(float y);

    void set_x_vel(float x);

    void set_lifetime(int l);

    void set_x(int X);

    void set_y(int Y);

    int get_lifetime();


   private:

    SDL_Renderer* renderer;

    SDL_Rect obj_rect; 

    SDL_Rect src_rect;

    float x;
    float y;
    float x_vel;
    float y_vel;

    int w;
    int h;

    int state;
    int lifetime;

    SDL_Texture* obj_graphic;

    

};
 
#endif

