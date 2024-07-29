#pragma once
#ifndef SUNFLOWER_H
#define SUNFLOWER_H

#include "Plant.h"
#include "SunFactory.h"

class Plant; // Forward declaration
class Sun;

class Sunflower : public Plant {

    sf::Texture sunTexture;
    sf::Sprite sunSprite;
    sf::Clock sunClock;
    
    Sun* sun;

public:
    Sunflower(int x = 0, int y = 0);

    virtual void attack(ZombieFactory& zombies) override;
    virtual ~Sunflower();
    void produceSun(SunFactory& sunFactory);
};



#endif // !SUNFLOWER_H