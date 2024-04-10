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

    //Initialize moving
    checkstatus = ANIMATION_STATUS_IDLE;
    checkup = false;
    checkdown = false;
    checkleft = false;
    checkright = false;
    checkspace = false;
    //Initialize animation flip
    flipType = SDL_FLIP_NONE;

    bloodFigure.x = 0;
    bloodFigure.y = 2150;
    bloodFigure.w = FIGURE_WIDTH;
    bloodFigure.h = 5;

    checkVictory = false;
}

void Figure::setBoxFigure(const int& choose)
{
    if(choose == 1)
    {
        this->mBox.x = 0;
        this->mBox.y = 2160;
    }
    else
    {
        this->mBox.x = 1520;
        this->mBox.y = 0;
    }
}

void Figure::setDie()
{
    this->checkstatus = ANIMATION_STATUS_DIE;
    cout << "DIE" << endl;
}

SDL_Rect Figure::getBoxFigure()
{
    return this->mBox;
}

int Figure::getBloodFigure()
{
    return this->bloodFigure.w;
}

void Figure::decreasedBlood()
{
    this->bloodFigure.w -= DAMAGE_FIRE * FIGURE_WIDTH / FIGURE_BLOOD ;
    if(bloodFigure.w < 0)
    {
        bloodFigure.w = 0;
    }
}

void Figure::resetVel()
{
    this->mVelX = 0;
    this->mVelY = 0;
}

bool Figure::getVictory()
{
    return this->checkVictory;
}

bool Figure::getSpace()
{
    return this->checkspace;
}

SDL_RendererFlip Figure::getFlip()

{
    return this->flipType;
}
void Figure::handleEvent( SDL_Event& e  )
{
    //If a key was pressed
    if( e.type == SDL_KEYDOWN && e.key.repeat == 0 )
    {
        //SDL_Delay(1000);
        //Adjust the velocity
        if(e.key.keysym.sym == SDLK_SPACE && this->checkdown == false && this->checkup == false && this->checkleft == false && this->checkright == false)
        {
            this->checkspace = true;
            this->checkstatus = ANIMATION_STATUS_ATTACK;
        }
        else if(e.key.keysym.sym == SDLK_UP && this->checkspace == false)
        {
            this->mVelY -= this->FIGURE_VEL;
            this->checkup = true;
            this->checkstatus = ANIMATION_STATUS_RUN;
        }
        else if(e.key.keysym.sym == SDLK_DOWN && this->checkspace == false)
        {
            this->mVelY += this->FIGURE_VEL;
            this->checkdown = true;
            this->checkstatus = ANIMATION_STATUS_RUN;
        }
        else if(e.key.keysym.sym == SDLK_LEFT && this->checkspace == false)
        {
            this->mVelX -= this->FIGURE_VEL;
            this->flipType = SDL_FLIP_HORIZONTAL;
            this->checkleft = true;
            this->checkstatus = ANIMATION_STATUS_RUN;
        }
        else if(e.key.keysym.sym == SDLK_RIGHT && this->checkspace == false)
        {
            this->mVelX += this->FIGURE_VEL;
            this->flipType = SDL_FLIP_NONE;
            this->checkright = true;
            this->checkstatus = ANIMATION_STATUS_RUN;
            //cout << "DUOC NHAN" << endl;
        }
    //cout << "nhan" << endl;
    }

    //If a key was released
    else if( e.type == SDL_KEYUP && e.key.repeat == 0 )
    {
        //Adjust the velocity
        //SDL_Delay(1000);
        if(e.key.keysym.sym == SDLK_SPACE &&  this->checkdown == false && this->checkup == false && this->checkleft == false && this->checkright == false)
        {
            this->checkspace = false;
            //cout << "NHA SPACE" << endl;
        }
        else if(e.key.keysym.sym == SDLK_UP && this->checkspace == false)
        {
            //mVelY += this->FIGURE_VEL;
            mVelY = 0;
            this->checkup = false;
            //cout << "checkspaceup = " << checkspace << endl;
        }
        else if(e.key.keysym.sym == SDLK_DOWN && this->checkspace == false)
        {
            //mVelY -= this->FIGURE_VEL;
            mVelY = 0;
            this->checkdown = false;
            //cout << "checkspacedown = " << checkspace << endl;
        }
        else if(e.key.keysym.sym == SDLK_LEFT && this->checkspace == false)
        {
            //mVelX += this->FIGURE_VEL;
            mVelX = 0;
            this->checkleft = false;
            //cout << "checkspaceleft = " << checkspace << endl;
        }
        else if(e.key.keysym.sym == SDLK_RIGHT && this->checkspace == false)
        {
            //mVelX -= this->FIGURE_VEL;
            mVelX = 0;
            this->checkright = false;
            //cout << "checkspaceright = " << checkspace << endl;
            //cout << "DUOC THA" << endl;

        }

        //cout << "Tha" << endl;
        if(this->checkspace == false && this->checkdown == false && this->checkup == false && this->checkleft == false && this->checkright == false )
        {
            this->checkstatus = ANIMATION_STATUS_IDLE;
        }
    }
    //cout << "this->mVelX = " << this->mVelX << endl;
    //cout << "this->mVelY = " << this->mVelY << endl;
}

void Figure::move(Tile *tiles[], const int& LEVEL_WIDTH, const int& LEVEL_HEIGHT, const int& TOTAL_TILES)
{
    //Move the dot left or right
    this->mBox.x += this->mVelX;

    //If the dot went too far to the left or right
    if( ( this->mBox.x < 0 ) || ( this->mBox.x + this->FIGURE_WIDTH > LEVEL_WIDTH  ) || touchesWall( this->mBox, tiles, TOTAL_TILES ))
    {
        //Move back
        this->mBox.x -= this->mVelX;
        //cout << "Va cham 1" << endl;
    }

    //Move the dot up or down
    this->mBox.y += this->mVelY;

    //If the dot went too far up or down
    if( ( this->mBox.y < 0 ) || ( this->mBox.y + this->FIGURE_HEIGHT > LEVEL_HEIGHT ) || touchesWall( this->mBox, tiles, TOTAL_TILES ) )
    {
        //Move back
        this->mBox.y -= this->mVelY;
        //cout << "Va cham 2" << endl;
    }

    //cout << "Vx = " << this->mVelX << endl;

    if(collisionLavaDie(this->mBox, tiles, TOTAL_TILES))
    {
        //cout << "DIE" << endl;
        //cout << "KET THUC" << endl;
        this->checkstatus = ANIMATION_STATUS_DIE;
    }
    if(collisionIceSlow(this->mBox, tiles, TOTAL_TILES))
    {
        //cout << "SLOW" << endl;
    }
    if(collisionCakeFast(this->mBox, tiles, TOTAL_TILES))
    {
        //cout << "FAST" << endl;
    }
    if(collisionFinishVictory(this->mBox, tiles, TOTAL_TILES))
    {
        checkVictory = true;
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
        cout << "Attack" << endl;
    }

    this->bloodFigure.x = this->mBox.x - camX;
    this->bloodFigure.y = this->mBox.y - camY;

    SDL_SetRenderDrawColor(aRenderer, 255, 0, 0, 255);
    SDL_RenderFillRect(aRenderer, &this->bloodFigure);
    //cout << "bloodFigure.w = "<< bloodFigure.w << endl;
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
