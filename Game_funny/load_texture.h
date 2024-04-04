
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
		void render( SDL_Rect& camera,  LTexture& floorTexture, LTexture& wallTexture,  SDL_Renderer*& aRenderer , LTexture& lavaTexture, LTexture& iceTexture, LTexture& cakeTexture  );

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
bool touchesWall( SDL_Rect box, Tile* tiles[] );

//Sets tiles from tile map
bool setTiles( Tile *tiles[]);

//Loads media
bool loadMedia(SDL_Renderer*& aRenderer, LTexture& figureTexture, LTexture& wallTexture, LTexture& floorTexture, LTexture& lavaTexture,LTexture& iceTexture,LTexture& cakeTexture,Tile* tiles[] );

//Load rec animation
void loadRectAnimation(SDL_Rect clipsIdle[], SDL_Rect clipsRun[]);

bool collisionLavaDie(SDL_Rect box, Tile* tiles[]);

bool collisionIceSlow(SDL_Rect box, Tile* tiles[]);

bool collisionCakeFast(SDL_Rect box, Tile* tiles[]);




















