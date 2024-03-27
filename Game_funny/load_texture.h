
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

		//Set color modulation
		void setColor( Uint8 red, Uint8 green, Uint8 blue );

		//Set blending
		void setBlendMode( SDL_BlendMode blending );

		//Set alpha modulation
		void setAlpha( Uint8 alpha );

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
		void render( SDL_Rect& camera, LTexture& gTileTexture, LTexture& floorTexture, LTexture& wallTexture, SDL_Rect gTileClips[], SDL_Renderer*& aRenderer   );

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
bool setTiles( Tile *tiles[], SDL_Rect gTileClips[] );


//Loads media
bool loadMedia(SDL_Renderer*& aRenderer, LTexture& figureTexture, LTexture& mazeMapTexture,LTexture& gTileTexture, LTexture& wallTexture, LTexture& floorTexture, Tile* tiles[],SDL_Rect gTileClips[] );

//Load rec animation
void loadRectAnimation(SDL_Rect clipsIdle[], SDL_Rect clipsRun[]);


