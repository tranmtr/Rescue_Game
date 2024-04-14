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
void LText::renderText(SDL_Renderer*& aRenderer, LTexture& textTexture)
{
    textTexture.render( this->posX , this->posY  , NULL, 0, NULL, SDL_FLIP_NONE, aRenderer );
}

void LText::setText(const int& index)
{
    if(index == GAME_HEALING)
    {
        this->posX = 0;
        this->posY = 30;
    }
    else if(index == GAME_GO_GET_CAKE)
    {
        this->posX = 0;
        this->posY = 30;
    }
    else if(index == GAME_GOT_CAKE)
    {
        this->posX = 0;
        this->posY = 30;
    }
    else if(index == GAME_CURSE_NOT_LIFTED)
    {
        this->posX = 0;
        this->posY = 15;
    }
    else if(index == GAME_CURSE_LIFTED)
    {
        this->posX = 0;
        this->posY = 15;
    }
    else if(index == PLAY_AGAIN)
    {
        this->posX = SCREEN_WIDTH - 105;
        this->posY = SCREEN_HEIGHT - 50;
    }
    else if(index == NEXT_LEVEL)
    {
        this->posX = SCREEN_WIDTH - 100;
        this->posY = SCREEN_HEIGHT - 50;
    }
}

bool loadText(SDL_Renderer*& aRenderer, LTexture textMenuTexture[], TTF_Font*& aFont)
{
    //Loading success flag
	bool success = true;
	aFont = TTF_OpenFont( "lazy.ttf", 18 );
    SDL_Color textColor[TOTAL_TEXT];

    textColor[GAME_HEALING] = { 255,255,255 };
    textColor[GAME_GO_GET_CAKE] = { 255,255,255 };
    textColor[GAME_GOT_CAKE] = { 248, 241, 119 };
    textColor[GAME_CURSE_NOT_LIFTED] = { 255, 255, 255 };
    textColor[GAME_CURSE_LIFTED] = { 248, 241, 119 };
    textColor[PLAY_AGAIN] = { 255, 0, 31 };
    textColor[NEXT_LEVEL] = { 255, 0, 31 };

    if( !textMenuTexture[GAME_HEALING].loadFromRenderedText( "YOU ARE HEALING.", textColor[GAME_HEALING], aFont, aRenderer ) )
    {
        printf( "Failed to render text texture!\n" );
        success = false;
    }
    if( !textMenuTexture[GAME_GO_GET_CAKE].loadFromRenderedText( "GO GET THE CAKE.", textColor[GAME_GO_GET_CAKE], aFont, aRenderer ) )
    {
        printf( "Failed to render text texture!\n" );
        success = false;
    }
    if( !textMenuTexture[GAME_GOT_CAKE].loadFromRenderedText( "YOU'VE GOT THE CAKE.", textColor[GAME_GOT_CAKE], aFont, aRenderer ) )
    {
        printf( "Failed to render text texture!\n" );
        success = false;
    }
    if( !textMenuTexture[GAME_CURSE_NOT_LIFTED].loadFromRenderedText( "THE CURSE ON THE PRINCESS HAS NOT BEEN LIFTED YET.", textColor[GAME_CURSE_NOT_LIFTED], aFont, aRenderer ) )
    {
        printf( "Failed to render text texture!\n" );
        success = false;
    }
    if( !textMenuTexture[GAME_CURSE_LIFTED].loadFromRenderedText( "THE CURSE ON THE PRINCESS HAS BEEN LIFTED.", textColor[GAME_CURSE_LIFTED], aFont, aRenderer ) )
    {
        printf( "Failed to render text texture!\n" );
        success = false;
    }
    if( !textMenuTexture[PLAY_AGAIN].loadFromRenderedText( "PLAY AGAIN", textColor[PLAY_AGAIN], aFont, aRenderer ) )
    {
        printf( "Failed to render text texture!\n" );
        success = false;
    }
    if( !textMenuTexture[NEXT_LEVEL].loadFromRenderedText( "NEXT LEVEL", textColor[NEXT_LEVEL], aFont, aRenderer ) )
    {
        printf( "Failed to render text texture!\n" );
        success = false;
    }

	return success;
}
