#pragma once
#ifndef LEVELS_H
#define LEVELS_H

#include "PlantFactory.h"
#include "ZombieFactory.h"
#include "SunFactory.h"
#include "Waves.h"
#include "Shovel.h"
#include "Times.h"
#include "Lawnmower.h"
#include "SeedSprites.h"


class Levels {
protected:
    PlantFactory plantFactory;
    ZombieFactory zombieFactory;
    SunFactory sunFactory;
    Times* time;
    int num;
    string name;
    string description;
    string objectives;
    string challenges;
    string rewards;
    string zombies[MAX_ZOMBIES];
    Waves wave;
    Shovel shovel;
    Lawnmower lawnmowers[5];
    Seeds seeds;
    int& score;

public:
    Levels(int num, int& score);
    virtual ~Levels();

    virtual void loadLevelInfo() = 0;

    PlantFactory& getPlantFactory();
    ZombieFactory& getZombieFactory();
    SunFactory& getSunFactory();
    Lawnmower& getLawnmower(int index);
    Seeds& getSeeds();
    Shovel& getShovel();
    Times*& getTime();
};

#endif // !LEVELS_H