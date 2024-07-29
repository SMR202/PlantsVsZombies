#pragma once
#ifndef SHOOTER_H
#define SHOOTER_H
#include "Plant.h"

class Plant; // Forward declaration
class ZombieFactory; // Forward declaration

class Shooter : public Plant {
protected:
    coordinates bulletPosition[2];
    sf::Texture bulletTexture;
    sf::IntRect bulletRect;
    sf::Sprite bulletSprite[2];
    sf::Clock bulletClock[2], bulletDamage[2];

    int bulletNum;

public:
    Shooter(int health = 100, int damage = 5, int cost = 100, std::string name = "shooter", int x = 0, int y = 0, int incrementX = 0, int limitX = 0, int bulletNum = 1);

    virtual void attack(ZombieFactory& zombies) = 0;
    void setSprite(sf::Sprite& bulletsprite);
    void setBulletPosition(int x, int y);
    sf::Sprite& getSprite();
    sf::IntRect& getRect();
    virtual void drawPlant(sf::RenderWindow& window);
    virtual ~Shooter();
};

#endif // SHOOTER_H