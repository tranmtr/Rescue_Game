#pragma once

#include "figure.h"

Figure::Figure()
{
    //Initialize the collision box
    mBox.x = 0;
    mBox.y = 2160;
	mBox.w = FIGURE_WIDTH;
	mBox.h = FIGURE_HEIGHT;

    //Initialize the velocity
    mVelX = 0;
    mVelY = 0;

    //Initialize moving
    checkstatus = ANIMATION_STATUS_IDLE;
    checkup = false;
    checkdown = false;
    checkleft = false;
    checkright = false;

    //Initialize animation flip
    flipType = SDL_FLIP_NONE;
}

void Figure::resetVel()
{
    this->mVelX = 0;
    this->mVelY = 0;
}

void Figure::handleEvent( SDL_Event& e )
{
    //If a key was pressed
    if( e.type == SDL_KEYDOWN && e.key.repeat == 0 )
    {
        //Adjust the velocity
        switch( e.key.keysym.sym )
        {
            case SDLK_SPACE:
                this->checkstatus = ANIMATION_STATUS_ATTACK;
                break;
            case SDLK_UP:
                this->mVelY -= this->FIGURE_VEL;
                this->checkup = true;
                //this->checkstatus = ANIMATION_STATUS_RUN;
                break;
            case SDLK_DOWN:
                this->mVelY += this->FIGURE_VEL;
                this->checkdown = true;
                //this->checkstatus = ANIMATION_STATUS_RUN;
                break;
            case SDLK_LEFT:
                this->mVelX -= this->FIGURE_VEL;
                this->flipType = SDL_FLIP_HORIZONTAL;
                this->checkleft = true;
                //this->checkstatus = ANIMATION_STATUS_RUN;
                break;
            case SDLK_RIGHT:
                this->mVelX += this->FIGURE_VEL;
                this->flipType = SDL_FLIP_NONE;
                this->checkright = true;
                //this->checkstatus = ANIMATION_STATUS_RUN;
                break;
        }
        if(this->checkstatus != ANIMATION_STATUS_ATTACK &&
           (this->checkdown == true || this->checkup == true || this->checkleft == true || this->checkright == true ))
        {
            this->checkstatus = ANIMATION_STATUS_RUN;
        }
        cout << "nhan" << endl;
    }
    //If a key was released
    else if( e.type == SDL_KEYUP && e.key.repeat == 0 )
    {
        //Adjust the velocity
        switch( e.key.keysym.sym )
        {
            case SDLK_UP:
                mVelY += this->FIGURE_VEL;
                this->checkup = false;
                break;
            case SDLK_DOWN:
                mVelY -= this->FIGURE_VEL;
                this->checkdown = false;
                break;
            case SDLK_LEFT:
                mVelX += this->FIGURE_VEL;
                this->checkleft = false;
                break;
            case SDLK_RIGHT:
                mVelX -= this->FIGURE_VEL;
                this->checkright = false;
                break;
        }
        cout << "Tha" << endl;
        if(this->checkdown == false && this->checkup == false && this->checkleft == false && this->checkright == false )
        {
            this->checkstatus = ANIMATION_STATUS_IDLE;
        }
    }
    cout << "this->mVelX = " << this->mVelX << endl;
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
        //cout << "Va cham 1" << endl;
    }

    //Move the dot up or down
    this->mBox.y += this->mVelY;

    //If the dot went too far up or down
    if( ( this->mBox.y < 0 ) || ( this->mBox.y + this->FIGURE_HEIGHT > LEVEL_HEIGHT ) || touchesWall( this->mBox, tiles ) )
    {
        //Move back
        this->mBox.y -= this->mVelY;
        //cout << "Va cham 2" << endl;
    }

    //cout << "Vx = " << this->mVelX << endl;

    if(collisionLavaDie(this->mBox, tiles))
    {
        //cout << "DIE" << endl;
        //cout << "KET THUC" << endl;
        this->checkstatus = ANIMATION_STATUS_DIE;
    }
    if(collisionIceSlow(this->mBox, tiles))
    {
        cout << "SLOW" << endl;
    }
    if(collisionCakeFast(this->mBox, tiles))
    {
        cout << "FAST" << endl;
    }
}

void Figure::render(SDL_Rect clipsIdle[], SDL_Rect clipsRun[], SDL_Rect clipsDie[], SDL_Rect clipsAttack[],
                    int& frameIdle, int& frameRun, int& frameDie, int& frameAttack, LTexture figureTexture[], SDL_Renderer* aRenderer, int camX, int camY)
{
    if(this->checkstatus == ANIMATION_STATUS_DIE)
    {
        if(frameDie / 16 < ANIMATION_FRAMES_DIE-1)
        {
            ++frameDie;
        }
        figureTexture[ANIMATION_STATUS_DIE].render( this->mBox.x - camX, this->mBox.y - camY, &clipsDie[ frameDie / 16 ], 0, NULL, this->flipType, aRenderer  );
        //cout << "DIE" << endl;


    }
    else if(this->checkstatus == ANIMATION_STATUS_IDLE)
    {
        ++frameIdle;
        if( frameIdle / 4 >= ANIMATION_FRAMES_IDLE )
        {
            frameIdle = 0;
        }
        figureTexture[ANIMATION_STATUS_IDLE].render( this->mBox.x - camX, this->mBox.y - camY, &clipsIdle[ frameIdle / 4 ], 0, NULL, this->flipType, aRenderer  );
        //cout << "dung yen" << endl;

    }
    else if(this->checkstatus == ANIMATION_STATUS_RUN)
    {
        ++frameRun;
        if(frameRun / 4 >= ANIMATION_FRAMES_RUN)
        {
            frameRun = 0;
        }
        figureTexture[ANIMATION_STATUS_RUN].render( this->mBox.x - camX, this->mBox.y - camY, &clipsRun[ frameRun / 4 ], 0, NULL, this->flipType, aRenderer  );
        //cout << "chay" << endl;
    }
    else if(this->checkstatus == ANIMATION_STATUS_ATTACK)
    {
        ++frameAttack;
        if(frameAttack / 4 >= ANIMATION_FRAMES_ATTACK)
        {
            frameAttack = 0;
        }
        figureTexture[ANIMATION_STATUS_ATTACK].render( this->mBox.x - camX, this->mBox.y - camY, &clipsAttack[ frameAttack / 4 ], 0, NULL, this->flipType, aRenderer  );
        cout << "ATTACK" << endl;
    }
}

int Figure::getBoxX()
{
    return this->mBox.x;
}

int Figure::getBoxY()
{
    return this->mBox.y;
}

int Figure::getStatus()
{
    return this->checkstatus;
}
