#pragma once

#include"loadText.h"


LText::LText()
{
    posX = 0;
    posY = 0;
}
LText::~LText()
{

}
void LText::renderText(SDL_Renderer*& aRenderer, LTexture& textTexture, int camX, int camY)
{
    textTexture.render( this->posX - camX  , this->posY - camY , NULL, 0, NULL, SDL_FLIP_NONE, aRenderer );
}

void LText::setText(const int& index, Figure Figure, int camX, int camY)
{
    if(index == NAME_PLAYER)
    {
        this->posX = Figure.getBoxFigure().x;
        this->posY = Figure.getBoxFigure().y - 15;
    }
    else if(index == NAME_GAME)
    {
        this->posX = Figure.getBoxFigure().x;
        this->posY = Figure.getBoxFigure().y - 30;
    }
    else if(index == PLAY_GAME)
    {
        this->posX = Figure.getBoxFigure().x;
        this->posY = Figure.getBoxFigure().y - 45;
    }
    else if(index == EXIT_GAME)
    {
        this->posX = Figure.getBoxFigure().x;
        this->posY = Figure.getBoxFigure().y - 60;
    }
    else if(index == NEXT_LEVEL)
    {
        this->posX = SCREEN_WIDTH - 100 + camX;
        this->posY = SCREEN_HEIGHT - 50 + camY;
    }
}

bool loadText(SDL_Renderer*& aRenderer, LTexture textMenuTexture[], TTF_Font*& aFont)
{
    //Loading success flag
	bool success = true;
	aFont = TTF_OpenFont( "lazy.ttf", 18 );
    SDL_Color textColor[TOTAL_TEXT];

    textColor[NAME_PLAYER] = { 237,157,84 };
    textColor[NAME_GAME] = { 237,157,84 };
    textColor[PLAY_GAME] = { 237,157,84 };
    textColor[EXIT_GAME] = { 255, 0, 31 };
    textColor[NEXT_LEVEL] = { 255, 0, 31 };

    if( !textMenuTexture[NAME_PLAYER].loadFromRenderedText( "tran mtr", textColor[NAME_PLAYER], aFont, aRenderer ) )
    {
        printf( "Failed to render text texture!\n" );
        success = false;
    }
    if( !textMenuTexture[NAME_GAME].loadFromRenderedText( "RESCUE", textColor[NAME_GAME], aFont, aRenderer ) )
    {
        printf( "Failed to render text texture!\n" );
        success = false;
    }
    if( !textMenuTexture[PLAY_GAME].loadFromRenderedText( "PLAY", textColor[PLAY_GAME], aFont, aRenderer ) )
    {
        printf( "Failed to render text texture!\n" );
        success = false;
    }
    if( !textMenuTexture[EXIT_GAME].loadFromRenderedText( "EXIT", textColor[EXIT_GAME], aFont, aRenderer ) )
    {
        printf( "Failed to render text texture!\n" );
        success = false;
    }
    if( !textMenuTexture[NEXT_LEVEL].loadFromRenderedText( "NEXT LEVEL", textColor[EXIT_GAME], aFont, aRenderer ) )
    {
        printf( "Failed to render text texture!\n" );
        success = false;
    }

	return success;
}
