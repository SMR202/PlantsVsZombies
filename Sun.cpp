#include "Sun.h"

Sun::Sun() : moveClock(), isDeleting(false), speed(1), spriteClock() {
    sunTexture.loadFromFile("Images/sun1.png");
    sunRect = sf::IntRect(0, 0, 130, 130);
    sunSprite.setTexture(sunTexture);
    sunSprite.setTextureRect(sunRect);
    sunSprite.setScale(0.4f, 0.4f);
    sunSprite.setPosition(200, 0);
    sunSprite.setOrigin(sunSprite.getLocalBounds().width / 2, sunSprite.getLocalBounds().height / 2);
}

void Sun::moveSun() {
    if (sunSprite.getPosition().y < 450 && moveClock.getElapsedTime().asSeconds() >= 0.0005) {
        
        sunSprite.setPosition(sunSprite.getPosition().x, sunSprite.getPosition().y + speed);

        if (sunRect.left >= 3700)
            sunRect.left = 0;
        else
            sunRect.left += 130;
        sunSprite.setTextureRect(sunRect);

        moveClock.restart();
    }
}

sf::Sprite& Sun::getSprite() {
    return sunSprite;
}

sf::IntRect& Sun::getRect() {
    return sunRect;
}

void Sun::setSprite(sf::Sprite& sunsprite) {
    this->sunSprite = sunsprite;
}
bool Sun::getIsDeleting() {
    return isDeleting;
}
void Sun::setIsDeleting(bool isDeleting) {
    this->isDeleting = isDeleting;
}
int Sun::getSpeed() {
    return speed;
}
void Sun::setSpeed(int speed) {
    this->speed = speed;
}
sf::Clock& Sun::getMoveClock() {
    return moveClock;
}
sf::Clock& Sun::getSpriteClock() {
	return spriteClock;
}