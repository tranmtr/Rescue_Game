#pragma once

#include "header.h"
#include "load_texture.h"

class Figure
{
    public:
		//The dimensions of the dot
		static const int FIGURE_WIDTH = 64;
		static const int FIGURE_HEIGHT = 64;

		//Maximum axis velocity of the dot
		static const int FIGURE_VEL = 5;

		//Initializes the variables
		Figure();

		//Takes key presses and adjusts the dot's velocity
		void handleEvent( SDL_Event& e, SDL_RendererFlip& flipType, bool& moving );

		//Moves the dot
		void move();

		//Shows the dot on the screen
		void render(SDL_Rect gSpriteClipsIdle[], SDL_Rect gSpriteClipsRun[], int frameIdle, int frameRun, LTexture& figureTexture, SDL_Renderer* gRenderer, SDL_RendererFlip flipType, bool moving);

    private:
		//The X and Y offsets of the dot
		int mPosX, mPosY;

		//The velocity of the dot
		int mVelX, mVelY;
};











