#include "ZombieFactory.h"
#include "SimpleZombie.h"
#include "FootballZombie.h"
#include "DancingZombie.h"
#include "FlyingZombie.h"
#include "DolphinZombie.h"
#include <cstdlib>
#include <iostream>

ZombieFactory::ZombieFactory(int& score) : zombiesCount(0), score(score) {
    for (int i = 0; i < MAX_ZOMBIES; ++i) {
        this->zombies[i] = nullptr;
    }
}

void ZombieFactory::createZombie(std::string name, int x, int y) {
    int randRow[5] = { 20, 85, 160, 225, 295 }; // [0, 1, 2, 3, 4]
    int randIndex = rand() % 5;
    int randy = randRow[randIndex];
    int randomZombie = rand() % 5;
    if (zombies[zombiesCount] == nullptr && zombiesCount<=MAX_ZOMBIES) {
        if (creationClock.getElapsedTime().asSeconds() > 4) {
            if (randomZombie == 0)
                zombies[zombiesCount] = new SimpleZombie();
            else if (randomZombie == 1)
                zombies[zombiesCount] = new FootballZombie();
            else if (randomZombie == 2 && randIndex != 0 && randIndex != 4 && zombiesCount < MAX_ZOMBIES - 5) {
                zombies[zombiesCount] = new DancingZombie();
                zombies[++zombiesCount] = new SimpleZombie();
                zombies[zombiesCount]->setPosition(x - 57, randy);
                zombies[++zombiesCount] = new SimpleZombie();
                zombies[zombiesCount]->setPosition(x + 57, randy);
                zombies[++zombiesCount] = new SimpleZombie();
                zombies[zombiesCount]->setPosition(x, randRow[randIndex + 1]);
                zombies[++zombiesCount] = new SimpleZombie();
                zombies[zombiesCount]->setPosition(x, randRow[randIndex - 1]);
            }

            else if (randomZombie == 3)
                zombies[zombiesCount] = new SimpleZombie();
            if (randomZombie == 4) {
                zombies[zombiesCount] = new FlyingZombie();
            }
            if (zombies[zombiesCount] != nullptr) {
                if (randomZombie == 2) {
                    zombies[zombiesCount - 4]->setPosition(x, randy);
                }
				else
                    zombies[zombiesCount]->setPosition(x, randy);
            }
            //zombies[zombiesCount]->setName(name);
            zombiesCount++;
            creationClock.restart();
        }
    }
    else {
        zombiesCount++;
        if (zombiesCount >= MAX_ZOMBIES) {
			zombiesCount = 0;
		}
    }
    
}

Zombie*& ZombieFactory::getZombie(int i) {
    return zombies[i];
}

void ZombieFactory::killZombie(int i) {
    delete zombies[i];
    zombies[i] = nullptr;
    score += 50;
    cout<< "Score: " << score << endl;
}

sf::Clock& ZombieFactory::getClock() {
    return creationClock;
}

ZombieFactory::~ZombieFactory() {
    for (int i = 0; i < MAX_ZOMBIES; i++) {
        if (zombies[i] != nullptr)
            delete this->zombies[i];
    }
}
