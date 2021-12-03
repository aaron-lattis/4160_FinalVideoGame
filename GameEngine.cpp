
#include <iostream>
#include "GameEngine.h"
#include "Background.h"
#include <SDL.h>
#include "Box.h"
#include "collisionDetection.h"
#include "CollisionResponse.h"
#include "ParticleEmitter.h"
#include "Particle.h"
#include <stdlib.h>
#include "GameEnemy.h"
#include "ImageHandler.h"


GameEngine::GameEngine()
{

}


GameEngine::~GameEngine()
{

}

//initializes the Game Engine
void GameEngine::init()
{

   fps = 60;
   frame_duration = 1000 / fps;

   //Screen dimension
   const int SCREEN_WIDTH = 900;
   const int SCREEN_HEIGHT = 600;

   if (SDL_Init(SDL_INIT_EVERYTHING) != 0) 
   { 
      std::cout << "Error initializing SDL: " << SDL_GetError() << std::endl; 
   }

   //Enable gpu_enhanced textures
   IMG_Init(IMG_INIT_PNG);
  
   my_window = SDL_CreateWindow("my_game", 
			       SDL_WINDOWPOS_CENTERED, 
			       SDL_WINDOWPOS_CENTERED, 
			       SCREEN_WIDTH,
			       SCREEN_HEIGHT, 0);
   my_renderer = SDL_CreateRenderer(my_window,-1,0);

   level = 1;

   player1.obj_init(240, 275, 50, 50, "face1.png", my_renderer);

   player2.obj_init(610, 275, 50, 50, "face2.png", my_renderer);

   SDL_Color c = {255, 160, 122};

   c.a = 255;

   welcome.obj_init(200, 50, "./fonts/font3.ttf", my_renderer, c, 70, 125, 500);
   startOnePlayer.obj_init(150, 250, "./fonts/font3.ttf", my_renderer, c, 70, 75, 600);
   startTwoPlayer.obj_init(150, 350, "./fonts/font3.ttf", my_renderer, c, 70, 75, 600);
   gamePaused.obj_init(250, 50, "./fonts/font3.ttf", my_renderer, c, 70, 100, 400);
   keepPlaying.obj_init(150, 250, "./fonts/font3.ttf", my_renderer, c, 70, 75, 600);
   gameOver.obj_init(250, 50, "./fonts/font3.ttf", my_renderer, c, 70, 125, 400);
   playAgainOnePlayer.obj_init(150, 250, "./fonts/font3.ttf", my_renderer, c, 70, 75, 600);
   playAgainTwoPlayer.obj_init(150, 350, "./fonts/font3.ttf", my_renderer, c, 70, 75, 600);

   welcome.set_message("Welcome to my game!!");
   startOnePlayer.set_message("Press 'o' to start a one player game!");
   startTwoPlayer.set_message("Press 't' to start a two player game!");
   gamePaused.set_message("Game paused!!");
   keepPlaying.set_message("Press the space bar to continue playing!");
   gameOver.set_message("Game over!!");
   playAgainOnePlayer.set_message("Press o to start a new one player game!");
   playAgainTwoPlayer.set_message("Press t to start a new two player game!");


   //set up the 40 enemy dots, 10 on each side of the screen
   for (int i = 0; i < 40; i ++)
   {  
      if(i < 10)
      {
         enemy[i].obj_init(-25, rand() % 600, 25, 25, "dot.png", my_renderer);
      }
      else if (i < 20)
      {
         enemy[i].obj_init(900, rand() % 600, 25, 25, "dot.png", my_renderer);
      }
      else if (i < 30)
      {
         enemy[i].obj_init(rand() % 900, -25, 25, 25, "dot.png", my_renderer);
      }
      else
      {
         enemy[i].obj_init(rand() % 900, 600, 25, 25, "dot.png", my_renderer);
      }
   }

   speedFromDirection = 4;
   perpendicularSpeed = 2;

   levelCntr = 0;

   startScreen = true;
   endScreen = false;
   paused = false;


   ImageHandler imgHandler = ImageHandler();

   background = imgHandler.handle_image(my_renderer, "floor.PNG");

   particleEmitter1 = ParticleEmitter("face1.png", my_renderer, 250, 250, 5, 5);
   particleEmitter2 = ParticleEmitter("face2.png", my_renderer, 250, 250, 5, 5);

   cntr1 = 0;
   cntr2 = 0;


   
   this_start_time = 0;
   fps_counter = 0;
   last_count_start_time = 0;
   //current_fps = 0;
   this_duration = 0;
   //frame_duration = 0; 
   game_is_running = true;


   two_players = false;

}
   
//Responds to relevent key presses
void GameEngine::handleEvents()
{

   SDL_Event game_event;
   SDL_PollEvent(&game_event);

   if (game_event.type == SDL_QUIT) { game_is_running = false; }

   if (startScreen)
   {

      if (game_event.type == SDL_KEYDOWN)
      {
         switch (game_event.key.keysym.sym)
         {
            
            case SDLK_o: 
               startScreen = false; 
               break; 

            case SDLK_t: 
               startScreen = false;
               two_players = true;
               break;
         }

      }
   }
   else if (endScreen)
   {

      if (game_event.type == SDL_KEYDOWN)
      {
         switch (game_event.key.keysym.sym)
         {
            
            case SDLK_o: 

               endScreen = false;
               two_players = false;
               player1.dead(false);
               player2.dead(false);

               player1.obj_init(240, 275, 50, 50, "face1.png", my_renderer);
               player2.obj_init(610, 275, 50, 50, "face2.png", my_renderer);

               for (int i = 0; i < 40; i ++)
               {  
                  if(i < 10)
                  {
                      enemy[i].obj_init(-25, rand() % 600, 25, 25, "dot.png", my_renderer);
                  }
                  else if (i < 20)
                  {
                     enemy[i].obj_init(900, rand() % 600, 25, 25, "dot.png", my_renderer);
                  }
                  else if (i < 30)
                  {
                     enemy[i].obj_init(rand() % 900, -25, 25, 25, "dot.png", my_renderer);
                  }
                  else
                  {
                     enemy[i].obj_init(rand() % 900, 600, 25, 25, "dot.png", my_renderer);
                  }
                  enemy[i].inPlay(false);
               }

               break; 

            case SDLK_t: 

               endScreen = false;
               two_players = true;
               player1.dead(false);
               player2.dead(false);
               
               player1.obj_init(240, 275, 50, 50, "face1.png", my_renderer);
               player2.obj_init(610, 275, 50, 50, "face2.png", my_renderer);

               for (int i = 0; i < 40; i ++)
               {  
                  if(i < 10)
                  {
                      enemy[i].obj_init(-25, rand() % 600, 25, 25, "dot.png", my_renderer);
                  }
                  else if (i < 20)
                  {
                     enemy[i].obj_init(900, rand() % 600, 25, 25, "dot.png", my_renderer);
                  }
                  else if (i < 30)
                  {
                     enemy[i].obj_init(rand() % 900, -25, 25, 25, "dot.png", my_renderer);
                  }
                  else
                  {
                     enemy[i].obj_init(rand() % 900, 600, 25, 25, "dot.png", my_renderer);
                  }
                  enemy[i].inPlay(false);
               }

               break;
         }
      }
   }
   else if (!paused)
   {
      if (game_event.type == SDL_KEYDOWN)
      {
         switch (game_event.key.keysym.sym)
         {
            case SDLK_SPACE:
               paused = true; 
               break; 
         }
      }

      if (game_event.type == SDL_KEYDOWN)
      {
         switch (game_event.key.keysym.sym)
         {
            
            case SDLK_a: 
               player1.set_x_velocity(-3); 
               break; 

            case SDLK_d: 
               player1.set_x_velocity(3);
               break;

            case SDLK_s: 
               player1.set_y_velocity(3);
               break;

            case SDLK_w: 
               player1.set_y_velocity(-3);
               break;
         }
      }
      else if (game_event.type == SDL_KEYUP)
      {
         switch (game_event.key.keysym.sym)
         {
            
            case SDLK_a: 
               if (player1.get_x_velocity() == -3) { player1.set_x_velocity(0); }
               break;

            case SDLK_d: 
              if (player1.get_x_velocity() == 3) { player1.set_x_velocity(0); }
              break;

            case SDLK_s: 
              if (player1.get_y_velocity() == 3) { player1.set_y_velocity(0); }
              break;

            case SDLK_w: 
              if (player1.get_y_velocity() == -3) { player1.set_y_velocity(0); }
              break;
         }  
      }

      if (game_event.type == SDL_KEYDOWN)
         {
            switch (game_event.key.keysym.sym)
            { 
               case SDLK_e: 
                  if (two_players) { two_players = false; } 
                  else if (!two_players) { two_players = true; }
                  break; 

            }
         }

      if (two_players)
      {
         if (game_event.type == SDL_KEYDOWN)
         {
            switch (game_event.key.keysym.sym)
            {
               
               case SDLK_LEFT: 
                  player2.set_x_velocity(-3); 
                  break; 

               case SDLK_RIGHT: 
                  player2.set_x_velocity(3);
                  break;

               case SDLK_DOWN: 
                  player2.set_y_velocity(3);
                  break;

               case SDLK_UP: 
                  player2.set_y_velocity(-3);
                  break;
            }
         }
         else if (game_event.type == SDL_KEYUP)
         {
            switch (game_event.key.keysym.sym)
            {
               
               case SDLK_LEFT: 
               if (player2.get_x_velocity() == -3) { player2.set_x_velocity(0); }
               break;

               case SDLK_RIGHT: 
               if (player2.get_x_velocity() == 3) { player2.set_x_velocity(0); }
               break;

               case SDLK_DOWN: 
               if (player2.get_y_velocity() == 3) { player2.set_y_velocity(0); }
               break;

               case SDLK_UP: 
               if (player2.get_y_velocity() == -3) { player2.set_y_velocity(0); }
               break;

            }  
         }
      }

      for (int i = 0; i < 40; i += 3)
      {  
         srand(17);

         if (!enemy[i].inPlay())
         {
            if (enemy[i].starting_location() == 0)
            {
               enemy[i].set_y_velocity(rand() % speedFromDirection + 1);
               enemy[i].set_x_velocity(rand() % perpendicularSpeed + 1 - (perpendicularSpeed/2));
            }
            else if (enemy[i].starting_location() == 1)
            {
               enemy[i].set_y_velocity(rand() % perpendicularSpeed + 1 - (perpendicularSpeed/2));
               enemy[i].set_x_velocity(rand() % speedFromDirection + 1 - (speedFromDirection + 1));
            }
            else if (enemy[i].starting_location() == 2)
            {
               enemy[i].set_y_velocity(rand() % speedFromDirection + 1 - (speedFromDirection + 1));
               enemy[i].set_x_velocity(rand() % perpendicularSpeed + 1 - (perpendicularSpeed/2));
            }  
            else
            {
               enemy[i].set_y_velocity(rand() % perpendicularSpeed + 1 - (perpendicularSpeed/2));
               enemy[i].set_x_velocity(rand() % speedFromDirection + 1);
            }
         }
      }
   }
   else if (paused)
   {
      player1.set_x_velocity(0);
      player1.set_y_velocity(0);
      if (two_players)
      {
         player2.set_x_velocity(0);
         player2.set_y_velocity(0);
      }

      if (game_event.type == SDL_KEYDOWN)
      {
         switch (game_event.key.keysym.sym)
         {
            
            case SDLK_SPACE: 
               paused = false; 
               break; 
         }
      }
   }
}
   
//updates game objects
void GameEngine::updateMechanics()
{

   if (!paused && !startScreen && !endScreen)
   {

      player1.obj_update();
   
      for (int i = 0; i < 40; i ++)
      {  
         enemy[i].obj_update();

         if (collisionDetection(enemy[i].get_center_x(), enemy[i].get_center_y(), enemy[i].get_radius(), player1.get_center_x(), player1.get_center_y(), player1.get_radius()))
         {

            particleEmitter1.set_x((int) player1.get_center_x());
            particleEmitter1.set_y((int) player1.get_center_y());

            player1.set_y_velocity(0);
            player1.set_x_velocity(0);

            player1.dead(true);
         }       
      }

      if (player1.dead())
      {
         particleEmitter1.update();
      }

      if (two_players)
      {
         player2.obj_update();
   
         for (int i = 0; i < 40; i ++)
         {

            if (collisionDetection(enemy[i].get_center_x(), enemy[i].get_center_y(), enemy[i].get_radius(), player2.get_center_x(), player2.get_center_y(), player2.get_radius()))
            {

               particleEmitter2.set_x((int) player2.get_center_x());
               particleEmitter2.set_y((int) player2.get_center_y());

               player2.set_y_velocity(0);
               player2.set_x_velocity(0);

               player2.dead(true);
            }
         }

         if(player2.dead())
         {
            particleEmitter2.update();
         }

         if (player2.dead())
         {
            cntr2 ++;

            if (cntr2 > 100)
            {
               player2.dead(false);

               cntr2 = 0;

               particleEmitter2 = ParticleEmitter("face2.png", my_renderer, 250, 250, 5, 5);

               level = 1;
               levelCntr = 0;

               endScreen = true;
            }
         }
      }

      if (player1.dead())
      {
         cntr1 ++;

         if (cntr1 > 100)
         {
            player1.dead(false);

            cntr1 = 0;

            particleEmitter1 = ParticleEmitter("face1.png", my_renderer, 250, 250, 5, 5);

            level = 1;
            levelCntr = 0;

            endScreen = true;
         }
      }
   }
}  

//renders to the screen
void GameEngine::renderer()
{
   SDL_RenderClear(my_renderer);

   if(startScreen)
   {

      SDL_SetRenderDrawColor(my_renderer, 140, 210, 180, 100);
      SDL_RenderFillRect(my_renderer, NULL);

      welcome.obj_render();

      startOnePlayer.obj_render();
      startTwoPlayer.obj_render();

   }
   else if (endScreen)
   {

      SDL_SetRenderDrawColor(my_renderer, 140, 210, 180, 100);
      SDL_RenderFillRect(my_renderer, NULL);

      gameOver.obj_render();

      playAgainOnePlayer.obj_render();
      playAgainTwoPlayer.obj_render();

   }
   else 
   {      

      SDL_SetRenderDrawColor(my_renderer, 140, 210, 180, 100);
      SDL_RenderFillRect(my_renderer, NULL);

      if (!player1.dead())
      {
         player1.obj_render();
      }
      else
      {
         particleEmitter1.draw(my_renderer);
      }
      
      if(two_players)
      {
         if (!player2.dead())
         {
            player2.obj_render();
         }
         else
         {
            particleEmitter2.draw(my_renderer);
         }
      }
      
      for (int i = 0; i < 40; i ++)
      {  
         enemy[i].obj_render();
      }

      if (paused)
      {
   
         gamePaused.obj_render();
         keepPlaying.obj_render();

      }
   }

   SDL_RenderPresent(my_renderer);
}
   

void GameEngine::quit()
{
   SDL_DestroyRenderer(my_renderer);
   SDL_DestroyWindow(my_window);

   IMG_Quit();
   SDL_Quit();

   player1.obj_quit();
   player2.obj_quit();
   
}


int GameEngine::get_this_start_time()
{
   return this_start_time;
}

int GameEngine::get_fps_counter()
{
   return fps_counter;
}

int GameEngine::get_last_count_start_time()
{
   return last_count_start_time;
}

int GameEngine::get_this_duration()
{
   return this_duration;
}

int GameEngine::get_frame_duration()
{
   return frame_duration;
}

int GameEngine::get_fps()
{
   return fps;
}

void GameEngine::set_this_start_time(int x)
{
   this_start_time = x;
}

void GameEngine::set_fps_counter(int x)
{
   fps_counter = x;
}

void GameEngine::set_last_count_start_time(int x)
{
   last_count_start_time = x;
}

void GameEngine::set_this_duration(int x)
{
   this_duration = x;
}

void GameEngine::set_frame_duration(int x)
{
   frame_duration = x;
}

void GameEngine::set_fps(int x)
{
   fps = x;
}

bool GameEngine::get_game_is_running()
{
   return game_is_running;
}

void GameEngine::set_game_is_running(bool x)
{
   game_is_running = x;
}



