#include "Lawnmower.h"
#include <iostream>
using namespace std;

Lawnmower::Lawnmower(int x, int y, int width, int height, int damage, int cost, bool active)
	: width(width), height(height), damage(damage), cost(cost), active(active) {
	sf::Texture NewTexture;
	NewTexture.loadFromFile("Images/Lawnmower.png");
	lawnmowerTexture = NewTexture;
	sf::Sprite NewSprite(lawnmowerTexture);
	NewSprite.setScale(0.75f, 0.75f);
	lawnmowerSprite = NewSprite;
	position.x = x;
	position.y = y;

}
void Lawnmower::drawLawnmower(sf::RenderWindow& window) {
	lawnmowerSprite.setPosition(position.x, position.y);
	window.draw(lawnmowerSprite);

}
sf::Sprite Lawnmower::getSprite() {
	return lawnmowerSprite;
}
coordinates Lawnmower::getPosition() {
	return position;
}
int Lawnmower::getWidth() {
	return width;
}
int Lawnmower::getHeight() {
	return height;
}
int Lawnmower::getDamage() {
	return damage;
}
int Lawnmower::getCost() {
	return cost;
}
bool Lawnmower::isActive() {
	return active;
}
void Lawnmower::setWidth(int width) {
	this->width = width;
}
void Lawnmower::setHeight(int height) {
	this->height = height;
}
void Lawnmower::setDamage(int damage) {
	this->damage = damage;
}
void Lawnmower::setCost(int cost) {
	this->cost = cost;
}
void Lawnmower::setActive(bool active) {
	this->active = active;
}

void Lawnmower::moveLawnmower() {
	// Move the lawnmower continuously until it reaches the end of the screen
	if (position.x < 800) {
		if (lawnmowerClock.getElapsedTime().asSeconds() >= 0.005) {
			position.x = lawnmowerSprite.getPosition().x + 2;
			position.y = lawnmowerSprite.getPosition().y;
			lawnmowerSprite.setPosition(position.x, position.y);
			lawnmowerClock.restart();
		}
	}
	else if (position.x >= 800) {
		// Stop the lawnmower
		active = false;
		position.x = 0;
		position.y = 800;
		lawnmowerSprite.setPosition(position.x, position.y);
	}
}

void Lawnmower::checkZombieCollision(ZombieFactory& zombies) {
	for (int i = 0; i < MAX_ZOMBIES; ++i) {
		if (zombies.getZombie(i) != nullptr) {
			sf::Vector2f zombiePosition = zombies.getZombie(i)->getSprite().getPosition();
			sf::Vector2f lawnmowerPosition = lawnmowerSprite.getPosition();

			// Check for collision based on position and dimensions
			if (zombiePosition.x + zombies.getZombie(i)->getRect().width >= lawnmowerPosition.x &&
				zombiePosition.x <= lawnmowerPosition.x + width &&
				zombiePosition.y + zombies.getZombie(i)->getRect().height-50 >= lawnmowerPosition.y &&
				zombiePosition.y <= lawnmowerPosition.y + height) {
				// Collision detected between lawnmower and zombie
				// Kill the zombie
				zombies.killZombie(i);
				// Start moving the lawnmower
				active = true;
				moveLawnmower();
			}
		}
	}
}

Lawnmower::~Lawnmower() {}