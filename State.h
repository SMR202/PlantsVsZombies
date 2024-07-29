#pragma once
#ifndef STATE_H
#define STATE_H
#include <SFML/Graphics.hpp>

class Game;
class State {

public:
	virtual void draw(sf::RenderWindow& window) = 0;
	virtual void update(Game& game, sf::RenderWindow& window) = 0;
	virtual ~State();

};
#endif // !STATE_H
