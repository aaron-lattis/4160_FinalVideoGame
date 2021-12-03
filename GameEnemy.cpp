


#include "GameEnemy.h"
#include "ImageHandler.h"
#include <stdlib.h>




void GameEnemy::obj_init(int x, int y, int h, int w, const char* img, SDL_Renderer* renderer)
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

    if (y == -25)
        startingLocation = 0;
    else if (x == 900)
        startingLocation = 1;
    else if (y == 600)
        startingLocation = 2;
    else
        startingLocation = 3;


    centerY = obj_rect.y + (0.5 * obj_rect.h);

    centerX = obj_rect.x + (0.5 * obj_rect.w);

    radius = w / 2.0;


}

void GameEnemy::obj_update()
{

   if (!in_play && (xVelocity > 0 || yVelocity > 0))
   {
      in_play = true;
   }

   if (in_play && (obj_rect.x < -25 || obj_rect.x > 900 || obj_rect.y > 600 || obj_rect.y < -25))
   {
        if (startingLocation == 0)
        {
            obj_rect.y = -25;
            obj_rect.x = rand() % 900;
        }
        else if (startingLocation == 1)
        {
            obj_rect.y = rand() % 600;
            obj_rect.x = 900;
        }
        else if (startingLocation == 2)
        {
            obj_rect.y = 600;
            obj_rect.x = rand() % 900;
        }  
        else
        {
            obj_rect.y = rand() % 600;
            obj_rect.x = -25;
        }

        in_play = false;
   }

   obj_rect.x += xVelocity;
   obj_rect.y += yVelocity;

}

void GameEnemy::obj_render()
{

    if (in_play)
        SDL_RenderCopy(obj_renderer, obj_graphic, NULL, &obj_rect);

}

bool GameEnemy::inPlay()
{
   return in_play;
}

int GameEnemy::starting_location()
{
    return  startingLocation;
}

void GameEnemy::inPlay(bool i)
{
    in_play = i;
}