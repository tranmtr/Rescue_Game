#pragma once

#include "header.h"
#include "load_texture.h"
#include "figure.h"
#include "check_collision.h"
#include "dragon.h"
class LIce
{
    public:
        static const int ICE_DAMAGE_WIDTH = 43;
		static const int ICE_DAMAGE_HEIGHT = 32;
		static const int ICE_DAMAGE_VEL = 5;

        LIce();
        ~LIce();
        void moveIce(Figure Figure, LTexture& iceDamegeTexture, dragon& dragon, SDL_Renderer*& aRenderer, int camX, int camY, Tile* Tiles[]);
        bool checkCollisionIceWithDragon(int camX, int camY, dragon dragon);
        void renderIce(Figure Figure, LTexture& iceDamegeTexture, SDL_Renderer*& aRenderer, int camX, int camY );

    private:
        SDL_Rect mIce;
        int iceVelX;
        int iceVelY;
        int framesIce;
        bool direction;
        bool iceCol; // va cham
};
