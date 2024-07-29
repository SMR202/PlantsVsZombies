#pragma once
#ifndef ZOMBIEFACTORY_H
#define ZOMBIEFACTORY_H
#include "Zombie.h"
#include <SFML/System/Clock.hpp>
#include "Constants.h"

class Zombie;

class ZombieFactory {
protected:
    Zombie* zombies[MAX_ZOMBIES];
    sf::Clock creationClock;
    int zombiesCount;
    int &score;

public:
    ZombieFactory(int& score);

    void createZombie(std::string name = "", int x = 720, int y = 295);
    Zombie*& getZombie(int i);
    void killZombie(int i);
    sf::Clock& getClock();
    ~ZombieFactory();
};

#endif // !ZOMBIEFACTORY_H