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

//Tile constants
const int TILE_WIDTH = 80;
const int TILE_HEIGHT = 80;
const int TOTAL_TILES = 34*33;
const int TOTAL_TILE_SPRITES = 5;
const int TILE_FLOOR = 0;
const int TILE_LAVA = 1;
const int TILE_ICE = 2;
const int TILE_CAKE = 3;
const int TILE_WALL = 4;

//Frame Animation
const int ANIMATION_FRAMES_DIE = 6;
const int ANIMATION_FRAMES_IDLE = 5;
const int ANIMATION_FRAMES_RUN = 8;
const int ANIMATION_FRAMES_ATTACK = 3;


// ANIMATION STATUS
const int ANIMATION_STATUS_DIE = 0;
const int ANIMATION_STATUS_IDLE = 1;
const int ANIMATION_STATUS_RUN = 2;
const int ANIMATION_STATUS_ATTACK = 3;
const int ANIMATION_STATUS_TOTAL = 4;

//Dragon
const int ANIMATION_FRAMES_DRAGON = 15;
const int TOTAL_DRAGON = 10;


//Dramage
const int DAMAGE_ICE = 25;
const int DAMAGE_FIRE = 25;

