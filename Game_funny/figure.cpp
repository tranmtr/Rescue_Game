#pragma once

#include "figure.h"

Figure::Figure()
{
    //Initialize the offsets
    mPosX = 0;
    mPosY = 0;

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
            case SDLK_UP: mVelY -= FIGURE_VEL; break;
            case SDLK_DOWN: mVelY += FIGURE_VEL; break;
            case SDLK_LEFT:
                mVelX -= FIGURE_VEL;
                flipType = SDL_FLIP_HORIZONTAL;
                break;
            case SDLK_RIGHT:
                mVelX += FIGURE_VEL;
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
            case SDLK_UP: mVelY += FIGURE_VEL; break;
            case SDLK_DOWN: mVelY -= FIGURE_VEL; break;
            case SDLK_LEFT: mVelX += FIGURE_VEL; break;
            case SDLK_RIGHT: mVelX -= FIGURE_VEL; break;
        }
        cout << "Tha" << endl;
        moving = false;
    }
}

void Figure::move()
{
    //Move the dot left or right
    mPosX += mVelX;

    //If the dot went too far to the left or right
    if( ( mPosX < 0 ) || ( mPosX + FIGURE_WIDTH > SCREEN_WIDTH ) )
    {
        //Move back
        mPosX -= mVelX;
    }

    //Move the dot up or down
    mPosY += mVelY;

    //If the dot went too far up or down
    if( ( mPosY < 0 ) || ( mPosY + FIGURE_HEIGHT > SCREEN_HEIGHT ) )
    {
        //Move back
        mPosY -= mVelY;
    }
}

void Figure::render(SDL_Rect clipsIdle[], SDL_Rect clipsRun[], int frameIdle, int frameRun, LTexture& figureTexture, SDL_Renderer* aRenderer, SDL_RendererFlip flipType, bool moving)
{
    //Show the figure
    //SDL_Rect* currentClip = &gSpriteClips[ frame / 2 ];
	//gSpriteSheetTexture.render( mPosX, mPosY, currentClip, 0, NULL, SDL_FLIP_NONE, gRenderer  );
    if(moving == true)
    {
        figureTexture.render( mPosX, mPosY, &clipsRun[ frameRun / 4 ], 0, NULL, flipType, aRenderer  );
    }
    else
    {
        figureTexture.render( mPosX, mPosY, &clipsIdle[ frameIdle / 4 ], 0, NULL, flipType, aRenderer  );
    }

	cout << "Chay" << endl;
}
