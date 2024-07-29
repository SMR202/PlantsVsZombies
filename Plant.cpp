#include "Plant.h"

Plant::Plant(int health, int damage, int cost, std::string name, int x, int y, int incrementX, int limitX)
    : health(health), damage(damage), cost(cost), name(name), position({ x, y }), incrementX(incrementX), limitX(limitX), clock(), isReady(false), isPressed(false) {}

Plant::~Plant() {}

int Plant::getHealth() {
    return health;
}

void Plant::setHealth(int health) {
    this->health = health;
}

int Plant::getDamage() {
    return damage;
}

int Plant::getCost() {
    return cost;
}

coordinates Plant::getPosition() {
    return position;
}

void Plant::setPosition(int x, int y) {
    position.x = x;
    position.y = y;
}

std::string Plant::getName() {
    return name;
}

void Plant::setName(std::string name) {
    this->name = name;
}

sf::Sprite& Plant::getSprite() {
    return plantSprite;
}

sf::IntRect& Plant::getRect() {
    return plantRect;
}

void Plant::setSprite(sf::Sprite& plantsprite) {
    plantSprite = plantsprite;
}

void Plant::drawPlant(sf::RenderWindow& window) {
    window.draw(plantSprite);
}

void Plant::restartClock() {
    clock.restart();
}

float Plant::getElapsedTime() {
    sf::Time elapsed = clock.getElapsedTime();
    if (elapsed.asSeconds() >= 5) {
        isReady = true;
    }
    return elapsed.asSeconds();
}

bool Plant::getIsReady() {
    return isReady;
}

void Plant::setIsReady(bool ready) {
    isReady = ready;
}

bool Plant::getPressed() {
    isPressed = true;
    return isPressed;
}

void Plant::setPressed(bool pressed) {
    isPressed = pressed;
}

sf::Clock& Plant::getClock() {
    return clock;
}

int Plant::getIncrementX() {
    return incrementX;
}

int Plant::getlimitX() {
    return limitX;
}

void Plant::setIncrementX(int incrementX) {
    this->incrementX = incrementX;
}

void Plant::setLimitX(int limitX) {
    this->limitX = limitX;
}
