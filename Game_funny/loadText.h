#pragma once
#include "header.h"
#include "load_texture.h"

class LText
{
    public:
        LText();
        ~LText();
        void renderText(SDL_Renderer*& aRenderer, LTexture& textTexture);
        void setText(const int& index);
    private:
        int posX;
        int posY;
};

bool loadText(SDL_Renderer*& aRenderer, LTexture textMenuTexture[], TTF_Font*& aFont);
