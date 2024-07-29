#pragma once
#ifndef FLYINGZOMBIE_H
#define FLYINGZOMBIE_H
#include "Zombie.h"

class Zombie;

class FlyingZombie : public Zombie {
public:
    FlyingZombie(int x = 720, int y = 230);
    //virtual void move();
    virtual void attack();
    virtual ~FlyingZombie();
};

#endif // !FLYINGZOMBIE_H