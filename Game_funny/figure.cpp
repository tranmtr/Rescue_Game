#pragma once

#include "figure.h"

Figure::Figure()
{
    //Initialize the collision box
    mBox.x = 0;
    mBox.y = 0;
	mBox.w = FIGURE_WIDTH;
	mBox.h = FIGURE_HEIGHT;

    //Initialize the velocity
    mVelX = 0;
    mVelY = 0;
}

void Figure::handleEvent( SDL_Event& e, SDL_RendererFlip& flipType, bool& moving )
{
    //If a key was pressed
	if( e.type == SDL_KEYDOWN && e.key.repeat == 0 )
    {
        //Adjust the velocity
        switch( e.key.keysym.sym )
        {
            case SDLK_UP:
                mVelY -= this->FIGURE_VEL;
                break;
            case SDLK_DOWN:
                mVelY += this->FIGURE_VEL;
                break;
            case SDLK_LEFT:
                mVelX -= this->FIGURE_VEL;
                flipType = SDL_FLIP_HORIZONTAL;
                break;
            case SDLK_RIGHT:
                mVelX += this->FIGURE_VEL;
                flipType = SDL_FLIP_NONE;
                break;
        }
        cout << "nhan" << endl;
        moving = true;
    }
    //If a key was released
    else if( e.type == SDL_KEYUP && e.key.repeat == 0 )
    {
        //Adjust the velocity
        switch( e.key.keysym.sym )
        {
            case SDLK_UP:
                mVelY += this->FIGURE_VEL;
                break;
            case SDLK_DOWN:
                mVelY -= this->FIGURE_VEL;
                break;
            case SDLK_LEFT:
                mVelX += this->FIGURE_VEL;
                break;
            case SDLK_RIGHT:
                mVelX -= this->FIGURE_VEL;
                break;
        }
        cout << "Tha" << endl;
        moving = false;
    }
}

void Figure::move(Tile *tiles[])
{
    //Move the dot left or right
    this->mBox.x += this->mVelX;

    //If the dot went too far to the left or right
    if( ( this->mBox.x < 0 ) || ( this->mBox.x + this->FIGURE_WIDTH > LEVEL_WIDTH  ) || touchesWall( this->mBox, tiles ))
    {
        //Move back
        this->mBox.x -= this->mVelX;
        cout << "Va cham 1" << endl;
    }

    //Move the dot up or down
    this->mBox.y += this->mVelY;

    //If the dot went too far up or down
    if( ( this->mBox.y < 0 ) || ( this->mBox.y + this->FIGURE_HEIGHT > LEVEL_HEIGHT ) || touchesWall( this->mBox, tiles ) )
    {
        //Move back
        this->mBox.y -= this->mVelY;
        cout << "Va cham 2" << endl;
    }
}

void Figure::render(SDL_Rect clipsIdle[], SDL_Rect clipsRun[], int& frameIdle, int& frameRun, LTexture& figureTexture, SDL_Renderer* aRenderer, SDL_RendererFlip flipType, bool moving, int camX, int camY)
{
    //Show the figure run
    if(moving == true)
    {
        ++frameRun;
        if(frameRun / 4 >= RUN_ANIMATION_FRAMES)
        {
            frameRun = 0;
        }
        figureTexture.render( this->mBox.x - camX, this->mBox.y - camY, &clipsRun[ frameRun / 4 ], 0, NULL, flipType, aRenderer  );
    }
    //Show the figure idle
    else
    {
        ++frameIdle;
        if( frameIdle / 4 >= IDLE_ANIMATION_FRAMES )
        {
            frameIdle = 0;
        }
        figureTexture.render( this->mBox.x - camX, this->mBox.y - camY, &clipsIdle[ frameIdle / 4 ], 0, NULL, flipType, aRenderer  );
    }

	cout << "Chay" << endl;
}

int Figure::getBoxX()
{
    return this->mBox.x;
}

int Figure::getBoxY()
{
    return this->mBox.y;
}
