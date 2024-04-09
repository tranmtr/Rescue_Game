#pragma once

#include "header.h"
#include "load_texture.h"

class dragon
{
    public:
        static const int FIRE_DRAGON_DAMAGE = 25;
        dragon();
        ~dragon();
        void render(LTexture& fireDragonTexture, SDL_Rect clipsDragon[], SDL_Renderer*& aRenderer, int camX, int camY);
        void fire();
        int getBloodDragon();
        void decreasedBloodDragon();
        SDL_Rect getBox();
    private:
        SDL_Rect box;
        int framesDragon;
        SDL_Rect bloodDragon;

};
