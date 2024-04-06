#pragma once

#include "header.h"
#include "load_texture.h"

class Figure
{
    public:
		//The dimensions of the figure
		static const int FIGURE_WIDTH = 45;
		static const int FIGURE_HEIGHT = 54;

		//static const int FIGURE_WIDTH_DIE = 84;
		//static const int FIGURE_HEIGHT_DIE = 54;

		//static const int FIGURE_WIDTH_ATTACK = 76;
		//static const int FIGURE_HEIGHT_ATTACK = 54;

		//Maximum axis velocity of the figure
		static const int FIGURE_VEL = 2;

		//Initializes the variables
		Figure();

		//Takes key presses and adjusts the figure's velocity
		void handleEvent( SDL_Event& e );

		//Moves the figure
		void move(Tile *tiles[]);

		//Shows the figure on the screen
		void render(SDL_Rect clipsIdle[], SDL_Rect clipsRun[], SDL_Rect clipsDie[], SDL_Rect clipsAttack[],
              int& frameIdle, int& frameRun, int& frameDie, int& frameAttack, LTexture figureTexture[], SDL_Renderer* aRenderer, int camX, int camY);

        //Get mPosX:
        int getBoxX();

        //Get mPosY:
        int getBoxY();

        //Get status
        int getStatus();

        //Reset Vel
        void resetVel();

    private:
        //The velocity of the dot
		int mVelX, mVelY;

		//Collision box of the dot
		SDL_Rect mBox;

		//Check moving
		int checkstatus;
		bool checkup;
		bool checkdown;
		bool checkleft;
		bool checkright;

		//Check flip
		SDL_RendererFlip flipType;

};
