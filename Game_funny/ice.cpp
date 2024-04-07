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
}
LIce::~LIce()
{

}

void LIce::moveIce(Figure Figure, LTexture& iceDamegeTexture, SDL_Renderer*& aRenderer, int camX, int camY)
{
    if(Figure.getSpace() == true)
    {
        this->mIce.x = Figure.getBoxX() + Figure.FIGURE_WIDTH;
        this->mIce.y = Figure.getBoxY() ;
        cout << "this->mIce.x = " << this->mIce.x << endl;
        cout << "this->mIce.y = " << this->mIce.y << endl;
        framesIce = 0;
        renderIce(Figure, iceDamegeTexture, aRenderer, camX, camY);
    }
    else if(Figure.getSpace() == false)
    {
        framesIce++;
    }
}
void LIce::renderIce(Figure Figure, LTexture& iceDamageTexture, SDL_Renderer*& aRenderer, int camX, int camY )
{
    iceDamageTexture.render(this->mIce.x - camX, this->mIce.y - camY, NULL, 0, NULL, SDL_FLIP_NONE, aRenderer);
}













