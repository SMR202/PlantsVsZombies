#include "Peashooter.h"

Peashooter::Peashooter(int x, int y) : Shooter(300, 20, 100, "peashooter", x, y, 155, 4333) {
    plantTexture.loadFromFile("Images/peashooter2.png");
    plantRect = sf::IntRect(0, 0, 155, 131);
    sf::Sprite peaShooterSprite(plantTexture, plantRect);
    peaShooterSprite.setScale(0.55f, 0.55f);
    peaShooterSprite.setPosition(position.x, position.y+5);
    Plant::setSprite(peaShooterSprite);
    

    bulletTexture.loadFromFile("Images/pea_projectile.png");
    bulletRect = sf::IntRect(0, 0, 24, 24);
    sf::Sprite peaBulletSprite(bulletTexture, bulletRect);
    peaBulletSprite.setPosition(position.x + 40, position.y);
    Shooter::setSprite(peaBulletSprite);
}
void Peashooter::attack(ZombieFactory& zombies) {
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
                if (zombies.getZombie(i)->getHealth() <= 0) {
                    zombies.killZombie(i);
                }
                bulletSprite[0].setPosition(position.x + 40, position.y);
            }
        }
    }
}

Peashooter::~Peashooter() {}
