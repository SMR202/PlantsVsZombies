#include "SunFactory.h"
#include <iostream>
#include <cmath>
#include <cstring>
SunFactory::SunFactory(int totalSun) : totalSun(totalSun), clock(), sunNum(0), deleteClock() {
    for (int i = 0; i < totalSunNum; i++) {
        suns[i] = nullptr;
    }
}

void SunFactory::generateSun(int i, int x, int y) {
    if (clock.getElapsedTime().asSeconds() >= 10) {
        suns[i] = new Sun();
        suns[i]->getSprite().setPosition(x, y);
        clock.restart();
    }
}

Sun*& SunFactory::getSun(int i) {
    return suns[i];
}

void SunFactory::collectSun() {
    float dt = deleteClock.restart().asSeconds();  // Time elapsed since the last call
    float speed = 200;
    for (int i = 0; i < totalSunNum; i++) {
        if (suns[i] != nullptr && suns[i]->getIsDeleting()) {
            float dx = 48 - suns[i]->getSprite().getPosition().x;
            float dy = 95 - suns[i]->getSprite().getPosition().y;
            // Calculate the distance to the target
            float distance = std::sqrt(dx * dx + dy * dy);

            if (distance < speed * dt) {
                // If the sun is close enough to the target, snap it to the target position
                suns[i]->getSprite().setPosition(48, 95);
                suns[i]->setIsDeleting(false);
                delete suns[i];
                suns[i] = nullptr;
                totalSun += 25;

            }
            else {
                // Normalize the direction
                dx /= distance;
                dy /= distance;

                // Move the sun along the direction towards the target, scaled by the elapsed time
                suns[i]->getSprite().setPosition(suns[i]->getSprite().getPosition().x + dx * speed * dt, suns[i]->getSprite().getPosition().y + dy * speed * dt);
            }
        }
    }
}

SunFactory::~SunFactory() {
    for (int i = 0; i < totalSunNum; i++) {
        if (suns[i] != nullptr) {
            delete this->suns[i];
            suns[i] = nullptr;
        }
    }
}
void SunFactory::isSunClicked(int x, int y) {
    for (int i = 0; i < totalSunNum; i++) {
        if (suns[i] != nullptr && (suns[i]->getSprite().getGlobalBounds().contains(x, y))) {
            suns[i]->setIsDeleting(true);
        }
    }
}
sf::Clock& SunFactory::getDeleteClock() {
    return deleteClock;
}
void SunFactory::drawTotalSun(sf::RenderWindow& window) {
    sf::Font font;
    font.loadFromFile("Light Stories.otf");
    sf::Text text;
    text.setFont(font);
    text.setString(std::to_string(totalSun));
    text.setCharacterSize(20);
    text.setFillColor(sf::Color::Black);
    text.setPosition(36, 121);
    window.draw(text);
}
int& SunFactory::getTotalSun() {
    return totalSun;
}
void SunFactory::setSun(int i, Sun* sun) {
	suns[i] = sun;
}