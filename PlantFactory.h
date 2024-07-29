#pragma once
#ifndef PLANTFACTORY_H
#define PLANTFACTORY_H

#include "Plant.h"
#include "Constants.h"
using namespace std;
class Plant;
class Sunflower;
class Peashooter;
class Walnut;
class CherryBomb;
class SnowPeashooter;
class Repeatershooter;
class Grid;

class PlantFactory {
protected:
    Plant* plants[MAX_PLANTS];
    int index;
    int numPlants;
public:
    PlantFactory(int lvl = 1);

    Plant*& createPlant(string name, int x, int y);
    Plant*& getPlant(int i);
    void killPlant(int i, Grid& grid);
    ~PlantFactory();
};

#endif // !PLANTFACTORY_H