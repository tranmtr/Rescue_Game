
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
		//SDL_SetColorKey( loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, 0, 0xFF, 0xFF ) );

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


bool loadMedia(SDL_Renderer*& aRenderer, LTexture figureTexture[], LTexture& wallTexture, LTexture& floorTexture,
                LTexture& lavaTexture, LTexture& iceTexture, LTexture& cakeTexture, LTexture& iceImageTexture, LTexture& fireDragonTexture,
                LTexture& fireTexture, Tile* tiles[] )
{
	//Loading success flag
	bool success = true;

	//Load sprite sheet texture
	if( !figureTexture[ANIMATION_STATUS_IDLE].loadFromFile( "File_Image/image_Figure/16x16_knight_1(phongto)idle.png",aRenderer ) )
	{
		cout << "Failed to load walking animation texture!\n" ;
		success = false;
	}
	if( !figureTexture[ANIMATION_STATUS_RUN].loadFromFile( "File_Image/image_Figure/16x16_knight_1(phongto)run.png",aRenderer ) )
	{
		cout << "Failed to load walking animation texture!\n" ;
		success = false;
	}
	if( !figureTexture[ANIMATION_STATUS_DIE].loadFromFile( "File_Image/image_Figure/16x16_knight_1(phongto)die.png",aRenderer ) )
	{
		cout << "Failed to load walking animation texture!\n" ;
		success = false;
	}
	if( !figureTexture[ANIMATION_STATUS_ATTACK].loadFromFile( "File_Image/image_Figure/16x16_knight_1(phongto)attack.png",aRenderer ) )
	{
		cout << "Failed to load walking animation texture!\n" ;
		success = false;
	}

    // Load wall
	if( !wallTexture.loadFromFile( "File_Image/image_Maze/wall.png", aRenderer ) )
	{
		cout << "Failed to load walking animation texture!\n" ;
		success = false;
	}

    // Load floor
	if( !floorTexture.loadFromFile( "File_Image/image_Maze/nen_mau_tim_2(thu_nho_2).jpg", aRenderer ) )
	{
		cout << "Failed to load walking animation texture!\n" ;
		success = false;
	}

	// Load floor
	if( !lavaTexture.loadFromFile( "File_Image/image_Maze/lavaPixel(80_80).jpg", aRenderer ) )
	{
		cout << "Failed to load walking animation texture!\n" ;
		success = false;
	}

	// Load floor
	if( !iceTexture.loadFromFile( "File_Image/image_Maze/ice_block_slow.jpg", aRenderer ) )
	{
		cout << "Failed to load walking animation texture!\n" ;
		success = false;
	}

	// Load floor

	if( !cakeTexture.loadFromFile( "File_Image/image_Maze/cake_fast(80_80).jpg", aRenderer ) )
	{
		cout << "Failed to load walking animation texture!\n" ;
		success = false;
	}

	if( !iceImageTexture.loadFromFile( "File_Image/image_Figure/ice_damage.png", aRenderer ) )
	{
		cout << "Failed to load walking animation texture!\n" ;
		success = false;
	}

	if( !fireDragonTexture.loadFromFile( "File_Image/image_Figure/SheetDragonRedAll(phun_Lua)(845_240).png", aRenderer ) )
	{
		cout << "Failed to load walking animation texture!\n" ;
		success = false;
	}

	if( !fireTexture.loadFromFile( "File_Image/image_Figure/firePixel(98_60).png", aRenderer ) )
	{
		cout << "Failed to load walking animation texture!\n" ;
		success = false;
	}


    //Load tile map
	if( !setTiles( tiles ) )
	{
		cout << "Failed to load tile set!\n" ;
		success = false;
	}

	return success;
}



void loadRectAnimation(SDL_Rect clipsIdle[], SDL_Rect clipsRun[], SDL_Rect clipsDie[], SDL_Rect clipsAttack[], SDL_Rect clipsDragon[])
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
		clipsRun[ 0 ].y =      43;
		clipsRun[ 0 ].w =      45;
		clipsRun[ 0 ].h =      54;

		clipsRun[ 1 ].x =     168;
		clipsRun[ 1 ].y =      43;
		clipsRun[ 1 ].w =      45;
		clipsRun[ 1 ].h =      54;

		clipsRun[ 2 ].x =     296;
		clipsRun[ 2 ].y =      43;
		clipsRun[ 2 ].w =      45;
		clipsRun[ 2 ].h =      54;

        clipsRun[ 3 ].x =   192*2 + 40;
		clipsRun[ 3 ].y =     43;
		clipsRun[ 3 ].w =    45;
		clipsRun[ 3 ].h =    54;

        clipsRun[ 4 ].x =   256*2+40;
		clipsRun[ 4 ].y =    43;
		clipsRun[ 4 ].w =    45;
		clipsRun[ 4 ].h =    54;

		clipsRun[ 5 ].x =   320*2 + 40;
		clipsRun[ 5 ].y =    43;
		clipsRun[ 5 ].w =    45;
		clipsRun[ 5 ].h =    54;

        clipsRun[ 6 ].x =   384*2 + 40;
		clipsRun[ 6 ].y =    43;
		clipsRun[ 6 ].w =    45;
		clipsRun[ 6 ].h =    54;

        clipsRun[ 7 ].x =   448*2 + 40;
		clipsRun[ 7 ].y =     43;
		clipsRun[ 7 ].w =    45;
		clipsRun[ 7 ].h =    54;

		//Set sprite clips die

        clipsDie[ 0 ].x =      20;
		clipsDie[ 0 ].y =      43;
		clipsDie[ 0 ].w =      84;
		clipsDie[ 0 ].h =      54;

		clipsDie[ 1 ].x =      20+128;
		clipsDie[ 1 ].y =      0+43;
		clipsDie[ 1 ].w =      84;
		clipsDie[ 1 ].h =      54;

		clipsDie[ 2 ].x =      20+256;
		clipsDie[ 2 ].y =      0+43;
		clipsDie[ 2 ].w =      84;
		clipsDie[ 2 ].h =      54;

		clipsDie[ 3 ].x =      20+384;
		clipsDie[ 3 ].y =      0+43;
		clipsDie[ 3 ].w =      84;
		clipsDie[ 3 ].h =      54;

		clipsDie[ 4 ].x =      20+512;
		clipsDie[ 4 ].y =      0+43;
		clipsDie[ 4 ].w =      84;
		clipsDie[ 4 ].h =      54;

		clipsDie[ 5 ].x =      20+640;
		clipsDie[ 5 ].y =      0+43;
		clipsDie[ 5 ].w =      84;
		clipsDie[ 5 ].h =      54;

		//Set sprite clips attack

		clipsAttack[ 0 ].x =      36;
		clipsAttack[ 0 ].y =      43;
		clipsAttack[ 0 ].w =      76;
		clipsAttack[ 0 ].h =      54;

		clipsAttack[ 1 ].x =      36+128;
		clipsAttack[ 1 ].y =      43;
		clipsAttack[ 1 ].w =      76;
		clipsAttack[ 1 ].h =      54;

		clipsAttack[ 2 ].x =      36+256;
		clipsAttack[ 2 ].y =      43;
		clipsAttack[ 2 ].w =      76;
		clipsAttack[ 2 ].h =      54;

		//Dragon

        clipsDragon[ 0 ].x =      0;
		clipsDragon[ 0 ].y =      0;
		clipsDragon[ 0 ].w =      169;
		clipsDragon[ 0 ].h =      80;

		clipsDragon[ 1 ].x =      169;
		clipsDragon[ 1 ].y =      0;
		clipsDragon[ 1 ].w =      169;
		clipsDragon[ 1 ].h =      80;

		clipsDragon[ 2 ].x =      338;
		clipsDragon[ 2 ].y =      0;
		clipsDragon[ 2 ].w =      169;
		clipsDragon[ 2 ].h =      80;

		clipsDragon[ 3 ].x =      507;
		clipsDragon[ 3 ].y =      0;
		clipsDragon[ 3 ].w =      169;
		clipsDragon[ 3 ].h =      80;

		clipsDragon[ 4 ].x =      676;
		clipsDragon[ 4 ].y =      0;
		clipsDragon[ 4 ].w =      169;
		clipsDragon[ 4 ].h =      80;

		clipsDragon[ 5 ].x =      0;
		clipsDragon[ 5 ].y =      80;
		clipsDragon[ 5 ].w =      169;
		clipsDragon[ 5 ].h =      80;

		clipsDragon[ 6 ].x =      169;
		clipsDragon[ 6 ].y =      80;
		clipsDragon[ 6 ].w =      169;
		clipsDragon[ 6 ].h =      80;

		clipsDragon[ 7 ].x =      338;
		clipsDragon[ 7 ].y =      80;
		clipsDragon[ 7 ].w =      169;
		clipsDragon[ 7 ].h =      80;

		clipsDragon[ 8 ].x =      507;
		clipsDragon[ 8 ].y =      80;
		clipsDragon[ 8 ].w =      169;
		clipsDragon[ 8 ].h =      80;

		clipsDragon[ 9 ].x =      676;
		clipsDragon[ 9 ].y =      80;
		clipsDragon[ 9 ].w =      169;
		clipsDragon[ 9 ].h =      80;

		clipsDragon[ 10 ].x =      0;
		clipsDragon[ 10 ].y =      160;
		clipsDragon[ 10 ].w =      169;
		clipsDragon[ 10 ].h =      80;

		clipsDragon[ 11 ].x =      169;
		clipsDragon[ 11 ].y =      160;
		clipsDragon[ 11 ].w =      169;
		clipsDragon[ 11 ].h =      80;

		clipsDragon[ 12 ].x =      338;
		clipsDragon[ 12 ].y =      160;
		clipsDragon[ 12 ].w =      169;
		clipsDragon[ 12 ].h =      80;

		clipsDragon[ 13 ].x =      507;
		clipsDragon[ 13 ].y =      160;
		clipsDragon[ 13 ].w =      169;
		clipsDragon[ 13 ].h =      80;

		clipsDragon[ 14 ].x =      676;
		clipsDragon[ 14 ].y =      160;
		clipsDragon[ 14 ].w =      169;
		clipsDragon[ 14 ].h =      80;
}
