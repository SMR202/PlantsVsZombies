#pragma once
#ifndef SUNFACTORY_H 
#define SUNFACTORY_H

#include "Sun.h"
#include "Constants.h"
#include <SFML/System/Clock.hpp>

class SunFactory {
protected:
    Sun* suns[totalSunNum];
    int totalSun;
    sf::Clock clock, deleteClock;
    int sunNum;

public:
    SunFactory(int totalSun = 250);

    void generateSun(int i = 0, int x = rand() % 710 + 180, int y = 0);
    Sun*& getSun(int i);
    void setSun(int i, Sun* sun);
    void collectSun();
    ~SunFactory();
    void isSunClicked(int x, int y);
    sf::Clock& getDeleteClock();
    void drawTotalSun(sf::RenderWindow& window);
    int& getTotalSun();
};

#endif // !SUNFACTORY_H