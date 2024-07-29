#pragma once
#ifndef SHOVEL_H
#define SHOVEL_H

#include "Grid.h"

class Shovel {
private:
    int positionX;
    int positionY;
    bool clicked;
public:
    Shovel();
    void setclicked(bool clicked);
    bool getclicked();
    void use(Grid& grid, coordinates& point, PlantFactory& plants);
    ~Shovel();
};

#endif // !SHOVEL_H