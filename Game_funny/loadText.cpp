#pragma once

#include"loadText.h"


LText::LText()
{
    posX = 0;
}
LText::~LText()
{

}
void LText::renderText(SDL_Renderer*& aRenderer, LTexture& textTexture, int camX, int camY)
{
    textTexture.render( this->posX - camX  , this->posY - camY , NULL, 0, NULL, SDL_FLIP_NONE, aRenderer );
}

void LText::setText(int x, int y)
{
    this->posX = x;
    this->posY = y;
}

bool loadText(SDL_Renderer*& aRenderer, LTexture& textTexture, TTF_Font*& aFont)
{
    //Loading success flag
	bool success = true;
	aFont = TTF_OpenFont( "lazy.ttf", 18 );
    SDL_Color textColor = { 237,157,84 };

    if( !textTexture.loadFromRenderedText( "tran mt", textColor, aFont, aRenderer ) )
    {
        printf( "Failed to render text texture!\n" );
        success = false;
    }

	return success;
}
