

#include <iostream>
#include "GameObject.h"
#include "ImageHandler.h"
#include "collisionDetection.h"
#include <stdlib.h>


GameObject::GameObject()
{
   
}


GameObject::~GameObject()
{

}


void GameObject::obj_init(int x, int y, int h, int w, const char* img, SDL_Renderer* renderer)
{
   obj_renderer = renderer;

   movingRight = false;
   movingLeft = false;

   xVelocity = 0;
   yVelocity = 0;

   obj_rect.x = x;
   obj_rect.y = y;
   obj_rect.h = h;
   obj_rect.w = w;


   ImageHandler imgHandler = ImageHandler();

   obj_graphic = imgHandler.handle_image(obj_renderer, img);

   centerY = obj_rect.y + (0.5 * obj_rect.h);

   centerX = obj_rect.x + (0.5 * obj_rect.w);

   radius = w / 2.0;

}


void GameObject::obj_update()
{
   int x1 = obj_rect.x;
   int x2 = obj_rect.x;
   int y1 = obj_rect.y;
   int y2 = obj_rect.y;

   if ((x1 + xVelocity > 850) || (x2 + xVelocity < 0) || (y1 + yVelocity > 550) || (y2 + yVelocity < 0))
   {

   }
   else
   {
      obj_rect.x += xVelocity;

      obj_rect.y += yVelocity;
   }
  

}


void GameObject::obj_render()
{

   SDL_RenderCopy(obj_renderer, obj_graphic, NULL, &obj_rect);
   
}


void GameObject::obj_quit()
{
   SDL_DestroyRenderer(obj_renderer);
   SDL_DestroyTexture(obj_graphic);
}


void GameObject::set_x_velocity(int v)
{
   xVelocity = v;
}


void GameObject::set_y_velocity(int v)
{
   yVelocity = v;
}


int GameObject::get_x_velocity()
{
   return xVelocity;
}


int GameObject::get_y_velocity()
{
   return yVelocity;
}

void GameObject::set_need_to_stop(bool s)
{
   needToStop = s;
}


bool GameObject::get_need_to_stop()
{
   return needToStop;
}


void GameObject::set_moving_right(bool r)
{
   movingRight = r;
}


bool GameObject::get_moving_right()
{
   return movingRight;
}


void GameObject::set_moving_left(bool l)
{
   movingLeft = l;
}

bool GameObject::get_moving_left()
{
   return movingLeft;
}

double GameObject::get_center_x()
{

   centerX = obj_rect.x + (0.5 * obj_rect.w);

   return centerX;
}

double GameObject::get_center_y()
{

   centerY = obj_rect.y + (0.5 * obj_rect.h);

   return centerY;
}

void GameObject::dead(bool d)
{
   is_dead = d;
}
 
bool GameObject::dead()  
{
   return is_dead;
}

double GameObject::get_radius() 
{
   return radius;
} 

const char* GameObject::get_graphic()
{
   return g;
}

void GameObject::set_y(int Y) 
{
   obj_rect.y = Y;
} 

void GameObject::set_x(int X) 
{
   obj_rect.x = X;
} 
