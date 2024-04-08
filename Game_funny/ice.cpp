#pragma once

#include "ice.h"

LIce::LIce()
{
    iceVelX = 0;
    iceVelY = 0;
    mIce.x = 0;
    mIce.y = 0;
    mIce.w = ICE_DAMAGE_WIDTH;
    mIce.h = ICE_DAMAGE_HEIGHT;
    framesIce = 0;
    direction = true;
    col = false;

    dragon.x = 300;
    dragon.y = 2250;
    dragon.w = 169;
    dragon.h = 80;
    framesDragon = 0;

    bloodDragon.x = 0;
    bloodDragon.y = 0;
    bloodDragon.w = 100;
    bloodDragon.h = 5;
}
LIce::~LIce()
{

}

int LIce::getBloodDragon()
{
    return this->bloodDragon.w;
}

void LIce::moveIce(Figure Figure, LTexture& iceDamegeTexture, SDL_Renderer*& aRenderer, int camX, int camY, Tile* Tiles[])
{
    if(Figure.getSpace() == true && this->framesIce == 0 )
    {
        this->mIce.x = Figure.getBoxX() + Figure.FIGURE_WIDTH / 2;
        this->mIce.y = Figure.getBoxY() ;
        this->framesIce = 100;
        this->col = false;
        if(Figure.getFlip() == SDL_FLIP_NONE)
        {
            this->direction = true;
            this->iceVelX = 5;
        }
        else if(Figure.getFlip() == SDL_FLIP_HORIZONTAL)
        {
            this->direction = false;
            this->iceVelX = -5;
        }
        renderIce(Figure, iceDamegeTexture, aRenderer, camX, camY);
        //cout << "Da xuat hien 1" << endl;
    }
    else if(Figure.getSpace() == false )
    {
        if(this->framesIce == 0)
        {
            this->mIce.x = Figure.getBoxX() + Figure.FIGURE_WIDTH / 2;
            this->mIce.y = Figure.getBoxY() ;
        }
        else if( touchesWall(this->mIce, Tiles))
        {
            this->col = true;
            this->framesIce = 0;

        }
        else if(this->bloodDragon.w != 0 && this->checkCollisionIceWithMonster(camX, camY))
        {
            this->bloodDragon.w -= ICE_DAMAGE_MAX;
            this->col = true;
            this->framesIce = 0;
            if(this->bloodDragon.w < 0)
            {
                this->bloodDragon.w = 0;
            }
        }
        else if(framesIce < 0)
        {
            this->framesIce = 0;
        }
        else if(this->framesIce > 0)
        {
            this->framesIce--;
            renderIce(Figure, iceDamegeTexture, aRenderer, camX, camY);

        }
    }
}
void LIce::renderIce(Figure Figure, LTexture& iceDamageTexture, SDL_Renderer*& aRenderer, int camX, int camY )
{
    this->mIce.x += this->iceVelX;
    if(this->col == true)
    {
        this->mIce.x -= this->iceVelX;
    }
    if(this->direction == true)
        iceDamageTexture.render(this->mIce.x - camX, this->mIce.y - camY, NULL, 0, NULL, SDL_FLIP_NONE  , aRenderer);
    else
        iceDamageTexture.render(this->mIce.x - camX, this->mIce.y - camY, NULL, 0, NULL, SDL_FLIP_HORIZONTAL  , aRenderer);
}


bool LIce::checkCollisionIceWithMonster(int camX, int camY)
{
    SDL_Rect realDragon = this->dragon;
    realDragon.x = realDragon.x + 55 ;
    //realDragon.y -= camY;
    realDragon.w -= 85;
    cout << "realDragon.x = " << realDragon.x << endl;
    cout << "realDragon.y = " << realDragon.y << endl;
    return checkCollision(this->mIce, realDragon);
}

void LIce::renderDragon(LTexture& fireDragonTexture, int camX, int camY, SDL_Rect clipsDragon[], SDL_Renderer*& aRenderer)
{
    this->framesDragon++;
    if(this->framesDragon / 8 >= ANIMATION_FRAMES_DRAGON)
    {
        this->framesDragon = 0;
    }
    fireDragonTexture.render(this->dragon.x - camX, this->dragon.y - camY, &clipsDragon[ framesDragon / 8 ], 0, NULL, SDL_FLIP_NONE, aRenderer);
    bloodDragon.x = this->dragon.x - camX + 48;
    bloodDragon.y = this->dragon.y - camY - 10;

    SDL_SetRenderDrawColor(aRenderer, 255, 0, 0, 255);
    SDL_RenderFillRect(aRenderer, &this->bloodDragon);
}

SDL_Rect LIce::getDragon()
{
    return this->dragon;
}








