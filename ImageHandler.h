
#include <string>
#include <SDL2/SDL.h> 
#include <SDL2/SDL_image.h> 
#include <SDL2/SDL_timer.h>

#ifndef IMAGEHANDLER_H
#define IMAGEHANDLER_H

class ImageHandler
{

    public:

        ImageHandler();

        ~ImageHandler();

        SDL_Texture* handle_image(SDL_Renderer* renderer, const char* img);

    private:

        SDL_Surface* temp;
};

#endif