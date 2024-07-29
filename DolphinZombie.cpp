#include "DolphinZombie.h"
#include <ctime>
#include <cstdlib>

DolphinZombie::DolphinZombie(int x, int y) : Zombie(500, 50, 3, "dolphinZombie", x, y, 110, 615) {
	zombieTexture.loadFromFile("Images/DolphinZombie.png");
	zombieRect = sf::IntRect(0, 0, 100, 110);
	sf::Sprite sprite(zombieTexture, zombieRect);
	sprite.setPosition(position.x, position.y);
	setSprite(sprite);
}

DolphinZombie::~DolphinZombie() {}