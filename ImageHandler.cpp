
#include "ImageHandler.h"


ImageHandler::ImageHandler()
{

}

ImageHandler::~ImageHandler()
{
   SDL_FreeSurface(temp);
}


SDL_Texture* ImageHandler::handle_image(SDL_Renderer* renderer, const char* img)
{
   SDL_Texture* texture;

   std::string imgPath = "./imgs/";
   imgPath = imgPath + img;
   const char *result = "";
   result = imgPath.c_str();


   temp = IMG_Load(result);
   texture = SDL_CreateTextureFromSurface(renderer, temp);
   
   return texture;
}