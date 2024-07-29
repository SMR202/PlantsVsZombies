#pragma once
#ifndef DOLPHINZOMBIE_H
#define DOLPHINZOMBIE_H
#include "Zombie.h"

class Zombie;

class DolphinZombie : public Zombie {
public:
    DolphinZombie(int x = 720, int y = 230);
    //virtual void move();
    virtual ~DolphinZombie();
};

#endif // !DOLPHINZOMBIE_H
