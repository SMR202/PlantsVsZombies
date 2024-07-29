#include "Times.h"
#include <iostream>
#include <string>

Times::Times() : clock(){}

sf::Clock Times::getClock() {
	return clock;
}

string Times::getTime() {
    sf::Time elapsed = clock.getElapsedTime();

    // Convert elapsed time to minutes and seconds
    int minutes = elapsed.asSeconds() / 60;
    int seconds = (int)elapsed.asSeconds() % 60;

    // Format time as a string
    std::string timeString = "Time: " + std::to_string(minutes) + "m " + std::to_string(seconds) + "s";

    return timeString;
}
