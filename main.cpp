//
//  File.cpp
//  MapAbstraction
//
//  Created by Nathan Sturtevant on 7/11/13.
//  Modified by Steve Rabin 12/15/14
//
//
#include <vector>
#include <cstdio>
#include <cstdint>
#include <numeric>
#include <algorithm>
#include "Timer.h"
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <unistd.h>
#include "Wrapper.h"
#include "Log.h"

int Random(int a, int b)
{
    if (a == b)
    {
        return a;
    }
    else if (a > b)
    {
        return b;
    }
    else
    {
        if (a < 0)
        {
            return a + Random(0, b-a);
        }
        else
        {
            return a + (int) ((b-a+1) * ((float)rand() / (RAND_MAX + 1.0)));
        }
    }

    return a;
}


int main(int argc, char *argv[]) {
    int64_t allTestsTotalTime = 0;
    Timer *timer = new Timer();
    std::vector<bool> mapData;
    int mapSize = 1000;

    //Construct map.
    for (int i = 0; i < mapSize; i++) {
        for (int j = 0; j < mapSize; j++) {
            mapData.push_back(true);
        }
    }

    for (int i = 0; i < 10000; i++)
    {
        int x = Random(0, 999);
        int y = Random(0, 999);
        // printf("x:%3d y:%3d\n", x, y);
        mapData[x + y * mapSize] = false;
    }

    JPSPWrapper *jpgb = new JPSPWrapper(mapData, mapSize, mapSize);
    jpgb->Preprocess();

    timer->StartTimer();
    xyLoc *start = new xyLoc(10, 10), *end = new xyLoc(967, 635);
    std::vector<xyLoc> *path = jpgb->GetPath((xyLoc &) *start, (xyLoc &) *end);

    allTestsTotalTime += timer->EndTimer();

#if 1
    if (path->size() > 0) {
        printf("Path found: ");
        for (unsigned int t = 0; t < path->size(); t++) {
            if (t != path->size() - 1) {
                if (t % 10 == 0 && t != 0) {
                    printf("\n");
                } else {
                    printf("(%d, %d)->", (*path)[t].x, (*path)[t].y);
                }
            } else {
                printf("(%d, %d)\n", (*path)[t].x, (*path)[t].y);
            }
        }
    } else {
        printf("Path not found.\n");
    }
    (*path).clear();

    printf("All tests total time: %lld", allTestsTotalTime);
#endif
    return 0;
}
