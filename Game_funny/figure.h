#pragma once

#include "header.h"
#include "load_texture.h"
#include "loadText.h"

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

        static const int PRINCESS_WIDTH = 32;
		static const int PRINCESS_HEIGHT = 52;

		//Maximum axis velocity of the figure
		static const int FIGURE_VEL = 5;

		static const int FIGURE_BLOOD = 100;
		//Initializes the variables
		Figure();

		//Takes key presses and adjusts the figure's velocity
		void handleEvent( SDL_Event& e );

		//Moves the figure
		void move(Tile *tiles[], const int& LEVEL_WIDTH, const int& LEVEL_HEIGHT, const int& TOTAL_TILES);

		//Shows the figure on the screen
		void render(SDL_Rect clipsIdle[], SDL_Rect clipsRun[], SDL_Rect clipsDie[], SDL_Rect clipsAttack[],
               LTexture figureTexture[], SDL_Renderer* aRenderer, int camX, int camY,
              Tile *tiles[], const int& TOTAL_TILES, LText textMenu[], LTexture textMenuTexture[], LTexture& princessTexture, SDL_Rect clipsPrincessRun[]);

        //Get mPosX:
        int getBoxX();

        //Get mPosY:
        int getBoxY();

        //Set Box
        void setBoxFigure(const int& choose);

        //Get status
        int getStatus();

        //Reset Vel
        void resetVel();

        //Get space
        bool getSpace();

        // get Box
        SDL_Rect getBoxFigure();

        //get flipType
        SDL_RendererFlip getFlip();

        // decreasedBlood
        void decreasedBlood();

        //healing
        void healingBlood();

        // get bloodFigure
        int getBloodFigure();

        void setDie();

        bool getVictory();

        void setPrincess();

        bool getPrincess();

        void setCake();

        bool getCake();

        SDL_Rect getPrincessBox();


    private:
        //The velocity of the figure
		int mVelX, mVelY;

		//Collision box of the figure
		SDL_Rect mBox;

        int frameIdle;
        int frameRun;
        int frameDie;
        int frameAttack;

		//princess
		SDL_Rect princessBox;

		//Check moving
		int checkstatus;
		bool checkup;
		bool checkdown;
		bool checkleft;
		bool checkright;

		//Check attack
        bool checkspace;
		//Check flip
		SDL_RendererFlip flipType;

        SDL_Rect bloodFigure;

        bool checkVictory;

        bool checkPrincess;
        int framePrincess;
        bool checkCake;

};
