

#include "GameObject.h"


#ifndef GAMEENEMY_H
#define GAMEENEMY_H

class GameEnemy : public GameObject
{

    public:

      void obj_init(int x, int y, int h, int w, const char* img, SDL_Renderer* renderer);

      void obj_update();

      void obj_render();

      bool inPlay();

      void inPlay(bool i);

      int starting_location();



    private:

        bool in_play;

        int startingLocation;




};

#endif