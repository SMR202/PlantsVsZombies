#pragma once
#ifndef ZOMBIE_H
#define ZOMBIE_H
#include <SFML/Graphics.hpp>
#include "PlantFactory.h"
#include "coordinates.h"

class Grid;

class Zombie {
protected:
    int health, damage, underattackPlant, incrementX, limitX;
    double speed;
    std::string name;
    sf::Clock stopClock;
    sf::Clock moveClock;
    sf::Clock animationClock;
    sf::Clock attackClock;
    coordinates position;
    sf::Texture zombieTexture;
    sf::IntRect zombieRect;
    sf::Sprite zombieSprite;
    bool shouldStop = false;  // Add this line
    bool reachedEnd = false;  

public:
    Zombie(int health = 100, int damage = 5, float speed = 1.0, std::string name = "plant", int x = 0, int y = 0, int incrementX = 0, int limitX = 0);
    virtual ~Zombie();

    virtual void attack(class PlantFactory& plants, Grid& grid); // Fixed the syntax error

    int getHealth();
    void setHealth(int health);
    int getDamage();
    void setDamage(int damage);
    double getSpeed();
    void setSpeed(double speed);
    coordinates& getPosition();
    void setPosition(int x, int y);
    std::string getName();
    void setName(std::string name);
    virtual void move();
    sf::Sprite& getSprite();
    sf::IntRect& getRect();
    void setLimitX(int limitX);
    void setIncrementX(int incrementX);
    int getLimitX();
    int getIncrementX();
    void stop();
    void startStop();
    void setSprite(sf::Sprite& zombiesprite);
    sf::Clock& getAnimationClock();
    void eat(class PlantFactory& plants, Grid& grid, int i);
};

#endif // ZOMBIE_H