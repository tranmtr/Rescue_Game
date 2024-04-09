#pragma once

#include "dragon.h"

dragon::dragon()
{
    box.x = 300;
    box.y = 2250;
    box.w = 169;
    box.h = 80;

    framesDragon = 0;

    bloodDragon.x = 0;
    bloodDragon.y = 0;
    bloodDragon.w = 100;
    bloodDragon.h = 5;
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




