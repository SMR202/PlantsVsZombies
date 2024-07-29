#include "Zombie.h"
#include <iostream>
#include <fstream>
using namespace std;

Zombie::Zombie(int health, int damage, float speed, std::string name, int x, int y, int incrementX, int limitX) : health(health), damage(damage), speed(speed), name(name), moveClock(), animationClock(), position({ x, y }), incrementX(incrementX), limitX(limitX) {}

Zombie::~Zombie() {}

void Zombie::attack(PlantFactory& plants, Grid& grid) {
    for (int i = 0; i < MAX_PLANTS; i++) {
        if (plants.getPlant(i) != nullptr) {
            // Define a smaller collision box for the zombie
            float zombieCollisionWidth = getRect().width * 0.3f;
            float zombieCollisionHeight = getRect().height * 0.1f;

            // Adjust the position and dimensions of the collision box
            float zombieCollisionX = position.x + getRect().width * 0.05f;
            float zombieCollisionY = position.y + getRect().height * 0.1f;

            if (plants.getPlant(i)->getPosition().x >= zombieCollisionX &&
                plants.getPlant(i)->getPosition().x <= zombieCollisionX + zombieCollisionWidth &&
                plants.getPlant(i)->getPosition().y-150 + plants.getPlant(i)->getRect().height >= zombieCollisionY &&
                plants.getPlant(i)->getPosition().y-50 <= zombieCollisionY-25 + zombieCollisionHeight) {
                // Collision detected, apply damage to the plant
                shouldStop = true;
                underattackPlant = i;
                eat(plants, grid, i);
                continue;
            }
        }
        else if (!shouldStop || plants.getPlant(underattackPlant) == nullptr) {
            move();
        }
    }
}

void Zombie::eat(class PlantFactory& plants, Grid& grid, int i) {
    if (attackClock.getElapsedTime().asSeconds() >= 1) {
        plants.getPlant(i)->setHealth(plants.getPlant(i)->getHealth() - damage);
        if (plants.getPlant(i)->getHealth() <= 0) {
            // Plant destroyed, remove it from the plant factory
            plants.killPlant(i, grid);
            cout << "killed";
            shouldStop = false;
        }
        attackClock.restart();
    }
}
int Zombie::getHealth() {
    return health;
}

void Zombie::setHealth(int health) {
    this->health = health;
}

int Zombie::getDamage() {
    return damage;
}

void Zombie::setDamage(int damage) {
    this->damage = damage;
}

double Zombie::getSpeed() {
    return speed;
}

void Zombie::setSpeed(double speed) {
    this->speed = speed;
}

coordinates& Zombie::getPosition() {
    return position;
}

void Zombie::setLimitX(int limitX) {
	this->limitX = limitX;
}

void Zombie::setIncrementX(int incrementX) {
	this->incrementX = incrementX;
}

int Zombie::getLimitX() {
	return limitX;
}

int Zombie::getIncrementX() {
	return incrementX;
}

void Zombie::setPosition(int x, int y) {
    position.x = x;
    position.y = y;
    zombieSprite.setPosition(position.x, position.y);
}

std::string Zombie::getName() {
    return name;
}

void Zombie::setName(std::string name) {
    this->name = name;
}

void Zombie::move() {
    if (moveClock.getElapsedTime().asSeconds() >= 0.05) {
        position.x = zombieSprite.getPosition().x - speed;
        //position.y = zombieSprite.getPosition().y;
        zombieSprite.setPosition(position.x, position.y);
        moveClock.restart();
        if (position.x <= 140 && position.y < 429) {
            zombieSprite.setPosition(140, 1800);
            position.y = 1800;
        }

    }

}

void Zombie::stop() {
    if (shouldStop && stopClock.getElapsedTime().asSeconds() >= 1) {
        shouldStop = false;
        stopClock.restart();
    }
}

void Zombie::startStop() {
    shouldStop = true;
}

sf::Sprite& Zombie::getSprite() {
    return zombieSprite;
}

sf::IntRect& Zombie::getRect() {
    return zombieRect;
}

void Zombie::setSprite(sf::Sprite& zombiesprite) {
    zombieSprite = zombiesprite;
}

sf::Clock& Zombie::getAnimationClock() {
    return animationClock;
}