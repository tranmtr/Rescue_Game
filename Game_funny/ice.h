#pragma once

#include "header.h"
#include "load_texture.h"
#include "figure.h"
#include "check_collision.h"
#include "dragon.h"
#include <ctime>
class LIce
{
    public:
        static const int ICE_DAMAGE_WIDTH = 43;
		static const int ICE_DAMAGE_HEIGHT = 32;
		static const int ICE_DAMAGE_VEL = 5;

        LIce();
        ~LIce();
        void moveIce(Figure Figure, LTexture& iceDamegeTexture, dragon& dragon, SDL_Renderer*& aRenderer, int camX, int camY, Tile* Tiles[], const int& TOTAL_TILES, const int& TOTAL_DRAGON);
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
