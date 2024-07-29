#pragma once
#ifndef FOOTBALLZOMBIE_H
#define FOOTBALLZOMBIE_H
#include "Zombie.h"

class FootballZombie : public Zombie {
	sf::Clock verticalClock;
public:
	FootballZombie(int x = 720, int y = 230);
	virtual void move();
	virtual ~FootballZombie();
};

#endif // !FOOTBALLZOMBIE_H