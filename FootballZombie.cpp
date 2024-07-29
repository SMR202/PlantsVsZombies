#include "FootballZombie.h"
#include <ctime>
#include <cstdlib>

FootballZombie::FootballZombie(int x, int y) : Zombie(600, 50, 1.5, "footballZombie", x, y, 97, 670), verticalClock() {
	zombieTexture.loadFromFile("Images/FootballZombie.png");
	zombieRect = sf::IntRect(0, 118, 100, 100);
	sf::Sprite sprite(zombieTexture, zombieRect);
	sprite.setPosition(position.x, position.y);
	setSprite(sprite);
}
void FootballZombie::move() {
	if (moveClock.getElapsedTime().asSeconds() >= 0.05) {
		position.x = zombieSprite.getPosition().x - speed;
		if (verticalClock.getElapsedTime().asSeconds() > 3) {
			int i = 0;
			int randRow[5] = { 20, 85, 160, 225, 295 }; // [0, 1, 2, 3, 4]
			for (; i < 5; i++) {
				if (position.y == randRow[i]) {
					break;
				}
			}
			int randomNum = rand() % 2;
			if (randomNum == 0 && i!=0) {
				position.y = randRow[i - 1];
			}
			else if (randomNum == 1 && i!=4){
				position.y = randRow[i + 1];
			}
			else {
				position.y = randRow[i];
			}
			verticalClock.restart();
		}
		zombieSprite.setPosition(position.x, position.y);
		moveClock.restart();
		if (position.x <= 140 && position.y < 429) {
			zombieSprite.setPosition(140, 1800);
			position.y = 1800;
		}
	}
}

FootballZombie::~FootballZombie() {}

