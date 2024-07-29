#include "CherryBomb.h"

CherryBomb::CherryBomb(int x, int y) : Plant(300, 500, 150, "cherrybomb", x, y, 331, 3975) , explosionClock() {
    plantTexture.loadFromFile("Images/cherryBomb.png");
    plantRect = sf::IntRect(0, 0, 331, 233);
    sf::Sprite cherryBombSprite(plantTexture, plantRect);
    cherryBombSprite.setScale(0.5f, 0.5f);
    cherryBombSprite.setPosition(position.x, position.y);
    setSprite(cherryBombSprite);
}

void CherryBomb::attack(ZombieFactory& zombies) {
    if (explosionClock.getElapsedTime().asSeconds() < 0.5f) {
        // CherryBomb is inflating, not yet ready to explode
        return;
    }
    // Define blast radius
    const int blastRadius = 1; // 3x3 area: 1 tile in each direction

    // Get CherryBomb position on the grid
    int bombX = getPosition().x / 179;
    int bombY = getPosition().y / 56;

    // Iterate over tiles in the blast radius
    for (int i = -blastRadius; i <= blastRadius; ++i) {
        for (int j = -blastRadius; j <= blastRadius; ++j) {
            int x = bombX + i;
            int y = bombY + j;

            // Check if tile is within grid bounds
            if (x >= 0 && x < 9 && y >= 0 && y < 5) {
                // Check if there's a zombie on the tile
                for (int k = 0; k < MAX_ZOMBIES; ++k) {
                    if (zombies.getZombie(k) != nullptr &&
                        zombies.getZombie(k)->getPosition().x / 179 == x &&
                        zombies.getZombie(k)->getPosition().y / 56 == y) {
                        // Destroy zombie
                        zombies.killZombie(k);
                    }
                }
            }
        }
    }

    // Remove CherryBomb from the grid
    this->setHealth(0);
}
sf::Clock& CherryBomb::getExplosionClock() {
	return explosionClock;
}

CherryBomb::~CherryBomb() {}
