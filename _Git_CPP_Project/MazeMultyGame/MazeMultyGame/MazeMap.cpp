#include "MazeMap.h"

char GetRoadOrItem();

void CreatMazeMap(char _arrMap[MAP_HEIGHT][MAP_WIDTH])
{
    //격자로 벽 생성
    for (int y = 0; y < MAP_HEIGHT; y++)
    {
        for (int x = 0; x < MAP_WIDTH; x++)
        {
            if (x % 2 == 0 && y % 2 == 0)
                _arrMap[y][x] = (char)OBJ_TYPE::ROAD;
            else
                _arrMap[y][x] = (char)OBJ_TYPE::WALL;
        }
    }

    //격자벽에 구멍뚫기
    srand((unsigned int)time(NULL));
    for (int y = 0; y < MAP_HEIGHT; y += 2)
    {
        bool flag = false;
        for (int x = 0; x < MAP_WIDTH; x += 2)
        {
            int random = rand() % 2;
            if (random == 0)
            {
                flag = true;
                _arrMap[y + 1][x] = GetRoadOrItem();
            }
            else if (random == 1)
                _arrMap[y][x + 1] = GetRoadOrItem();

            random = rand() % 5;
            if (flag && random == 0)
            {
                _arrMap[y][x + 1] = GetRoadOrItem();
                flag = false;
            }
        }
    }

    //마지막줄 비우기
    for (int y = 0; y < MAP_HEIGHT; y++)
    {
        _arrMap[y][MAP_WIDTH - 1] = (char)OBJ_TYPE::ROAD;
    }
    for (int x = 0; x < MAP_WIDTH; x++)
    {
        _arrMap[MAP_HEIGHT - 1][x] = (char)OBJ_TYPE::ROAD;
    }
}

char GetRoadOrItem()
{
    char resualt = (char)OBJ_TYPE::ROAD;
    int random = rand() % 50 + 1;
    if (random <= 7)
    {
        resualt += random;
    }

    return resualt;
}