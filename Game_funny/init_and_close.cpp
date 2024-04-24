
#pragma once

#include "init_and_close.h"

bool init(SDL_Window*& aWindow, SDL_Renderer*& aRenderer)
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO||SDL_INIT_AUDIO ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			printf( "Warning: Linear texture filtering not enabled!" );
		}

		//Create window
		aWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( aWindow == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			//Create vsynced renderer for window
			aRenderer = SDL_CreateRenderer( aWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
			if( aRenderer == NULL )
			{
				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor( aRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
					printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
					success = false;
				}
				//Initialize SDL_ttf
				if( TTF_Init() == -1 )
				{
					printf( "SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError() );
					success = false;
				}
				//Initialize SDL_mixer
				if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
				{
					printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
					success = false;
				}

			}
		}
	}

	return success;
}

void close(SDL_Window*& aWindow, SDL_Renderer*& aRenderer, LTexture figureTexture[], LTexture& wallTexture, LTexture& floorTexture, LTexture& lavaTexture,
           LTexture& iceTexture, LTexture& cakeTexture, TTF_Font*& aFont, Mix_Music*& soundTrackMusic, Mix_Chunk*& iceDamageChuck, Mix_Chunk*& fireDragonChuck)
{
    Mix_FreeChunk( iceDamageChuck );
	Mix_FreeChunk( fireDragonChuck );
	iceDamageChuck = NULL;
    fireDragonChuck = NULL;

	//Free the music
	Mix_FreeMusic( soundTrackMusic );
    soundTrackMusic = NULL;

	//Free loaded images
	figureTexture[ANIMATION_STATUS_IDLE].free();
	figureTexture[ANIMATION_STATUS_RUN].free();
    wallTexture.free();
    floorTexture.free();
    lavaTexture.free();
    iceTexture.free();
    cakeTexture.free();
	//Destroy window
	SDL_DestroyRenderer( aRenderer );
	SDL_DestroyWindow( aWindow );
	aWindow = NULL;
	aRenderer = NULL;

	//Free font
	TTF_CloseFont( aFont );
	aFont = NULL;
	//Quit SDL subsystems
	TTF_Quit();
	IMG_Quit();
	Mix_Quit();
	SDL_Quit();
}
