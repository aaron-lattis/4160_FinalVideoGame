


#include "Box.h"
#include "GameObject.h"
#include <SDL2/SDL.h> 
#include <SDL2/SDL_image.h> 
#include <SDL2/SDL_timer.h>

#ifndef COLLISIONRESPONSE_H
#define COLLISIONRESPONSE_H

class CollisionResponse
{

    public:

        CollisionResponse(SDL_Renderer* r);

        CollisionResponse();

        void collisionResponse(GameObject* player, GameObject* ball);

        ~CollisionResponse();


    private:

        SDL_Renderer* renderer;

        bool stuckOnLeft;
        bool stuckOnRight;
        bool stuckOnTop;
        bool stuckOnBottom;

};



#endif