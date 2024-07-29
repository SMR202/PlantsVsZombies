#pragma once
#ifndef CHERRYBOMB_H
#define CHERRYBOMB_H

#include "Plant.h"
#include "Grid.h"
#include "ZombieFactory.h"

class CherryBomb : public Plant {
private:
    bool alive;
    sf::Clock explosionClock;
public:
    CherryBomb(int x = 0, int y = 0);

    virtual void attack(ZombieFactory& zombies);
    sf::Clock& getExplosionClock();
    virtual ~CherryBomb();
};

#endif // !CHERRYBOMB_H