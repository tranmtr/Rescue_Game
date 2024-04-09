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

}
LIce::~LIce()
{

}

void LIce::moveIce(Figure Figure, LTexture& iceDamegeTexture, dragon& dragon, SDL_Renderer*& aRenderer, int camX, int camY, Tile* Tiles[])
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
        else if(dragon.getBloodDragon() != 0 && this->checkCollisionIceWithDragon(camX, camY, dragon))
        {
            dragon.decreasedBloodDragon();
            this->col = true;
            this->framesIce = 0;
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


bool LIce::checkCollisionIceWithDragon(int camX, int camY, dragon dragon)
{
    SDL_Rect colDragon = dragon.getBox();
    colDragon.x = colDragon.x + 55 ;
    //realDragon.y -= camY;
    colDragon.w -= 85;
    cout << "colDragon.x = " << colDragon.x << endl;
    cout << "colDragon.y = " << colDragon.y << endl;
    return checkCollision(this->mIce, colDragon);
}









