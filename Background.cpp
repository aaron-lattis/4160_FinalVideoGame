
#include <string>
#include <SDL2/SDL.h> 
#include <SDL2/SDL_image.h> 
#include <SDL2/SDL_timer.h>
#include <iostream>
#include "ImageHandler.h"

#include "Background.h"

Background::Background(const char* img, SDL_Renderer* renderer)
{
    
   ImageHandler imgHandler = ImageHandler();

   bg_graphic = imgHandler.handle_image(renderer, img);


   dest1.x = -50;
   dest1.y = 0;
   dest1.h = 480;
   dest1.w = 740;

   dest1_only = true;
   dest1_in_frame = true;
   dest1_moving_in = false;

   dest2.x = 900;
   dest2.y = 0;
   dest2.h = 480;
   dest2.w = 740;

   dest2_only = false; 
   dest2_in_frame = false;
   dest2_moving_in = false;

}

Background::Background()
{

}

Background::~Background()
{

}

void Background::render_bg(SDL_Renderer* renderer)
{
    if (dest1_in_frame) { SDL_RenderCopy(renderer, bg_graphic, NULL, &dest1); }
    if (dest2_in_frame) { SDL_RenderCopy(renderer, bg_graphic, NULL, &dest2); }
}

void Background::set_velocity(int v)
{
    velocity = v;  
}

int Background::get_velocity()
{
    return velocity;
}

void Background::update()
{

    if(dest1_in_frame) { dest1.x -= velocity; }
    if(dest2_in_frame) { dest2.x -= velocity; }

    if((dest1.x > 640 || dest1.x < -740)) { dest1_in_frame = false; dest2_only = true; }
    if((dest2.x > 640 || dest2.x < -740)) { dest2_in_frame = false; dest1_only = true; }

    if (dest1_in_frame && dest1_only && (dest1.x > -25 || dest1.x < -75))
    {
        if(dest1.x > -25)
        {
            dest2.x = -740 + dest1.x;
        }
        else if (dest1.x < -75)
        {
            dest2.x = 665 + dest1.x + 75;  
        }

        dest2_in_frame = true;
        dest1_only = false;
    }

    if (dest2_in_frame && dest2_only && (dest2.x > -25 || dest2.x < -75))
    {
        if(dest2.x > -25)
        {
            dest1.x = -740 + dest2.x;
        }
        else if (dest2.x < -75)
        {
            dest1.x = 665 + dest2.x + 75;  
        }

        dest1_in_frame = true;
        dest2_only = false;
    }
}
    
    
