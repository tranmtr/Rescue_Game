
#pragma once

#include "header.h"
#include "load_maze.h"

//Texture wrapper class
class LTexture
{
	public:
		//Initializes variables
		LTexture();

		//Deallocates memory
		~LTexture();

		//Loads image at specified path
		bool loadFromFile( string path, SDL_Renderer*& gRenderer );

		//Deallocates texture
		void free();

		//Renders texture at given point
		void render( int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE, SDL_Renderer* aRenderer = NULL );

		//Set color modulation
		void setColor( Uint8 red, Uint8 green, Uint8 blue );

		//Set blending
		void setBlendMode( SDL_BlendMode blending );

		//Set alpha modulation
		void setAlpha( Uint8 alpha );

		//Creates image from font string
		bool loadFromRenderedText( string textureText, SDL_Color textColor, TTF_Font*& aFont, SDL_Renderer*& aRenderer );

		//Gets image dimensions
		int getWidth();
		int getHeight();

	private:
		//The actual hardware texture
		SDL_Texture* mTexture;

		//Image dimensions
		int mWidth;
		int mHeight;


};

class Tile
{
    public:
		//Initializes position and type
		Tile( int x, int y, int tileType );

		//Shows the tile
		void render( SDL_Rect& camera,  LTexture& floorTexture, LTexture& wallTexture,  SDL_Renderer*& aRenderer , LTexture& lavaTexture, LTexture& iceTexture,
              LTexture& cakeTexture, LTexture& startTexture, LTexture& finishTexture );

		//Get the tile type
		int getType();

		//Get the collision box
		SDL_Rect getBox();

    private:
		//The attributes of the tile
		SDL_Rect mBox;

		//The tile type
		int mType;
};

//Checks collision box against set of tiles
bool touchesWall( SDL_Rect box, Tile* tiles[],const int& TOTAL_TILES );

//Sets tiles from tile map
bool setTiles( Tile *tiles[], const int& TOTAL_TILES, const int& LEVEL_WIDTH, const int& LEVEL_HEIGHT, const string& pathMaze);

//Loads media
bool loadMedia(SDL_Renderer*& aRenderer, LTexture figureTexture[], LTexture& wallTexture, LTexture& floorTexture,
               LTexture& lavaTexture,LTexture& iceTexture,LTexture& cakeTexture, LTexture& iceImageTexture, LTexture& fireDragonTexture,
               LTexture& fireTexture, LTexture& startTexture, LTexture& finishTexture, LTexture& victoryTexture, LTexture& defeatTexture, LTexture& princessTexture,
               LTexture& nextLevelTexture, LTexture& menuTexture, LTexture& arrowrightMenuTexture, LTexture& arrowleftMenuTexture,
               LTexture& levelAgainTexture, LTexture& arrowdownMenuTexture, LTexture& chooseLevelTexture, LTexture& howToPlayTexture,
               LTexture& backHomeTexture, LTexture& soundOnTexture, LTexture& soundOffTexture );
//Loads sound
bool loadSound(Mix_Music*& soundTrackMusic, Mix_Chunk*& iceDamageChuck, Mix_Chunk*& fireDragonChuck);

void makeSound(bool& checkSound, Mix_Music*& soundTrackMusic);

//Load rec animation
void loadRectAnimation(SDL_Rect clipsIdle[], SDL_Rect clipsRun[], SDL_Rect clipsDie[], SDL_Rect clipsAttack[], SDL_Rect clipsDragon[], SDL_Rect clipsPrincessRun[]);

bool collisionLavaDie(SDL_Rect box, Tile* tiles[], const int& TOTAL_TILES);

bool collisionIceSlow(SDL_Rect box, Tile* tiles[], const int& TOTAL_TILES);

bool collisionCakeFast(SDL_Rect box, Tile* tiles[], const int& TOTAL_TILES);

bool collisionFinishVictory(SDL_Rect box, Tile* tiles[], const int& TOTAL_TILES);

bool collisionPrincess(SDL_Rect mBox, SDL_Rect princessBox);
