#pragma once
#ifndef TIMES_H
#define TIMES_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

using namespace std;

class Times {
	sf::Clock clock;
public:
	Times();
	sf::Clock getClock();
	string getTime();
};

#endif // !TIMES_H