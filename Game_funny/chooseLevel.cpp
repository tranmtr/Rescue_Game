#pragma once

#include "chooseLevel.h"

void loadLevel(const int& choose, string& pathMaze, int& LEVEL_WIDTH, int& LEVEL_HEIGHT, int& TOTAL_TILES, int& TOTAL_DRAGON)
{
    if(choose == 1)
    {
        pathMaze = "map_1.txt";
        LEVEL_WIDTH = 17*80;
        LEVEL_HEIGHT = 16*80;
        TOTAL_TILES = 17*16;
        TOTAL_DRAGON = 7;
    }
    else if(choose == 2)
    {
        pathMaze = "map_2.txt";
        LEVEL_WIDTH = 22*80;
        LEVEL_HEIGHT = 33*80;
        TOTAL_TILES = 22*33;
        TOTAL_DRAGON = 10;
    }
    else if(choose == 3)
    {
        pathMaze = "map_3.txt";
        LEVEL_WIDTH = 34*80;
        LEVEL_HEIGHT = 33*80;
        TOTAL_TILES = 34*33;
        TOTAL_DRAGON = 10;
    }
}
