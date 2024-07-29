#pragma once
#ifndef TILE_H
#define TILE_H
#include "Plant.h"
#include "Zombie.h"
#include "Constants.h"
#include "coordinates.h"
class Tile {
protected:
    Plant* plant;
    Zombie* zombies[MAX_ZOMBIES_PER_TILE];
    coordinates topLeft;
    coordinates bottomRight;
    coordinates topRight;
    coordinates bottomLeft;
    coordinates center;

public:

    coordinates& getTopLeft();
    coordinates& getBottomRight();
    coordinates& getTopRight();
    coordinates& getBottomLeft();
    coordinates& getCenter();
    void setTopLeft(coordinates& topLeft);
    void setBottomRight(coordinates& bottomRight);
    void setTopRight(coordinates& topRight);
    void setBottomLeft(coordinates& bottomLeft);
    void setCenter(coordinates& center);
    Tile(Plant* plant = nullptr, Zombie* zombies[MAX_ZOMBIES_PER_TILE] = { nullptr });
    void addPlant(Plant* plant);
    void removePlant();
    Plant*& getPlant();
};

#endif // !TILE_H