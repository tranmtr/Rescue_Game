
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

bool LTexture::loadFromFile( string path, SDL_Renderer*& aRenderer )
{
	//Get rid of preexisting texture
	this->free();

	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
	if( loadedSurface == NULL )
	{
		cout << "Unable to load image %s! SDL_image Error" << path <<  IMG_GetError() ;
	}
	else
	{
		//Color key image
		SDL_SetColorKey( loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, 0, 0xFF, 0xFF ) );

		//Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( aRenderer, loadedSurface );
		if( newTexture == NULL )
		{
			cout << "Unable to create texture from %s! SDL Error:" << path << SDL_GetError() ;
		}
		else
		{
			//Get image dimensions
			this->mWidth = loadedSurface->w;
			this->mHeight = loadedSurface->h;
		}

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}

	//Return success
	this->mTexture = newTexture;
	return this->mTexture != NULL;
}

void LTexture::free()
{
	//Free texture if it exists
	if( this->mTexture != NULL )
	{
		SDL_DestroyTexture( this->mTexture );
		this->mTexture = NULL;
		this->mWidth = 0;
		this->mHeight = 0;
	}
}

void LTexture::setColor( Uint8 red, Uint8 green, Uint8 blue )
{
	//Modulate texture rgb
	SDL_SetTextureColorMod( this->mTexture, red, green, blue );
}

void LTexture::setBlendMode( SDL_BlendMode blending )
{
	//Set blending function
	SDL_SetTextureBlendMode( this->mTexture, blending );
}

void LTexture::setAlpha( Uint8 alpha )
{
	//Modulate texture alpha
	SDL_SetTextureAlphaMod( this->mTexture, alpha );
}

void LTexture::render( int x, int y, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip , SDL_Renderer* aRenderer)
{
	//Set rendering space and render to screen
	SDL_Rect renderQuad = { x, y, this->mWidth, this->mHeight };

	//Set clip rendering dimensions
	if( clip != NULL )
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}

	//Render to screen
	SDL_RenderCopyEx( aRenderer, this->mTexture, clip, &renderQuad, angle, center, flip );
}

int LTexture::getWidth()
{
	return this->mWidth;
}

int LTexture::getHeight()
{
	return this->mHeight;
}


bool loadMedia(SDL_Renderer*& aRenderer, LTexture& figureTexture, LTexture& mazeMapTexture,LTexture& gTileTexture, LTexture& wallTexture, LTexture& floorTexture, Tile* tiles[],SDL_Rect gTileClips[] )
{
	//Loading success flag
	bool success = true;

	//Load sprite sheet texture
	if( !figureTexture.loadFromFile( "File_Image/image_Figure/16x16_knight_1(phongto)testIDLEvaRUN.png",aRenderer ) )
	{
		cout << "Failed to load walking animation texture!\n" ;
		success = false;
	}

	if(!mazeMapTexture.loadFromFile("File_Image/image_Maze/testmap.jpg", aRenderer))
    {
        cout << "Failed to load walking animation texture!\n" ;
		success = false;
    }
    else
    {
        cout << "OK" << "   ";
    }

    if( !gTileTexture.loadFromFile( "File_Image/image_Maze/tiles.png", aRenderer ) )
	{
		printf( "Failed to load tile set texture!\n" );
		success = false;
	}

	if( !wallTexture.loadFromFile( "File_Image/image_Maze/bottomtest(80_80).jpg", aRenderer ) )
	{
		printf( "Failed to load tile set texture!\n" );
		success = false;
	}

	if( !floorTexture.loadFromFile( "File_Image/image_Maze/nen_mau_tim_2(thu_nho_2).jpg", aRenderer ) )
	{
		printf( "Failed to load tile set texture!\n" );
		success = false;
	}

    //Load tile map
	if( !setTiles( tiles, gTileClips ) )
	{
		printf( "Failed to load tile set!\n" );
		success = false;
	}

	return success;
}



void loadRectAnimation(SDL_Rect clipsIdle[], SDL_Rect clipsRun[])
{
    //Set sprite clips idle

        clipsIdle[ 0 ].x =    40;
        clipsIdle[ 0 ].y =    43;
        clipsIdle[ 0 ].w =    45;
        clipsIdle[ 0 ].h =    54;

        clipsIdle[ 1 ].x =   168;
        clipsIdle[ 1 ].y =    43;
        clipsIdle[ 1 ].w =    45;
        clipsIdle[ 1 ].h =    54;

        clipsIdle[ 2 ].x =   296;
        clipsIdle[ 2 ].y =    43;
        clipsIdle[ 2 ].w =    45;
        clipsIdle[ 2 ].h =    54;

        clipsIdle[ 3 ].x =   424;
        clipsIdle[ 3 ].y =    43;
        clipsIdle[ 3 ].w =    45;
        clipsIdle[ 3 ].h =    54;

        clipsIdle[ 4 ].x =   552;
        clipsIdle[ 4 ].y =    43;
        clipsIdle[ 4 ].w =    45;
        clipsIdle[ 4 ].h =    54;


        //Set sprite clips run

        clipsRun[ 0 ].x =      40;
		clipsRun[ 0 ].y =     171;
		clipsRun[ 0 ].w =      45;
		clipsRun[ 0 ].h =      54;

		clipsRun[ 1 ].x =     168;
		clipsRun[ 1 ].y =     171;
		clipsRun[ 1 ].w =      45;
		clipsRun[ 1 ].h =      54;

		clipsRun[ 2 ].x =     296;
		clipsRun[ 2 ].y =     171;
		clipsRun[ 2 ].w =      45;
		clipsRun[ 2 ].h =      54;

        clipsRun[ 3 ].x =   192*2 + 40;
		clipsRun[ 3 ].y =    171;
		clipsRun[ 3 ].w =    45;
		clipsRun[ 3 ].h =    54;

        clipsRun[ 4 ].x =   256*2+40;
		clipsRun[ 4 ].y =    171;
		clipsRun[ 4 ].w =    45;
		clipsRun[ 4 ].h =    54;

		clipsRun[ 5 ].x =   320*2 + 40;
		clipsRun[ 5 ].y =    171;
		clipsRun[ 5 ].w =    45;
		clipsRun[ 5 ].h =    54;

        clipsRun[ 6 ].x =   384*2 + 40;
		clipsRun[ 6 ].y =    171;
		clipsRun[ 6 ].w =    45;
		clipsRun[ 6 ].h =    54;

        clipsRun[ 7 ].x =   448*2 + 40;
		clipsRun[ 7 ].y =    171;
		clipsRun[ 7 ].w =    45;
		clipsRun[ 7 ].h =    54;
}

