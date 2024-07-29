#include "Levels.h"

Levels::Levels(int num, int& score) : score(score), plantFactory(), zombieFactory(score), time(new Times()), num(num), name(), description(), objectives(), challenges(), rewards(), wave(), shovel(), sunFactory(), lawnmowers{
    Lawnmower(100, 50, 50, 5, 500, 0, false),
    Lawnmower(100, 115, 50, 5, 500, 0, false),
    Lawnmower(100, 180, 50, 5, 500, 0, false),
    Lawnmower(100, 250, 50, 5, 500, 0, false),
    Lawnmower(100, 325, 50, 5, 500, 0, false)
} {

}

Levels::~Levels() {
    delete time;
    time = nullptr;
}

PlantFactory& Levels::getPlantFactory() {
    return plantFactory;
}

ZombieFactory& Levels::getZombieFactory() {
    return zombieFactory;
}

SunFactory& Levels::getSunFactory() {
    return sunFactory;
}
Lawnmower& Levels::getLawnmower(int index) {
	return lawnmowers[index];
}
Seeds& Levels::getSeeds() {
	return seeds;
}
Shovel& Levels::getShovel() {
	return shovel;
}
Times*& Levels::getTime() {
	return time;
}