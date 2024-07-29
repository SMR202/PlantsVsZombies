#pragma once
#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "State.h"
#include "Game.h"
#include <SFML/Audio.hpp>
class State;


class GameState : public State {
private:
	sf::Sprite gameSprite;
	sf::Image gameImage;
	sf::Texture gameTexture;
	sf::Sprite shopSprite;
	sf::Image shopImage;
	sf::Texture shopTexture;

	sf::Sprite gameoverSprite;
	sf::Image gameoverImage;
	sf::Texture gameoverTexture;
	sf::Clock gameoverClock;

	int lives;
	int killCount;
	bool isPaused;
	bool isGameOver;

	sf::Music music;

public:
	GameState();
	virtual ~GameState();

	void pause();
	void resume();

	void update(Game& pvz, sf::RenderWindow& window);
	virtual void draw(sf::RenderWindow& window);
	void runSprite(Clock& clock, float animationSpeed, IntRect& textureRect, Sprite& textureSprite, int picLimit, float increment);
};

#endif // !GAMESTATE_H
