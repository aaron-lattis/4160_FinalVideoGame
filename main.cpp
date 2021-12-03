
#include "GameEngine.h"

int main ()
{
   GameEngine* engine = new GameEngine();
   
   engine -> init();
   
   while (engine -> get_game_is_running())
   { 
      engine -> set_this_start_time(SDL_GetTicks());
      
      engine -> handleEvents();
      engine -> updateMechanics();
      engine -> renderer();
      
      engine -> set_this_duration(SDL_GetTicks() - engine -> get_this_start_time()) ;
      
      if (engine -> get_this_duration() < engine -> get_frame_duration())
      {
         SDL_Delay(engine -> get_frame_duration() - engine -> get_this_duration());
      }
   }
   
   engine -> quit();
   
   return 0;  
}

