#include "SnowPeashooter.h"
#include <iostream>
SnowPeashooter::SnowPeashooter(int x, int y) : Shooter(300, 20, 175, "snowpeashooter", x, y, 124, 840), slowedZombie(nullptr), slowClock(), defaultColor() {
    plantTexture.loadFromFile("Images/SnowPea.png");
    plantRect = sf::IntRect(0, 0, 127, 131);
    sf::Sprite snowPeaShooterSprite(plantTexture, plantRect);
    snowPeaShooterSprite.setScale(0.5f, 0.5f);
    snowPeaShooterSprite.setPosition(position.x, position.y + 5);
    Plant::setSprite(snowPeaShooterSprite);

    bulletTexture.loadFromFile("Images/snow projectile.png");
    bulletRect = sf::IntRect(0, 0, 26, 26);
    sf::Sprite peaBulletSprite(bulletTexture, bulletRect);
    peaBulletSprite.setPosition(position.x + 5, position.y + 5);
    Shooter::setSprite(peaBulletSprite);
}

void SnowPeashooter::attack(ZombieFactory& zombies) {
    if (bulletSprite[0].getPosition().x >= 800) {
        bulletSprite[0].setPosition(position.x + 5, position.y);
    }
    if (bulletClock[0].getElapsedTime().asSeconds() >= 0.005) {
        bulletPosition[0].x = bulletSprite[0].getPosition().x + 2;
        bulletPosition[0].y = bulletSprite[0].getPosition().y;
        bulletSprite[0].setPosition(bulletPosition[0].x, bulletPosition[0].y);
        bulletClock[0].restart();
    }
    for (int i = 0; i < MAX_ZOMBIES; i++) {
        if (zombies.getZombie(i) != nullptr) {
            if (bulletPosition[0].x + bulletRect.width >= zombies.getZombie(i)->getPosition().x && bulletPosition[0].x <= zombies.getZombie(i)->getPosition().x + zombies.getZombie(i)->getRect().width && bulletPosition[0].y + bulletRect.height >= zombies.getZombie(i)->getPosition().y && bulletPosition[0].y <= zombies.getZombie(i)->getPosition().y + zombies.getZombie(i)->getRect().height - 25) {
                // Collision detected, apply damage to the zombie
                if (bulletDamage[0].getElapsedTime().asSeconds() >= 1) {
                    bulletDamage[0].restart();
                    zombies.getZombie(i)->setHealth(zombies.getZombie(i)->getHealth() - damage);
                }
                if (slowedZombie == nullptr) {
                    zombies.getZombie(i)->setSpeed(zombies.getZombie(i)->getSpeed() / 4);
                    defaultColor = zombies.getZombie(i)->getSprite().getColor();
                    slowClock.restart();
                    slowedZombie = zombies.getZombie(i);
                    sf::Color iceBlue(0, 191, 255);
                    slowedZombie->getSprite().setColor(iceBlue);
                }   
                
                if (zombies.getZombie(i)->getHealth() <= 0) {
                    zombies.killZombie(i);
                    slowedZombie = nullptr;
                }
                bulletSprite[0].setPosition(position.x + 20, position.y);
            }
        }
    }
    if (slowedZombie != nullptr && slowClock.getElapsedTime().asSeconds() > 4) {
        slowedZombie->setSpeed(slowedZombie->getSpeed() * 4);
        slowedZombie->getSprite().setColor(defaultColor);
        slowedZombie = nullptr;
        slowClock.restart();
        cout << "speed restored" << endl;
    }
}

SnowPeashooter::~SnowPeashooter() {}
