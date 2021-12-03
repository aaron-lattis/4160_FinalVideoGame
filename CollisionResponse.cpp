
#include "CollisionResponse.h"
#include <iostream>


CollisionResponse::CollisionResponse(SDL_Renderer* r)
{
   renderer = r;

   stuckOnLeft = false;
   stuckOnRight = false;
   stuckOnTop = false;
   stuckOnBottom = false;
}

CollisionResponse::CollisionResponse()
{
    
}

CollisionResponse::~CollisionResponse()
{
    
}


void CollisionResponse::collisionResponse(GameObject* player, GameObject* ball)
{

   player -> dead(true);
}

