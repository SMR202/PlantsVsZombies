#pragma once
#ifndef PLANT_H
#define PLANT_H
#include <SFML/Graphics.hpp>
#include "ZombieFactory.h"
#include "coordinates.h"
#include "PlantFactory.h"

class Plant {
protected:
    int health, damage, cost, incrementX, limitX;
    std::string name;
    coordinates position;
    sf::Clock clock;
    bool isReady;
    bool isPressed;
    sf::Texture plantTexture;
    sf::IntRect plantRect;
    sf::Sprite plantSprite;

public:
    Plant(int health = 100, int damage = 5, int cost = 100, std::string name = "plant", int x = 0, int y = 0, int incrementX = 0, int limitX = 0);
    virtual ~Plant();

    int getHealth();
    void setHealth(int health);
    int getDamage();
    int getCost();
    coordinates getPosition();
    void setPosition(int x, int y);
    std::string getName();
    void setName(std::string name);
    sf::Sprite& getSprite();
    sf::IntRect& getRect();
    void setSprite(sf::Sprite& plantsprite);
    virtual void drawPlant(sf::RenderWindow& window);
    void restartClock();
    float getElapsedTime();
    bool getIsReady();
    void setIsReady(bool ready);
    bool getPressed();
    void setPressed(bool pressed);
    sf::Clock& getClock();
    int getIncrementX();
    int getlimitX();
    void setIncrementX(int incrementX);
    void setLimitX(int limitX);
    virtual void attack(class ZombieFactory& zombies) = 0;
};

#endif // PLANT_H