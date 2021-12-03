
#include "Box.h"
#include <string>
#include <SDL2/SDL.h> 
#include <SDL2/SDL_image.h> 
#include <SDL2/SDL_timer.h>
#include "Background.h"


#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

class GameObject
{
   public:

      GameObject();

      ~GameObject();

      void obj_init(int x, int y, int h, int w, const char* img, SDL_Renderer* renderer);

      void obj_update();

      void obj_render();

      void obj_quit();

      void set_x_velocity(int v);

      void set_y_velocity(int v);

      int get_x_velocity();

      int get_y_velocity();

      void set_need_to_stop(bool s);

      bool get_need_to_stop();

      void set_moving_right(bool r);

      bool get_moving_right();

      void set_moving_left(bool r);

      bool get_moving_left();

      double get_center_x();

      double get_center_y(); 

      void dead(bool d);

      bool dead();

      double get_radius();

      const char* get_graphic();

      void set_y(int Y);

      void set_x(int X);


   protected:

     
     const char* g;

      SDL_Renderer* obj_renderer;

      SDL_Texture* obj_graphic;

      SDL_Rect obj_rect; 
      SDL_Rect src_rect;

      
      bool needToStop;

      bool movingRight;
      bool movingLeft;

      int xVelocity;
      int yVelocity;

      bool is_dead;

      double radius;

      double centerX;
      double centerY;
     

};
 
#endif

