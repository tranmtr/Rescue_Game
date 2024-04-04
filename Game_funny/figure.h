#pragma once

#include "header.h"
#include "load_texture.h"

class Figure
{
    public:
		//The dimensions of the dot
		static const int FIGURE_WIDTH = 45;
		static const int FIGURE_HEIGHT = 54;

		//Maximum axis velocity of the figure
		static const int FIGURE_VEL = 5;

		//Initializes the variables
		Figure();

		//Takes key presses and adjusts the figure's velocity
		void handleEvent( SDL_Event& e );

		//Moves the figure
		void move(Tile *tiles[]);

		//Shows the figure on the screen
		void render(SDL_Rect clipsIdle[], SDL_Rect clipsRun[], int& frameIdle, int& frameRun, LTexture& figureTexture, SDL_Renderer* aRenderer, int camX, int camY);

        //Get mPosX:
        int getBoxX();

        //Get mPosY:
        int getBoxY();
    private:
        //The velocity of the dot
		int mVelX, mVelY;

		//Collision box of the dot
		SDL_Rect mBox;

		//Check moving
		bool moving;
		bool checkup;
		bool checkdown;
		bool checkleft;
		bool checkright;
		//Check flip
		SDL_RendererFlip flipType;

};
