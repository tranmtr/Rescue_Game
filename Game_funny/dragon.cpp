#pragma once

#include "dragon.h"

dragon::dragon()
{
    box.x = 300;
    box.y = 2240;
    box.w = 169;
    box.h = 80;

    framesDragon = 0;

    bloodDragon.x = 0;
    bloodDragon.y = 0;
    bloodDragon.w = 100;
    bloodDragon.h = 5;

    framesFire = 0;

    fireBox.x = 0;
    fireBox.y = 0;
    fireBox.w = 98;
    fireBox.h = 60;

    fireCol = false;
    fireVel = 0;
}

dragon::~dragon()
{

}

void dragon::render(LTexture& fireDragonTexture, SDL_Rect clipsDragon[], SDL_Renderer*& aRenderer, int camX, int camY)
{
    this->framesDragon++;
    if(this->framesDragon / 8 >= ANIMATION_FRAMES_DRAGON)
    {
        this->framesDragon = 0;
    }
    fireDragonTexture.render(this->box.x - camX, this->box.y - camY, &clipsDragon[ this->framesDragon / 8 ], 0, NULL, SDL_FLIP_NONE, aRenderer);

    this->bloodDragon.x = this->box.x - camX + 48;
    this->bloodDragon.y = this->box.y - camY - 10;

    SDL_SetRenderDrawColor(aRenderer, 255, 0, 0, 255);
    SDL_RenderFillRect(aRenderer, &this->bloodDragon);

}

int dragon::getBloodDragon()
{
    return this->bloodDragon.w;
}

void dragon::decreasedBloodDragon()
{
    this->bloodDragon.w -= DAMAGE_ICE;
    if(this->bloodDragon.w < 0)
    {
        this->bloodDragon.w = 0;
    }
}

SDL_Rect dragon::getBox()
{
    return this->box;
}

void dragon::setBox(int x, int y)
{
    this->box.x = x;
    this->box.y = y;
}
void dragon::fireMove(Figure& Figure, LTexture& fireTexture, SDL_Renderer*& aRenderer, int camX, int camY, Tile* Tiles[], const int& TOTAL_TILES)
{
    if(this->framesFire == 0)
    {
        this->framesDragon = 7;
        this->fireBox.x = this->box.x;
        this->fireBox.y = this->box.y;
        this->framesFire = 100;
        this->fireCol = false;
        this->fireVel = -5;
        this->renderFire(fireTexture, aRenderer, camX, camY);
    }
    else if( touchesWall(this->fireBox, Tiles, TOTAL_TILES))
    {
        this->fireCol = true;
        this->framesFire = 0;
        //cout << "Cham tuong" << endl;

    }
    else if(Figure.getBloodFigure() != 0 && this->checkCollisionFireWithFigure(camX, camY, Figure))
    {
        Figure.decreasedBlood();
        this->fireCol = true;
        this->framesFire = 0;
        //cout << "Va cham" << endl;
    }
    else if(Figure.getBloodFigure() == 0)
    {
        Figure.setDie();
    }
    else if(framesFire < 0)
    {
        this->framesFire = 0;
    }
    else if(this->framesFire > 0)
    {
        this->framesFire--;
        renderFire(fireTexture, aRenderer, camX, camY);
        //cout <<"Render" << endl;
    }
    //cout << "framesFire = " << framesFire << endl;
}

void dragon::renderFire(LTexture& fireTexture, SDL_Renderer*& aRenderer, int camX, int camY)
{
    this->fireBox.x += this->fireVel;
    if(this->fireCol == true)
    {
        this->fireBox.x -= this->fireVel;
    }
    fireTexture.render(this->fireBox.x - camX, this->fireBox.y - camY, NULL, 0, NULL, SDL_FLIP_NONE, aRenderer);
    //cout << "Vao fire" << endl;
}

bool dragon::checkCollisionFireWithFigure(int camX, int camY, Figure Figure)
{
    //cout <<"FireBox.x = " << fireBox.x << endl;
    return checkCollision(Figure.getBoxFigure(), this->fireBox);
}

void setDragon(Tile* tiles[], dragon dragon[], const int& TOTAL_TILES)
{
    int indexDragon = 0;
    for(int i = 0; i < TOTAL_TILES; i++)
    {
        if(tiles[i]->getType() == TILE_LAVA)
        {
            dragon[indexDragon].setBox(tiles[i]->getBox().x - 80, tiles[i]->getBox().y);
            indexDragon += 1;
        }
    }
}










