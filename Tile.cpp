#include "Tile.h"

Tile::Tile(Plant* plant, Zombie* zombies[MAX_ZOMBIES_PER_TILE]) : plant(plant) {
    for (int i = 0; i < MAX_ZOMBIES_PER_TILE; ++i) {
        this->zombies[i] = nullptr;
    }
}

void Tile::addPlant(Plant* plant) {
    if (plant != nullptr) {
        this->plant = plant;
        plant->setPosition(topLeft.x, topLeft.y);
    }
}

void Tile::removePlant() {
    this->plant = nullptr;
}

Plant*& Tile::getPlant() {
    return plant;
}

coordinates& Tile::getTopLeft() {
	return topLeft;
}

coordinates& Tile::getBottomRight() {
	return bottomRight;
}

coordinates& Tile::getTopRight() {
	return topRight;
}

coordinates& Tile::getBottomLeft() {
	return bottomLeft;
}

coordinates& Tile::getCenter() {
	return center;
}

void Tile::setTopLeft(coordinates& topLeft) {
	this->topLeft = topLeft;
}

void Tile::setBottomRight(coordinates& bottomRight) {
	this->bottomRight = bottomRight;
}

void Tile::setTopRight(coordinates& topRight) {
	this->topRight = topRight;
}

void Tile::setBottomLeft(coordinates& bottomLeft) {
	this->bottomLeft = bottomLeft;
}

void Tile::setCenter(coordinates& center) {
	this->center = center;
}

