#include "MazeMap.h"


void CreatMazeMap(char _mapArr[MAP_HEIGHT][MAP_WIDTH])
{
    for (int y = 0; y < MAP_HEIGHT; y++)
    {
        for (int x = 0; x < MAP_WIDTH; x++)
        {
            if (x % 2 == 1 || y % 2 == 1)
                _mapArr[y][x] = (char)Core::OBJ_TYPE::ROAD;
            else
                _mapArr[y][x] = (char)Core::OBJ_TYPE::WALL;
        }
    }

    srand((unsigned int)time(NULL));
    for (int y = 0; y < MAP_HEIGHT; y += 2)
    {
        int x = 0;
        while (true)
        {
            if (x >= MAP_WIDTH) break;

            int random = rand() % 3;
            if (random == 0)
                _mapArr[y + 1][x] = (char)Core::OBJ_TYPE::ROAD;
            else if (random == 1)
                _mapArr[y][x + 1] = (char)Core::OBJ_TYPE::ROAD;
            else if (random == 2)
                x += 2;
            x += 2;
        }
    }
}