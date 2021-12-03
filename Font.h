
#include <string>
#include <SDL2/SDL.h> 
#include <SDL2/SDL_image.h> 
#include <SDL2/SDL_timer.h>
#include <SDL_ttf.h>



#ifndef FONT_H
#define FONT_H

class Font
{
   public:

      Font();

      ~Font();

      void obj_init(int x, int y, const char* path, SDL_Renderer* renderer, SDL_Color c, int s, int h, int w);

      void set_message(const char* m);

      void obj_update();

      void obj_render();

      void obj_quit();

      void set_y(int Y);

      void set_x(int X);


   protected:

     
      SDL_Color color;

      TTF_Font *font;

      int size;

      SDL_Renderer* obj_renderer;

      SDL_Texture* obj_graphic;

      SDL_Rect obj_rect; 
      SDL_Rect src_rect;    

};
 
#endif

