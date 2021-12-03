

#ifndef BACKGROUND_H
#define BACKGROUND_H

class Background
{
   public:

        Background(const char* img, SDL_Renderer* renderer);

        Background();

        ~Background();

        void render_bg(SDL_Renderer* renderer);

        void set_velocity(int v);

        int get_velocity();

        void update();

   private:

        SDL_Texture* bg_graphic;

        SDL_Rect dest1;

        SDL_Rect dest2;

        bool dest1_in_frame;
        bool dest2_in_frame;

        bool dest1_only;
        bool dest2_only;

        bool dest1_moving_in;
        bool dest2_moving_in;

        int velocity;
};
 
#endif

