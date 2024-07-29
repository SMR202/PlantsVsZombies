#include "Shooter.h"

Shooter::Shooter(int health, int damage, int cost, std::string name, int x, int y, int incrementX, int limitX, int bulletNum)
    : Plant(health, damage, cost, name, x, y, incrementX, limitX), bulletNum(bulletNum) {
    for (int i = 0; i < bulletNum; i++) {
		bulletPosition[i] = { position.x + i * 60 + 5 , position.y };
		bulletSprite[i].setPosition(bulletPosition[i].x, bulletPosition[i].y);
	}

}

void Shooter::setSprite(sf::Sprite& bulletsprite) {
	for (int i = 0; i < bulletNum; i++) {
		bulletSprite[i] = bulletsprite;
	}

}

void Shooter::setBulletPosition(int x, int y) {
	for (int i = 0; i < bulletNum; i++) {
		bulletPosition[i] = { x, y };
	}	
}

sf::Sprite& Shooter::getSprite() {
    return bulletSprite[0];
}

sf::IntRect& Shooter::getRect() {
    return bulletRect;
}

void Shooter::drawPlant(sf::RenderWindow& window) {
    window.draw(plantSprite);
	for (int i = 0; i < bulletNum; i++)
		window.draw(bulletSprite[i]);
}

Shooter::~Shooter() {}
