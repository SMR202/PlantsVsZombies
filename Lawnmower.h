#pragma once
#ifndef LAWNMOWER_H
#define LAWNMOWER_H
#include <SFML/Graphics.hpp>
#include "coordinates.h"
#include "ZombieFactory.h"

class Lawnmower {
protected:
	sf::Texture lawnmowerTexture;
	sf::Sprite lawnmowerSprite;
	sf::Clock lawnmowerClock;
	coordinates position;
	int width, height;
	int damage;
	int cost;
	bool active;
public:
	Lawnmower(int x, int y, int width, int height, int damage, int cost, bool active);
	~Lawnmower();
	sf::Sprite getSprite();
	coordinates getPosition();
	int getSpeed();
	int getDirection();
	void drawLawnmower(sf::RenderWindow& window);
	int getDamage();
	int getWidth();
	int getHeight();
	int getCost();
	bool isActive();
	void setWidth(int width);
	void setHeight(int height);
	void setSpeed(int speed);
	void setDirection(int direction);
	void setDamage(int damage);
	void setCost(int cost);
	void setActive(bool active);
	void moveLawnmower();
	void checkZombieCollision(ZombieFactory& zombies);
};

#endif // !LAWNMOWER_H