#pragma once

//#include "load_maze.h"
#include "load_texture.h"
#include "check_collision.h"
Tile::Tile( int x, int y, int tileType )
{
    //Get the offsets
    this->mBox.x = x;
    this->mBox.y = y;

    //Set the collision box
    this->mBox.w = TILE_WIDTH;
    this->mBox.h = TILE_HEIGHT;

    //Get the tile type
    mType = tileType;
}

void Tile::render( SDL_Rect& camera, LTexture& floorTexture, LTexture& wallTexture, SDL_Renderer*& aRenderer, LTexture& lavaTexture, LTexture& iceTexture, LTexture& cakeTexture )
{
    //Hien thi tile va cham camera
    if( checkCollision( camera, mBox ) )
    {
        if(this->mType == TILE_WALL )
        {
            wallTexture.render( mBox.x - camera.x, mBox.y - camera.y, NULL, 0, NULL, SDL_FLIP_NONE, aRenderer );
        }
        else if(this->mType == TILE_FLOOR)
        {
            floorTexture.render( mBox.x - camera.x, mBox.y - camera.y, NULL, 0, NULL, SDL_FLIP_NONE, aRenderer );
        }
        else if(this->mType == TILE_LAVA)
        {
            lavaTexture.render( mBox.x - camera.x, mBox.y - camera.y, NULL, 0, NULL, SDL_FLIP_NONE, aRenderer );
        }
        else if(this->mType == TILE_ICE)
        {
            iceTexture.render( mBox.x - camera.x, mBox.y - camera.y, NULL, 0, NULL, SDL_FLIP_NONE, aRenderer );
        }
        else if(this->mType == TILE_CAKE)
        {
            cakeTexture.render( mBox.x - camera.x, mBox.y - camera.y, NULL, 0, NULL, SDL_FLIP_NONE, aRenderer );
        }

    }
}

int Tile::getType()
{
    return mType;
}

SDL_Rect Tile::getBox()
{
    return mBox;
}


bool setTiles( Tile* tiles[] )
{
	//Success flag
	bool tilesLoaded = true;

    //The tile offsets
    int x = 0, y = 0;

    //Open the map
    ifstream map( "firstmap.txt" );

    //If the map couldn't be loaded
    if( map.fail() )
    {
		printf( "Unable to load map file!\n" );
		tilesLoaded = false;
    }
	else
	{
		//Initialize the tiles
		for( int i = 0; i < TOTAL_TILES; i++ )
		{
			//Determines what kind of tile will be made
			int tileType = -1;

			//Read tile from map file
			map >> tileType;

			//If the was a problem in reading the map
			if( map.fail() )
			{
				//Stop loading map
				printf( "Error loading map: Unexpected end of file!\n" );
				tilesLoaded = false;
				break;
			}

			//If the number is a valid tile number
			if( ( tileType >= 0 ) && ( tileType < TOTAL_TILE_SPRITES ) )
			{
				tiles[ i ] = new Tile( x, y, tileType );
			}
			//If we don't recognize the tile type
			else
			{
				//Stop loading map
				printf( "Error loading map: Invalid tile type at %d!\n", i );
                cout << "1" << endl;
				tilesLoaded = false;
				break;
			}

			//Move to next tile spot
			x += TILE_WIDTH;

			//If we've gone too far
			if( x >= LEVEL_WIDTH )
			{
				//Move back
				x = 0;

				//Move to the next row
				y += TILE_HEIGHT;
			}
		}

	}

    //Close the file
    map.close();

    //If the map was loaded fine
    return tilesLoaded;
}


bool touchesWall( SDL_Rect box, Tile* tiles[] )
{
    //Go through the tiles
    for( int i = 0; i < TOTAL_TILES; ++i )
    {
        //If the tile is a wall type tile
        if( ( tiles[ i ]->getType() == TILE_WALL ))
        {
            //If the collision box touches the wall tile
            if( checkCollision( box, tiles[ i ]->getBox() ) )
            {
                //cout << "O day : " << i << endl;
                return true;
            }
        }
    }

    //If no wall tiles were touched
    return false;
}

bool collisionLavaDie(SDL_Rect box, Tile* tiles[])
{
    for( int i = 0; i < TOTAL_TILES; ++i )
    {
        //If the tile is a wall type tile
        if( ( tiles[ i ]->getType() == TILE_LAVA ))
        {
            //If the collision box touches the wall tile
            if( checkCollision( box, tiles[ i ]->getBox() ) )
            {
                //cout << "LAVA" << i << endl;
                return true;
            }
        }
    }

    //If no wall tiles were touched
    return false;
}

bool collisionIceSlow(SDL_Rect box, Tile* tiles[])
{
    for( int i = 0; i < TOTAL_TILES; ++i )
    {
        //If the tile is a wall type tile
        if( ( tiles[ i ]->getType() == TILE_ICE ))
        {
            //If the collision box touches the wall tile
            if( checkCollision( box, tiles[ i ]->getBox() ) )
            {
                //cout << "ICE" << i << endl;
                return true;
            }
        }
    }

    //If no wall tiles were touched
    return false;
}

bool collisionCakeFast(SDL_Rect box, Tile* tiles[])
{
    for( int i = 0; i < TOTAL_TILES; ++i )
    {
        //If the tile is a wall type tile
        if( ( tiles[ i ]->getType() == TILE_CAKE ))
        {
            //If the collision box touches the wall tile
            if( checkCollision( box, tiles[ i ]->getBox() ) )
            {
                //cout << "CAKE" << i << endl;
                return true;
            }
        }
    }

    //If no wall tiles were touched
    return false;
}
