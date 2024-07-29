#pragma once
#ifndef MENUSTATE_H
#define MENUSTATE_H

#include "State.h"
#include "Highscore.h"
#include <SFML/Audio.hpp>

class MenuState : public State
{
	sf::Sprite menuSprite;
	sf::Image menuImage;
	sf::Texture menuTexture;

	sf::Sprite levelSprite;
	sf::Image levelImage;
	sf::Texture levelTexture;

	sf::Sprite instructionsSprite;
	sf::Image instructionsImage;
	sf::Texture instructionsTexture;

	sf::Sprite leaderboardSprite;
	sf::Image leaderboardImage;
	sf::Texture leaderboardTexture;

	std::string stage;

	sf::Clock clock;

	Highscore player[20];

	sf::Music music;

public:
	MenuState();
	virtual ~MenuState();

	void update(Game& game, sf::RenderWindow& window);
	void render() {}
	void onEnter() {}
	void onExit() {}
	void resume() {}
	virtual void draw(sf::RenderWindow& window);
	void drawScreen(sf::RenderWindow& window, sf::Sprite& sprite);
	void drawHighScores(sf::RenderWindow& window);
};


#endif // !MENUSTATE_H
