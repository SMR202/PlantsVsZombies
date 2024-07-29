#pragma once
#ifndef SNOWPEASHOOTER_H
#define SNOWPEASHOOTER_H
#include "Shooter.h"

class SnowPeashooter : public Shooter {
    Zombie* slowedZombie;
    sf::Clock slowClock;
    sf::Color defaultColor;
public:
    SnowPeashooter(int x = 0, int y = 0);

    virtual void attack(ZombieFactory& zombies) override;
    virtual ~SnowPeashooter();
};

#endif // !SNOWPEASHOOTER_H