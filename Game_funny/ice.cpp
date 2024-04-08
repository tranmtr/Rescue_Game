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
    dragon.x = 300;
    dragon.y = 2250;
    dragon.w = 169;
    dragon.h = 80;
    col = false;
}
LIce::~LIce()
{

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
        if(touchesWall(this->mIce, Tiles))
        {
            this->col = true;
            this->framesIce = 0;
//            cout << "Va cham" << endl;
//            //cout << "Va tuong" << endl;
//            cout << "x = " << this->mIce.x << endl;
//            cout << "y = " << this->mIce.y << endl;
        }
        else if(this->checkCollisionIceWithMonster(camX, camY))
        {
            this->col = true;
            this->framesIce = 0;
            cout << "Va cham" << endl;
            //cout << "Va tuong" << endl;
            cout << "x = " << this->mIce.x << endl;
            cout << "y = " << this->mIce.y << endl;
        }
        else if(framesIce < 0)
        {
            this->framesIce = 0;
        }
        else if(this->framesIce > 0)
        {
            this->framesIce--;
            renderIce(Figure, iceDamegeTexture, aRenderer, camX, camY);
            //cout << "Da xuat hien 2" << endl;
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

SDL_Rect LIce::getDragon()
{
    return this->dragon;
}








