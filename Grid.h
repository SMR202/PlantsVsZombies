#pragma once
#ifndef GRID_H
#define GRID_H

#include "Tile.h"
#include "LastLineDefence.h"
#include "coordinates.h"
#include "Constants.h"

class Grid {
protected:
    Tile tiles[ROWS][COLS];
    bool isPlantable[ROWS][COLS];
    LastLineDefence* lastLineDefence;

public:
    Grid();

    bool getIsPlantable(int x, int y);
    void setIsPlantable(int x, int y, bool isPlantable);
    coordinates& checkBounds(int x, int y);
    Tile& getTile(int x, int y);
    Tile& getTile(coordinates& point);
};

#endif // !GRID_H