
#include "Particle.h"
#include <SDL2/SDL.h> 
#include <SDL2/SDL_image.h> 
#include <SDL2/SDL_timer.h>
#include "ImageHandler.h"
#include <stdlib.h>


void Particle::p_init(const char* graphic, SDL_Renderer* ren, int X, int Y, int W, int H)
{

    renderer = ren;

    ImageHandler imgHandler = ImageHandler();

    obj_graphic = imgHandler.handle_image(renderer, graphic);

    obj_rect.x = X;
    obj_rect.y = Y;
    obj_rect.w = W;
    obj_rect.h = H;

    x = X;
    y = Y;
    w = W;
    h = H;

    
}
      
Particle::Particle()
{

}

Particle::~Particle()
{

}

void Particle::draw(SDL_Renderer* ren)
{
    if (lifetime > 0)
    {
        SDL_RenderCopy(ren, obj_graphic, NULL, &obj_rect);
    }
}

void Particle::update()
{
    x += x_vel;
    y += y_vel;

    if (lifetime > 0)
    {
        obj_rect.x = (int) x;
        obj_rect.y = (int) y;

        obj_rect.w = (int) w/2 + w * (int) (10 * lifetime / 100);
        obj_rect.h = (int) h/2 + h * (int) (10 * lifetime / 100);

    }

    lifetime -= 1;

}

void Particle::set_y_vel(float y)
{
    y_vel = y;
}

void Particle::set_x_vel(float x)
{
    x_vel = x;
}

void Particle::set_lifetime(int l)
{
    lifetime = l;
}

void Particle::set_x(int X)
{
    obj_rect.x = X;
    x = X;
}

void Particle::set_y(int Y)
{
    obj_rect.y = Y;
    y = Y;
}

int Particle::get_lifetime()
{
    return lifetime;
}