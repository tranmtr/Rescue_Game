#pragma once

#include "chooseLevel.h"

void loadLevel(const int& choose, string& pathMaze, int& LEVEL_WIDTH, int& LEVEL_HEIGHT, int& TOTAL_TILES, int& TOTAL_DRAGON)
{
    if(choose == 1)
    {
        pathMaze = "maze/map_1.txt";
        LEVEL_WIDTH = 14*80;
        LEVEL_HEIGHT = 7*80;
        TOTAL_TILES = 14*7;
        TOTAL_DRAGON = 1;
    }
    else if(choose == 2)
    {
        pathMaze = "maze/map_2.txt";
        LEVEL_WIDTH = 20*80;
        LEVEL_HEIGHT = 18*80;
        TOTAL_TILES = 20*18;
        TOTAL_DRAGON = 2;
    }
    else if(choose == 3)
    {
        pathMaze = "maze/map_3.txt";
        LEVEL_WIDTH = 17*80;
        LEVEL_HEIGHT = 16*80;
        TOTAL_TILES = 17*16;
        TOTAL_DRAGON = 7;
    }
    else if(choose == 4)
    {
        pathMaze = "maze/map_4.txt";
        LEVEL_WIDTH = 19*80;
        LEVEL_HEIGHT = 19*80;
        TOTAL_TILES = 19*19;
        TOTAL_DRAGON = 4;
    }
    else if(choose == 5)
    {
        pathMaze = "maze/map_5.txt";
        LEVEL_WIDTH = 22*80;
        LEVEL_HEIGHT = 33*80;
        TOTAL_TILES = 22*33;
        TOTAL_DRAGON = 10;
    }
    else if(choose == 6)
    {
        pathMaze = "maze/map_6.txt";
        LEVEL_WIDTH = 39*80;
        LEVEL_HEIGHT = 33*80;
        TOTAL_TILES = 39*33;
        TOTAL_DRAGON = 8;
    }
    else if(choose == 7)
    {
        pathMaze = "maze/map_7.txt";
        LEVEL_WIDTH = 34*80;
        LEVEL_HEIGHT = 33*80;
        TOTAL_TILES = 34*33;
        TOTAL_DRAGON = 10;
    }
    else if(choose == 8)
    {
        pathMaze = "maze/map_8.txt";
        LEVEL_WIDTH = 46*80;
        LEVEL_HEIGHT = 46*80;
        TOTAL_TILES = 46*46;
        TOTAL_DRAGON = 10;
    }
}
