#pragma once

#include"header.h"
#include"load_texture.h"
#include"figure.h"

class load_Mouse
{
    public:
        load_Mouse();

        void setBoxMouse(int x, int y, int w, int h);

        void handleEvent( SDL_Event& e, Figure Figure );

        void render();

        bool getNextLevel();

    private:
        SDL_Rect mBox;

		int mCurrentSprite;

		bool nextLevel;
};
