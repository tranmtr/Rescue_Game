/*
#pragma once

#include "header.h"
#include "check_collision.h"
#include "load_texture.h"

//The tile
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
*/
