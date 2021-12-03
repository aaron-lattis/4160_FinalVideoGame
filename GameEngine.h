
#include "GameObject.h"
#include "Background.h"
#include "CollisionResponse.h"
#include "ParticleEmitter.h"
#include "GameEnemy.h"
#include "Font.h"


#ifndef GAMEENGINE_H
#define GAMEENGINE_H

class GameEngine
{

public:

    GameEngine();

    ~GameEngine();

    void init();

    void handleEvents();

    void updateMechanics();

    void renderer();

    void quit();

    int get_this_start_time();
    int get_fps_counter();
    int get_last_count_start_time();
    int get_this_duration();
    int get_frame_duration();
    int get_fps();

    void set_this_start_time(int x);
    void set_fps_counter(int x);
    void set_last_count_start_time(int x);
    void set_this_duration(int x);
    void set_frame_duration(int x);
    void set_fps(int x);

    bool get_game_is_running();
    void set_game_is_running(bool x);

private:

    GameObject player1;

    GameObject player2;

    GameObject claw;

    GameEnemy enemy [50];

    SDL_Texture* background;


    SDL_Window* my_window = NULL;
    SDL_Renderer* my_renderer = NULL;
    SDL_Event input;

    int this_start_time;
    int fps_counter;
    int last_count_start_time;
    //int current_fps;
    int this_duration;
    int frame_duration; 
    int fps;

    bool game_is_running;

    ParticleEmitter particleEmitter1;
    ParticleEmitter particleEmitter2;

    int level;

    int speedFromDirection;
    int perpendicularSpeed;

    bool two_players;

    int cntr1;
    int cntr2;

    int levelCntr;

    bool paused;
    bool startScreen;
    bool endScreen;

    Font welcome;
    Font startOnePlayer;
    Font startTwoPlayer;
    Font gamePaused;
    Font keepPlaying;
    Font changeMode;
    Font startOver;
    Font gameOver;
    Font playAgainOnePlayer;
    Font playAgainTwoPlayer;


    

};

#endif