#pragma once

#include "chooseLevel.h"

void loadLevel(const int& choose, string& pathMaze, int& LEVEL_WIDTH, int& LEVEL_HEIGHT, int& TOTAL_TILES)
{
    if(choose == 1)
    {
        pathMaze = "firstmap.txt";
        LEVEL_WIDTH = 34*80;
        LEVEL_HEIGHT = 33*80;
        TOTAL_TILES = 34*33;
    }
    else if(choose == 2)
    {
        pathMaze = "secondmap.txt";
        LEVEL_WIDTH = 22*80;
        LEVEL_HEIGHT = 33*80;
        TOTAL_TILES = 22*33;
    }
}
