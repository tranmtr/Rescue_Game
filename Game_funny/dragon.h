#pragma once

#include "header.h"
#include "load_texture.h"
#include "figure.h"
#include "check_collision.h"

class dragon
{
    public:
        static const int DRAGON_BLOOD = 100;
        dragon();
        ~dragon();
        void render(LTexture& fireDragonTexture, SDL_Rect clipsDragon[], SDL_Renderer*& aRenderer, int camX, int camY);
        void fireMove(Figure& Figure, LTexture& fireTexture, SDL_Renderer*& aRenderer, int camX, int camY, Tile* Tiles[], const int& TOTAL_TILES );
        int getBloodDragon();
        void decreasedBloodDragon();
        SDL_Rect getBox();
        void setBox(int x, int y);
        void renderFire(LTexture& fireTexture, SDL_Renderer*& aRenderer, int camX, int camY);
        bool checkCollisionFireWithFigure(int camX, int camY, Figure Figure);
    private:
        SDL_Rect box;
        int framesDragon;
        SDL_Rect bloodDragon;
        int framesFire;
        SDL_Rect fireBox;
        bool fireCol;
        int fireVel;

};

void setDragon(Tile* tiles[], dragon dragon[], const int& TOTAL_TILES);
