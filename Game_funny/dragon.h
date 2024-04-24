#pragma once

#include "header.h"
#include "load_texture.h"
#include "figure.h"
#include "check_collision.h"

class dragon
{
    public:
        const int DRAGON_BLOOD = 100;
        dragon();
        ~dragon();
        void render(LTexture& fireDragonTexture, SDL_Rect clipsDragon[], SDL_Renderer*& aRenderer, const int& camX, const int& camY);
        void fireMove(Figure& Figure, LTexture& fireTexture, SDL_Renderer*& aRenderer, const int& camX, const int& camY, Tile* Tiles[],
                      const int& TOTAL_TILES, Mix_Chunk*& fireDragonChuck, bool& checkSound );
        int getBloodDragon();
        void decreasedBloodDragon();
        SDL_Rect getBox();
        void setBox(const int& x, const int& y);
        void renderFire(LTexture& fireTexture, SDL_Renderer*& aRenderer, const int& camX, const int& camY);
        bool checkCollisionFireWithFigure(const int& camX, const int& camY, Figure Figure);

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
