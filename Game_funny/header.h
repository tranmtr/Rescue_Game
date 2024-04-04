#pragma once


//Using SDL, SDL_image, standard IO, and strings
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

//The dimensions of the level
const int LEVEL_WIDTH = 34*80;
const int LEVEL_HEIGHT = 33*80;

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

//Walking animation
const int RUN_ANIMATION_FRAMES = 8;
const int IDLE_ANIMATION_FRAMES = 5;

//Tile constants
const int TILE_WIDTH = 80;
const int TILE_HEIGHT = 80;
const int TOTAL_TILES = 34*33;
const int TOTAL_TILE_SPRITES = 5;

//The different tile sprites
const int TILE_FLOOR = 0;
const int TILE_LAVA = 1;
const int TILE_ICE = 2;
const int TILE_CAKE = 3;
const int TILE_WALL = 4;

