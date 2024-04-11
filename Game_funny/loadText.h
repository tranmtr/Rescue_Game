#pragma once
#include "header.h"
#include "load_texture.h"

class LText
{
    public:
        LText();
        ~LText();
        void renderText(SDL_Renderer*& aRenderer, LTexture& textTexture, int camX, int camY);
        void setText(int x, int y);
    private:
        int posX;
        int posY;
};

bool loadText(SDL_Renderer*& aRenderer, LTexture& textTexture, TTF_Font*& aFont);
