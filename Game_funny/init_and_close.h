#pragma once

#include "header.h"
#include "load_texture.h"

//Starts up SDL and creates window
bool init(SDL_Window*& gWindow, SDL_Renderer*& gRenderer);

//Frees media and shuts down SDL
void close(SDL_Window*& gWindow, SDL_Renderer*& gRenderer, LTexture& figureTexture);


