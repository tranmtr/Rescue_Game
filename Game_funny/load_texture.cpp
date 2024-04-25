
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
	//cout << 1 << endl;
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
		cout << "Unable to load image ! SDL_image Error: " << path <<  IMG_GetError() ;
	}
	else
	{
		//Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( aRenderer, loadedSurface );
		if( newTexture == NULL )
		{
			cout << "Unable to create texture from ! SDL Error:" << path << SDL_GetError() ;
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

bool LTexture::loadFromRenderedText( string textureText, SDL_Color textColor, TTF_Font*& aFont, SDL_Renderer*& aRenderer )
{
	//Get rid of preexisting texture
	free();

	//Render text surface
	SDL_Surface* textSurface = TTF_RenderText_Solid( aFont, textureText.c_str(), textColor );
	if( textSurface == NULL )
	{
		printf( "Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError() );
		cout << "NOTTTT" << endl;
	}
	else
	{
		//Create texture from surface pixels
        mTexture = SDL_CreateTextureFromSurface( aRenderer, textSurface );
		if( mTexture == NULL )
		{
			cout << "Unable to create texture from rendered text! SDL Error: " <<  SDL_GetError() ;
		}
		else
		{
			//Get image dimensions
			mWidth = textSurface->w;
			mHeight = textSurface->h;
		}

		//Get rid of old surface
		SDL_FreeSurface( textSurface );
	}

	//Return success
	return mTexture != NULL;
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
                LTexture& fireTexture, LTexture& startTexture, LTexture& finishTexture, LTexture& victoryTexture, LTexture& defeatTexture,
                LTexture& princessTexture,LTexture& nextLevelTexture, LTexture& menuTexture, LTexture& arrowrightMenuTexture,
                LTexture& arrowleftMenuTexture, LTexture& levelAgainTexture, LTexture& arrowdownMenuTexture, LTexture& chooseLevelTexture,
                LTexture& howToPlayTexture, LTexture& backHomeTexture, LTexture& soundOnTexture, LTexture& soundOffTexture)
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
		cout << "Failed to load run animation texture!\n" ;
		success = false;
	}
	if( !figureTexture[ANIMATION_STATUS_DIE].loadFromFile( "File_Image/image_Figure/16x16_knight_1(phongto)die.png",aRenderer ) )
	{
		cout << "Failed to load die animation texture!\n" ;
		success = false;
	}
	if( !figureTexture[ANIMATION_STATUS_ATTACK].loadFromFile( "File_Image/image_Figure/16x16_knight_1(phongto)attack.png",aRenderer ) )
	{
		cout << "Failed to load attack animation texture!\n" ;
		success = false;
	}

    // Load wall
	if( !wallTexture.loadFromFile( "File_Image/image_Maze/wall.png", aRenderer ) )
	{
		cout << "Failed to load wall texture!\n" ;
		success = false;
	}

    // Load floor
	if( !floorTexture.loadFromFile( "File_Image/image_Maze/nen_mau_tim_2(thu_nho_2).jpg", aRenderer ) )
	{
		cout << "Failed to load floor texture!\n" ;
		success = false;
	}

	// Load floor
	if( !lavaTexture.loadFromFile( "File_Image/image_Maze/lavaPixel(80_80).jpg", aRenderer ) )
	{
		cout << "Failed to load lava block texture!\n" ;
		success = false;
	}

	// Load floor
	if( !iceTexture.loadFromFile( "File_Image/image_Maze/ice_block_slow.jpg", aRenderer ) )
	{
		cout << "Failed to load ice block texture!\n" ;
		success = false;
	}

	// Load floor

	if( !cakeTexture.loadFromFile( "File_Image/image_Maze/cake_fast(80_80).jpg", aRenderer ) )
	{
		cout << "Failed to load cake block texture!\n" ;
		success = false;
	}

	if( !iceImageTexture.loadFromFile( "File_Image/image_Figure/ice_damage.png", aRenderer ) )
	{
		cout << "Failed to load ice damage animation texture!\n" ;
		success = false;
	}

	if( !fireDragonTexture.loadFromFile( "File_Image/image_Figure/SheetDragonRedAll(phun_Lua)(845_240).png", aRenderer ) )
	{
		cout << "Failed to load dragon animation texture!\n" ;
		success = false;
	}

	if( !fireTexture.loadFromFile( "File_Image/image_Figure/firePixel(98_60).png", aRenderer ) )
	{
		cout << "Failed to load fire texture!\n" ;
		success = false;
	}

	if( !startTexture.loadFromFile( "File_Image/image_Maze/start_mau_ghi(80_80).jpg", aRenderer ) )
	{
		cout << "Failed to load start block texture!\n" ;
		success = false;
	}

	if( !finishTexture.loadFromFile( "File_Image/image_Maze/finish_mau_xanh_la_cay.jpg", aRenderer ) )
	{
		cout << "Failed to load finish block texture!\n" ;
		success = false;
	}
	if( !victoryTexture.loadFromFile( "File_Image/image_Maze/victory_tach_nen.png", aRenderer ) )
	{
		cout << "Failed to load victory texture!\n" ;
		success = false;
	}
	if( !defeatTexture.loadFromFile( "File_Image/image_Maze/defeat_tach_nen.png", aRenderer ) )
	{
		cout << "Failed to load defeat texture!\n" ;
		success = false;
	}
	if( !princessTexture.loadFromFile( "File_Image/image_Figure/cong_chua_vay_hong_xoa_nen_run(210_114).png", aRenderer ) )
	{
		cout << "Failed to load princess animation texture!\n" ;
		success = false;
	}
	if( !nextLevelTexture.loadFromFile("File_Image/image_Menu/mui_ten_next_level.png", aRenderer))
    {
        cout << "Failed to load next level texture!\n" ;
		success = false;
    }
    if( !menuTexture.loadFromFile("File_Image/image_Menu/MENU_BACKGROUD.png", aRenderer))
    {
        cout << "Failed to load background menu texture!\n" ;
		success = false;
    }
    if( !arrowrightMenuTexture.loadFromFile("File_Image/image_Menu/right_arrow_xoa_nen(45_35).png", aRenderer))
    {
        cout << "Failed to load right arrow texture!\n" ;
		success = false;
    }
    if( !arrowleftMenuTexture.loadFromFile("File_Image/image_Menu/left_arrow_xoa_nen(45_35).png", aRenderer))
    {
        cout << "Failed to load left arrow texture!\n" ;
		success = false;
    }
    if( !levelAgainTexture.loadFromFile("File_Image/image_Menu/level_again.png", aRenderer))
    {
        cout << "Failed to load level again texture!\n" ;
		success = false;
    }
    if( !arrowdownMenuTexture.loadFromFile("File_Image/image_Menu/down_menu(35_45).png", aRenderer))
    {
        cout << "Failed to load down arrow texture!\n" ;
		success = false;
    }
    if( !chooseLevelTexture.loadFromFile("File_Image/image_Menu/Choose_level_menu(550_386).png", aRenderer))
    {
        cout << "Failed to load choose level menu texture!\n" ;
		success = false;
    }
    if( !howToPlayTexture.loadFromFile("File_Image/image_Menu/How_to_play_menu(550_382).png", aRenderer))
    {
        cout << "Failed to load how to play menu texture!\n" ;
		success = false;
    }
    if( !backHomeTexture.loadFromFile("File_Image/image_Menu/way_back_home.png", aRenderer))
    {
        cout << "Failed to load back home texture!\n" ;
		success = false;
    }
    if( !soundOnTexture.loadFromFile("File_Image/image_Menu/bat_loa(37_32).png", aRenderer))
    {
        cout << "Failed to load sound on texture!\n" ;
		success = false;
    }
    if( !soundOffTexture.loadFromFile("File_Image/image_Menu/tat_loa(37_42).png", aRenderer))
    {
        cout << "Failed to load sound off texture!\n" ;
		success = false;
    }
	return success;
}

//Loads sound
bool loadSound(Mix_Music*& soundTrackMusic, Mix_Chunk*& iceDamageChuck, Mix_Chunk*& fireDragonChuck)
{
    //Loading success flag
	bool success = true;

	//Load music
	soundTrackMusic = Mix_LoadMUS( "music/soundTrack.wav" );
	if( soundTrackMusic == NULL )
	{
		cout << "Failed to load sound track music! SDL_mixer Error: " <<  Mix_GetError() ;
		success = false;
	}

	//Load sound effects
	iceDamageChuck = Mix_LoadWAV( "music/iceDamage.wav" );
	if( iceDamageChuck == NULL )
	{
		cout << "Failed to load ice damage sound effect! SDL_mixer Error: " << Mix_GetError() ;
		success = false;
	}

	fireDragonChuck = Mix_LoadWAV( "music/fireDragon.wav" );
	if( fireDragonChuck == NULL )
	{
		cout << "Failed to load fire damage sound effect! SDL_mixer Error: " << Mix_GetError() ;
		success = false;
	}

	return success;
}

void makeSound(bool& checkSound, Mix_Music*& soundTrackMusic)
{
    if(checkSound == true)
    {
        if( Mix_PlayingMusic() == 0 )
        {
            //Play the music
            Mix_PlayMusic( soundTrackMusic, -1 );
        }
        else
        {
            Mix_ResumeMusic();
        }
    }
    else
    {
        Mix_PauseMusic();
    }
}

void loadRectAnimation(SDL_Rect clipsIdle[], SDL_Rect clipsRun[], SDL_Rect clipsDie[], SDL_Rect clipsAttack[], SDL_Rect clipsDragon[], SDL_Rect clipsPrincessRun[])
{
    //Set sprite clips idle

    clipsIdle[ 0 ] = {40, 43, 45, 54};
    clipsIdle[ 1 ] = {168, 43, 45, 54};
    clipsIdle[ 2 ] = {296, 43, 45, 54};
    clipsIdle[ 3 ] = {424, 43, 45, 54};
    clipsIdle[ 4 ] = {552, 43, 45, 54};

    //Set sprite clips run

    clipsRun[ 0 ] = {40, 43, 45, 54};
    clipsRun[ 1 ] = {168, 43, 45, 54};
    clipsRun[ 2 ] = {296, 43, 45, 54};
    clipsRun[ 3 ] = {424, 43, 45, 54};
    clipsRun[ 4 ] = {552, 43, 45, 54};
    clipsRun[ 5 ] = {680, 43, 45, 54};
    clipsRun[ 6 ] = {808, 43, 45, 54};
    clipsRun[ 7 ] = {936, 43, 45, 54};

    //Set sprite clips die

    clipsDie[ 0 ] = {20, 43, 84, 54};
    clipsDie[ 1 ] = {148, 43, 84, 54};
    clipsDie[ 2 ] = {276, 43, 84, 54};
    clipsDie[ 3 ] = {404, 43, 84, 54};
    clipsDie[ 4 ] = {532, 43, 84, 54};
    clipsDie[ 5 ] = {660, 43, 84, 54};

    //Set sprite clips attack

    clipsAttack[ 0 ] = {36, 43, 76, 54};
    clipsAttack[ 1 ] = {164, 43, 76, 54};
    clipsAttack[ 2 ] = {292, 43, 76, 54};

    //Dragon

    clipsDragon[ 0 ] = {0, 0, 169, 80};
    clipsDragon[ 1 ] = {169, 0, 169, 80};
    clipsDragon[ 2 ] = {338, 0, 169, 80};
    clipsDragon[ 3 ] = {507, 0, 169, 80};
    clipsDragon[ 4 ] = {676, 0, 169, 80};
    clipsDragon[ 5 ] = {0, 80, 169, 80};
    clipsDragon[ 6 ] = {169, 80, 169, 80};
    clipsDragon[ 7 ] = {338, 80, 169, 80};
    clipsDragon[ 8 ] = {507, 80, 169, 80};
    clipsDragon[ 9 ] = {676, 80, 169, 80};
    clipsDragon[ 10 ] = {0, 160, 169, 80};
    clipsDragon[ 11 ] = {169, 160, 169, 80};
    clipsDragon[ 12 ] = {338, 160, 169, 80};
    clipsDragon[ 13 ] = {507, 160, 169, 80};
    clipsDragon[ 14 ] = {676, 160, 169, 80};

    //Princess
    clipsPrincessRun[ 0 ] = {0, 0, 35, 57};
    clipsPrincessRun[ 1 ] = {35, 0, 35, 57};
    clipsPrincessRun[ 2 ] = {70, 0, 35, 57};
    clipsPrincessRun[ 3 ] = {105, 0, 35, 57};
    clipsPrincessRun[ 4 ] = {140, 0, 35, 57};
    clipsPrincessRun[ 5 ] = {175, 0, 35, 57};
    clipsPrincessRun[ 6 ] = {0, 57, 35, 57};
    clipsPrincessRun[ 7 ] = {35, 57, 35, 57};
    clipsPrincessRun[ 8 ] = {70, 57, 35, 57};
    clipsPrincessRun[ 9 ] = {105, 57, 35, 57};
    clipsPrincessRun[ 10 ] = {140, 57, 35, 57};
    clipsPrincessRun[ 11 ] = {175, 57, 35, 57};
}
