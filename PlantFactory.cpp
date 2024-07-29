#include "PlantFactory.h"
#include "Peashooter.h"
#include "Sunflower.h"
#include "SnowPeashooter.h"
#include "RepeaterShooter.h"
#include "Walnut.h"
#include "CherryBomb.h"
#include "Grid.h"
#include <iostream>
using namespace std;

PlantFactory::PlantFactory(int lvl) : index(0), numPlants(0) {
    for (int i = 0; i < MAX_PLANTS; i++) {
        plants[i] = nullptr;
    }
}

PlantFactory::~PlantFactory() {
    for (int i = 0; i < MAX_PLANTS; i++) {
        if (plants[i] != nullptr)
            delete plants[i];
    }
}

Plant*& PlantFactory::createPlant(std::string name, int x, int y) {
    Plant* newPlant = nullptr;
    if (name == "peaShooter") {
        newPlant = new Peashooter(x, y);
    }
    else if (name == "sunflower") {
        newPlant = new Sunflower(x, y);
    }
    else if (name == "snowPeaShooter") {
        newPlant = new SnowPeashooter(x, y);
    }
    else if (name == "repeaterShooter") {
        newPlant = new RepeaterShooter(x, y);
    }
    else if (name == "walnut") {
        newPlant = new Walnut(x, y);
    }
    else if (name == "cherryBomb") {
        newPlant = new CherryBomb(x, y);
    }
    if (newPlant != nullptr) {
        plants[numPlants++] = newPlant;
    }
    return newPlant;
}

Plant*& PlantFactory::getPlant(int i) {
    return plants[i];
}

void PlantFactory::killPlant(int index, Grid& grid) {
    // Now, find the corresponding tile where the plant is located
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            if (grid.getTile(i, j).getPlant() == plants[index]) {
                cout << "plant killed" << endl;
                grid.getTile(i, j).removePlant(); // Remove the plant pointer from the tile
                grid.setIsPlantable(i, j, true); // Set the tile to plantable
                return; // No need to continue searching, we found the corresponding tile
            }
        }
    }

    delete plants[index]; // Delete the plant object
    plants[index] = nullptr; // Set the pointer in the plant factory to nullptr
}