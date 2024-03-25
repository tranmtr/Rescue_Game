
#pragma once

#include "load_texture.h"

LTexture::LTexture()
{
	//Initialize
	mTexture = NULL;
	mWidth = 0;
	mHeight = 0;
}

LTexture::~LTexture()
{
	//Deallocate
	free();
}

bool LTexture::loadFromFile( std::string path, SDL_Renderer*& gRenderer )
{
	//Get rid of preexisting texture
	free();

	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
	if( loadedSurface == NULL )
	{
		printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
	}
	else
	{
		//Color key image
		SDL_SetColorKey( loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, 0, 0xFF, 0xFF ) );

		//Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
		if( newTexture == NULL )
		{
			printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		}
		else
		{
			//Get image dimensions
			mWidth = loadedSurface->w;
			mHeight = loadedSurface->h;
		}

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}

	//Return success
	mTexture = newTexture;
	return mTexture != NULL;
}

void LTexture::free()
{
	//Free texture if it exists
	if( mTexture != NULL )
	{
		SDL_DestroyTexture( mTexture );
		mTexture = NULL;
		mWidth = 0;
		mHeight = 0;
	}
}

void LTexture::setColor( Uint8 red, Uint8 green, Uint8 blue )
{
	//Modulate texture rgb
	SDL_SetTextureColorMod( mTexture, red, green, blue );
}

void LTexture::setBlendMode( SDL_BlendMode blending )
{
	//Set blending function
	SDL_SetTextureBlendMode( mTexture, blending );
}

void LTexture::setAlpha( Uint8 alpha )
{
	//Modulate texture alpha
	SDL_SetTextureAlphaMod( mTexture, alpha );
}

void LTexture::render( int x, int y, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip , SDL_Renderer* gRenderer)
{
	//Set rendering space and render to screen
	SDL_Rect renderQuad = { x, y, mWidth, mHeight };

	//Set clip rendering dimensions
	if( clip != NULL )
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}

	//Render to screen
	SDL_RenderCopyEx( gRenderer, mTexture, clip, &renderQuad, angle, center, flip );
}

int LTexture::getWidth()
{
	return mWidth;
}

int LTexture::getHeight()
{
	return mHeight;
}




bool loadMedia(SDL_Renderer*& gRenderer, LTexture& figureTexture, SDL_Rect gSpriteClipsIdle[], SDL_Rect gSpriteClipsRun[] )
{
	//Loading success flag
	bool success = true;

	//Load sprite sheet texture
	if( !figureTexture.loadFromFile( "File_Image/image_Figure/16x16_knight_1(phongto)testIDLEvaRUN.png",gRenderer ) )
	{
		printf( "Failed to load walking animation texture!\n" );
		success = false;
	}
	else
	{
		//Set sprite clips idle

        gSpriteClipsIdle[ 0 ].x =    40;
        gSpriteClipsIdle[ 0 ].y =    43;
        gSpriteClipsIdle[ 0 ].w =    45;
        gSpriteClipsIdle[ 0 ].h =    54;

        gSpriteClipsIdle[ 1 ].x =   168;
        gSpriteClipsIdle[ 1 ].y =    43;
        gSpriteClipsIdle[ 1 ].w =    45;
        gSpriteClipsIdle[ 1 ].h =    54;

        gSpriteClipsIdle[ 2 ].x =   296;
        gSpriteClipsIdle[ 2 ].y =    43;
        gSpriteClipsIdle[ 2 ].w =    45;
        gSpriteClipsIdle[ 2 ].h =    54;

        gSpriteClipsIdle[ 3 ].x =   424;
        gSpriteClipsIdle[ 3 ].y =    43;
        gSpriteClipsIdle[ 3 ].w =    45;
        gSpriteClipsIdle[ 3 ].h =    54;

        gSpriteClipsIdle[ 4 ].x =   552;
        gSpriteClipsIdle[ 4 ].y =    43;
        gSpriteClipsIdle[ 4 ].w =    45;
        gSpriteClipsIdle[ 4 ].h =    54;


        //Set sprite clips run

        gSpriteClipsRun[ 0 ].x =      40;
		gSpriteClipsRun[ 0 ].y =     171;
		gSpriteClipsRun[ 0 ].w =      45;
		gSpriteClipsRun[ 0 ].h =      54;

		gSpriteClipsRun[ 1 ].x =     168;
		gSpriteClipsRun[ 1 ].y =     171;
		gSpriteClipsRun[ 1 ].w =      45;
		gSpriteClipsRun[ 1 ].h =      54;

		gSpriteClipsRun[ 2 ].x =     296;
		gSpriteClipsRun[ 2 ].y =     171;
		gSpriteClipsRun[ 2 ].w =      45;
		gSpriteClipsRun[ 2 ].h =      54;

        gSpriteClipsRun[ 3 ].x =   192*2 + 40;
		gSpriteClipsRun[ 3 ].y =    171;
		gSpriteClipsRun[ 3 ].w =    45;
		gSpriteClipsRun[ 3 ].h =    54;

        gSpriteClipsRun[ 4 ].x =   256*2+40;
		gSpriteClipsRun[ 4 ].y =    171;
		gSpriteClipsRun[ 4 ].w =    45;
		gSpriteClipsRun[ 4 ].h =    54;

		gSpriteClipsRun[ 5 ].x =   320*2 + 40;
		gSpriteClipsRun[ 5 ].y =    171;
		gSpriteClipsRun[ 5 ].w =    45;
		gSpriteClipsRun[ 5 ].h =    54;

        gSpriteClipsRun[ 6 ].x =   384*2 + 40;
		gSpriteClipsRun[ 6 ].y =    171;
		gSpriteClipsRun[ 6 ].w =    45;
		gSpriteClipsRun[ 6 ].h =    54;

        gSpriteClipsRun[ 7 ].x =   448*2 + 40;
		gSpriteClipsRun[ 7 ].y =    171;
		gSpriteClipsRun[ 7 ].w =    45;
		gSpriteClipsRun[ 7 ].h =    54;
	}

	return success;
}


