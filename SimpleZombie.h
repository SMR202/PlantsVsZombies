#pragma once
#ifndef SIMPLEZOMBIE_H
#define SIMPLEZOMBIE_H
#include "Zombie.h"

class Zombie;

class SimpleZombie : public Zombie {
public:
    SimpleZombie(int x = 720, int y = 230);
    virtual ~SimpleZombie();
};

#endif // !SIMPLEZOMBIE_H