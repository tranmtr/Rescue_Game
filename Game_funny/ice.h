#pragma once

#include "header.h"
#include "load_texture.h"
#include "figure.h"
#include "check_collision.h"
class LIce
{
    public:
        static const int ICE_DAMAGE_WIDTH = 43;
		static const int ICE_DAMAGE_HEIGHT = 32;
		static const int ICE_DAMAGE_VEL = 5;
		static const int ICE_DAMAGE_MAX = 25;
		static const int DRAGON_BLOOD_MAX = 100;
        LIce();
        ~LIce();
        void moveIce(Figure Figure, LTexture& iceDamegeTexture, SDL_Renderer*& aRenderer, int camX, int camY, Tile* Tiles[]);
        bool checkCollisionIceWithMonster(int camX, int camY);
        void renderIce(Figure Figure, LTexture& iceDamegeTexture, SDL_Renderer*& aRenderer, int camX, int camY );
        SDL_Rect getDragon();
        void renderDragon(LTexture& fireDragonTexture, int camX, int camY, SDL_Rect clipsDragon[], SDL_Renderer*& aRenderer);
        int getBloodDragon();
    private:
        SDL_Rect mIce;
        int iceVelX;
        int iceVelY;
        int framesIce;
        bool direction;
        SDL_Rect dragon;
        SDL_Rect bloodDragon;
        int framesDragon;
        SDL_Rect fire;
        bool col;
};
