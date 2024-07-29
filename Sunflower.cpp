#include "Sunflower.h"
#include <iostream>
Sunflower::Sunflower(int x, int y) : Plant(300, 0, 100, "sunflower", x, y, 127, 630), sun(nullptr) {
    plantTexture.loadFromFile("Images/Sunflower.png");
    plantRect = sf::IntRect(0, 0, 133, 150);
    sf::Sprite sunflowerSprite(plantTexture, plantRect);
    sunflowerSprite.setScale(0.5f, 0.5f);
    sunflowerSprite.setPosition(position.x, position.y);
    setSprite(sunflowerSprite);

}

void Sunflower::attack(ZombieFactory& zombies) {
    // Sunflower does not attack
}
void Sunflower::produceSun(SunFactory& sunFactory){
    if (sunClock.getElapsedTime().asSeconds() > 10) {
        int i = 0;
        cout<<"Sunflower produce sun"<<endl;
        for (; i < totalSunNum; i++) {
            if (sunFactory.getSun(i) == nullptr) {
                sunFactory.setSun(i, new Sun());
                sunFactory.getSun(i)->setSpeed(0);
                sunFactory.getSun(i)->getSprite().setPosition(position.x + 20, position.y + 20);
                break;
            }
        }
        sunClock.restart();
    }

}

Sunflower::~Sunflower() {
    delete sun;
    sun = nullptr;
}

