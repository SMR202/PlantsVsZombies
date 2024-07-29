#include "RepeaterShooter.h"

RepeaterShooter::RepeaterShooter(int x, int y) : Shooter(300, 20, 175, "repeatershooter", x, y, 159, 597, 2) {
    plantTexture.loadFromFile("Images/Repeater.png");
    plantRect = sf::IntRect(0, 0, 159, 157);
    sf::Sprite repeaterShooterSprite(plantTexture, plantRect);
    repeaterShooterSprite.setScale(0.5f, 0.5f);
    repeaterShooterSprite.setPosition(position.x, position.y);
    Plant::setSprite(repeaterShooterSprite);

    bulletTexture.loadFromFile("Images/pea_projectile.png");
    bulletRect = sf::IntRect(0, 0, 24, 24);
    sf::Sprite repeaterBulletSprite(bulletTexture, bulletRect);
    repeaterBulletSprite.setPosition(position.x + 5, position.y);
    Shooter::setSprite(repeaterBulletSprite);
}
void RepeaterShooter::attack(ZombieFactory& zombies) {
    for (int bullet = 0; bullet < bulletNum; bullet++) {
        if (bulletSprite[bullet].getPosition().x >= 800 || bulletSprite[bullet].getPosition().x <= position.x + bullet * 65) {
            bulletSprite[bullet].setPosition(position.x + bullet * 60 + 5, position.y);
        }
        if (bulletClock[bullet].getElapsedTime().asSeconds() >= 0.0005) {
            bulletPosition[bullet].x = bulletSprite[bullet].getPosition().x + 1;
            bulletPosition[bullet].y = bulletSprite[bullet].getPosition().y;
            bulletSprite[bullet].setPosition(bulletPosition[bullet].x, bulletPosition[bullet].y);
            bulletClock[bullet].restart();
        }
        for (int i = 0; i < MAX_ZOMBIES; i++) {
            if (zombies.getZombie(i) != nullptr) {
                if (bulletPosition[bullet].x + bulletRect.width >= zombies.getZombie(i)->getPosition().x && bulletPosition[bullet].x <= zombies.getZombie(i)->getPosition().x + zombies.getZombie(i)->getRect().width && bulletPosition[bullet].y + bulletRect.height >= zombies.getZombie(i)->getPosition().y && bulletPosition[bullet].y <= zombies.getZombie(i)->getPosition().y + zombies.getZombie(i)->getRect().height - 25) {
                    // Collision detected, apply damage to the zombie
                    if (bulletDamage[bullet].getElapsedTime().asSeconds() >= 1) {
                        bulletDamage[bullet].restart();
                        zombies.getZombie(i)->setHealth(zombies.getZombie(i)->getHealth() - damage);
                    }
                    if (zombies.getZombie(i)->getHealth() <= 0) {
                        zombies.killZombie(i);
                    }
                    bulletSprite[bullet].setPosition(position.x + bullet * 20 + 5, position.y);
                }
            }
        }
    }
}

RepeaterShooter::~RepeaterShooter() {}
