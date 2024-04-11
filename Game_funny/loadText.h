#pragma once
#include "header.h"
#include "load_texture.h"
#include "figure.h"
class LText
{
    public:
        LText();
        ~LText();
        void renderText(SDL_Renderer*& aRenderer, LTexture& textTexture, int camX, int camY);
        void setText(const int& index, Figure Figure, int camX, int camY);
    private:
        int posX;
        int posY;
};

bool loadText(SDL_Renderer*& aRenderer, LTexture textMenuTexture[], TTF_Font*& aFont);
