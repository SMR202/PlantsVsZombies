#include "FlyingZombie.h"
#include <ctime>
#include <cstdlib>

FlyingZombie::FlyingZombie(int x, int y) : Zombie(250, 50, 1.5, "flyingZombie", x, y, 100, 860) {
	zombieTexture.loadFromFile("Images/flyingZombie edit.png");
	zombieRect = sf::IntRect(0, 0, 100, 135);
	sf::Sprite sprite(zombieTexture, zombieRect);
	sprite.setPosition(position.x, position.y);
	setSprite(sprite);
	sprite.setScale(0.75f, 0.75f);
}
void FlyingZombie::attack() {
	move();
}

FlyingZombie::~FlyingZombie() {}