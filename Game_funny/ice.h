#pragma once

#include "header.h"
#include "load_texture.h"
#include "figure.h"
class LIce
{
    public:
        static const int ICE_DAMAGE_WIDTH = 43;
		static const int ICE_DAMAGE_HEIGHT = 32;
		static const int ICE_DAMAGE_VEL = 2;
        LIce();
        ~LIce();
        void moveIce(Figure Figure, LTexture& iceDamegeTexture, SDL_Renderer*& aRenderer, int camX, int camY);
        bool checkCollisionIceWithWall(Tile* tiles[]);
        bool checkCollisionIceWithMonster();
        void renderIce(Figure Figure, LTexture& iceDamegeTexture, SDL_Renderer*& aRenderer, int camX, int camY );
    private:
        SDL_Rect mIce;
        int iceVelX;
        int iceVelY;
        int framesIce;
};
