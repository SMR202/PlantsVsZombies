#include "Shovel.h"
#include <iostream>
using namespace std;

Shovel::Shovel() : positionX(400), positionY(13), clicked(false) {}

void Shovel::use(Grid& grid, coordinates& point, PlantFactory& plants) {
    // Check if the mouse position is within the bounds of any plant sprite
    for (int i = 0; i < MAX_PLANTS; i++) {
        if (plants.getPlant(i) != nullptr) {
            if (plants.getPlant(i)->getSprite().getGlobalBounds().contains(point.x, point.y)) {
                // Collision detected, remove the clicked plant
                plants.getPlant(i)->setHealth(plants.getPlant(i)->getHealth() - 250);
                plants.killPlant(i, grid);
                // Exit the loop after removing the clicked plant
                break;
            }
        }
    }
}

void Shovel::setclicked(bool clicked) {
	this->clicked = clicked;
}

bool Shovel::getclicked() {
	return clicked;
}

Shovel::~Shovel() {}
