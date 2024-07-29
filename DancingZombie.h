#pragma once
#ifndef DANCINGZOMBIE_H
#define DANCINGZOMBIE_H
#include "Zombie.h"

class Zombie;

class DancingZombie : public Zombie {
protected:
	sf::Clock verticalClock;
public:
	DancingZombie(int x = 720, int y = 230);
	virtual void move();
	virtual ~DancingZombie();
};

#endif // !DANCINGZOMBIE_H
