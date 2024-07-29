#include "Walnut.h"
#include <iostream>
Walnut::Walnut(int x, int y) : Plant(4000, 0, 50, "walnut", x, y, 131, 900), angle(0), rollClock() {
    plantTexture.loadFromFile("Images/Walnut3.png");
    plantRect = sf::IntRect(0, 383, 131, 135);
    sf::Sprite walnutSprite(plantTexture, plantRect);
    walnutSprite.setScale(0.5f, 0.5f);
    walnutSprite.setPosition(position.x, position.y);
    setSprite(walnutSprite);
}

void Walnut::attack(ZombieFactory& zombies) {

    for (int i = 0; i < MAX_ZOMBIES; i++) {
		if (zombies.getZombie(i) != nullptr) {
			if (zombies.getZombie(i)->getSprite().getGlobalBounds().intersects(getSprite().getGlobalBounds())) {
				if (angle == 0) {

					if (zombies.getZombie(i)->getPosition().y > 160) {
						angle = -1;
					}
					else {
						angle = 1;
					}
				}
				else if (angle == 1) {
					angle = -1;
				}
				else {
					angle = 1;
				}
				zombies.killZombie(i);
			}
		}
	}
	roll();
}
void Walnut::roll() {
	if (position.x < 1000) {
		if (rollClock.getElapsedTime().asSeconds() > 0.001) {
			position.x += 1;
			position.y += angle;
			getSprite().setPosition(position.x, position.y);
			rollClock.restart();

		}
	}
}


Walnut::~Walnut() {}
