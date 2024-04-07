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
}
LIce::~LIce()
{

}

void LIce::moveIce(Figure Figure, LTexture& iceDamegeTexture, SDL_Renderer*& aRenderer, int camX, int camY, Tile* Tiles[])
{
    if(Figure.getSpace() == true && this->framesIce == 0 )
    {
        this->mIce.x = Figure.getBoxX() + Figure.FIGURE_WIDTH;
        this->mIce.y = Figure.getBoxY() ;
        this->framesIce = 100;
        if(Figure.getFlip() == SDL_FLIP_NONE)
            this->direction = true;
        else if(Figure.getFlip() == SDL_FLIP_HORIZONTAL)
            this->direction = false;
        renderIce(Figure, iceDamegeTexture, aRenderer, camX, camY);
        cout << "Da xuat hien 1" << endl;
    }
    else if(Figure.getSpace() == false )
    {
        if(touchesWall(this->mIce, Tiles) || framesIce < 0)
        {
            this->framesIce = 0;
            cout << "Va tuong" << endl;
        }
        else if(this->framesIce > 0)
        {
            this->framesIce--;
            renderIce(Figure, iceDamegeTexture, aRenderer, camX, camY);
            cout << "Da xuat hien 2" << endl;
        }
    }
}
void LIce::renderIce(Figure Figure, LTexture& iceDamageTexture, SDL_Renderer*& aRenderer, int camX, int camY )
{
    if(this->direction == true)
    {
        this->mIce.x += ICE_DAMAGE_VEL;
        iceDamageTexture.render(this->mIce.x - camX, this->mIce.y - camY, NULL, 0, NULL, SDL_FLIP_NONE  , aRenderer);
    }
    else if(this->direction == false)
    {
        this->mIce.x -= ICE_DAMAGE_VEL;
        iceDamageTexture.render(this->mIce.x - camX - 2*Figure.FIGURE_WIDTH , this->mIce.y - camY, NULL, 0, NULL, SDL_FLIP_HORIZONTAL  , aRenderer);
    }
}


/*
bool LIce::checkCollisionIceWithMonster(Tile* Tiles[])
{
    this->reload = true;
    return
}*/










