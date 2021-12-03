

#include <iostream>
#include "ImageHandler.h"
#include <stdlib.h>
#include "Font.h"
#include <SDL_ttf.h>



Font::Font()
{
   
}


Font::~Font()
{

}


void Font::obj_init(int x, int y, const char* path, SDL_Renderer* renderer, SDL_Color c, int s, int h, int w)
{



   TTF_Init();

   obj_renderer = renderer;

   font = TTF_OpenFont(path, 50);

   obj_rect.x = x;
   obj_rect.y = y;

   obj_rect.w = w;
   obj_rect.h = h;
  
   color = c;
}

void Font::set_message(const char* m)
{
   SDL_Surface *text_surface;

   if (!(text_surface = TTF_RenderText_Solid(font, m, color)))
    std::cout << "Error \n";

   obj_graphic = SDL_CreateTextureFromSurface(obj_renderer, text_surface);

   SDL_FreeSurface(text_surface);
}

void Font::obj_update()
{

}



void Font::obj_render()
{

   SDL_RenderCopy(obj_renderer, obj_graphic, NULL, &obj_rect);
   
}


void Font::obj_quit()
{
   SDL_DestroyRenderer(obj_renderer);
   SDL_DestroyTexture(obj_graphic);
}


void Font::set_y(int Y) 
{
   obj_rect.y = Y;
} 

void Font::set_x(int X) 
{
   obj_rect.x = X;
} 
