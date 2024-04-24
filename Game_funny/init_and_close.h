#pragma once

#include "header.h"
#include "load_texture.h"

//Starts up SDL and creates window
bool init(SDL_Window*& aWindow, SDL_Renderer*& aRenderer);

//Frees media and shuts down SDL
void close(SDL_Window*& aWindow, SDL_Renderer*& aRenderer, LTexture figureTexture[], LTexture& wallTexture,
           LTexture& floorTexture, LTexture& lavaTexture, LTexture& iceTexture, LTexture& cakeTexture, TTF_Font*& aFont,
           Mix_Music*& soundTrackMusic, Mix_Chunk*& iceDamageChuck, Mix_Chunk*& fireDragonChuck);
