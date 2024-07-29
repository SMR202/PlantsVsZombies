#include "MenuState.h"
#include "GameState.h"
#include "Game.h"
#include <iostream>
#include <fstream>
MenuState::MenuState() : clock()
{
	stage = "menu";

	music.openFromFile("Audio/menu.mp3");
	music.setLoop(true);
	music.play();
	menuImage.loadFromFile("images/menu.png");
	menuTexture.loadFromImage(menuImage);
	menuSprite.setTexture(menuTexture);
	menuSprite.setPosition(0, 0);

	levelImage.loadFromFile("images/stage select.png");
	levelTexture.loadFromImage(levelImage);
	levelSprite.setTexture(levelTexture);
	levelSprite.setPosition(0, 0);
	
	instructionsImage.loadFromFile("images/instructions.png");
	instructionsTexture.loadFromImage(instructionsImage);
	instructionsSprite.setTexture(instructionsTexture);

	leaderboardImage.loadFromFile("images/leaderboard.png");
	leaderboardTexture.loadFromImage(leaderboardImage);
	leaderboardSprite.setTexture(leaderboardTexture);

	std::ifstream file("player_data.txt");
	std::string line;

	int playerCount = 0;
	int currentLine = 0;

	if (file.is_open()) {
		while (std::getline(file, line) && currentLine<39) {
			if (currentLine % 2 == 0) {
				player[playerCount].name = line;
			}
			else if (currentLine % 2 == 1) {
				player[playerCount].score = std::stoi(line);
				playerCount++;
			}
			currentLine++;
		}
		file.close();
	}
	else {
		std::cout << "Error: Unable to open file.\n";
	}

	for (int i = 0; i < playerCount - 1; i++)
	{
		for (int j = 0; j < playerCount - i - 1; j++)
		{
			if (player[j].score < player[j + 1].score)
			{
				// Swap players
				Highscore temp = player[j];
				player[j] = player[j + 1];
				player[j + 1] = temp;
			}
		}
	}

	cout<< "Leaderboard:\n";
	for (int i = 0; i < playerCount; i++)
	{
		cout << player[i].name << " - " << player[i].score << endl;
	}

}

MenuState::~MenuState() {}

void MenuState::update(Game& game, sf::RenderWindow& window)
{
	if (stage == "menu") {
		draw(window);
	}
	else if (stage == "levels"){
		drawScreen(window, levelSprite);
	}
	else if (stage == "instructions") {
		drawScreen(window, instructionsSprite);
	}
	else if (stage == "leaderboard") {
		drawScreen(window, leaderboardSprite);
		drawHighScores(window);
	}
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		if (stage == "menu" && clock.getElapsedTime().asSeconds() > 0.5)
		{
			sf::Vector2i mousePos = sf::Mouse::getPosition(window);
			if (mousePos.x > 395 && mousePos.x < 606 && mousePos.y > 104 && mousePos.y < 185)
			{
				stage = "levels";
				clock.restart();
			}
			else if (mousePos.x > 395 && mousePos.x < 574 && mousePos.y > 211 && mousePos.y < 306) {
				window.close();
				cout << "Game Over!\n";
			}
			else if (mousePos.x > 13 && mousePos.x < 198 && mousePos.y > 231 && mousePos.y < 301) {
				stage = "instructions";
				clock.restart();
			}
			else if (mousePos.x > 12 && mousePos.x < 198 && mousePos.y > 151 && mousePos.y < 221) {
				stage = "leaderboard";
				clock.restart();
			}
		}
		else if (stage == "levels" && clock.getElapsedTime().asSeconds() > 0.5) {
			game.setState(new GameState());
		}
		else if ((stage == "instructions" || stage == "leaderboard") && clock.getElapsedTime().asSeconds() > 0.5) {
			if (sf::Mouse::getPosition(window).x > 17 && sf::Mouse::getPosition(window).x < 154 && sf::Mouse::getPosition(window).y > 15 && sf::Mouse::getPosition(window).y < 62) {
				stage = "menu";
			}
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		
	}

}
void MenuState::draw(sf::RenderWindow& window)
{
	window.draw(menuSprite);
}
void MenuState::drawScreen(sf::RenderWindow& window, sf::Sprite& sprite)
{
	window.draw(sprite);
}
void MenuState::drawHighScores(sf::RenderWindow& window)
{
	sf::Font font;
	font.loadFromFile("Light Stories.otf");
	sf::Text text;
	text.setFont(font);
	text.setCharacterSize(40);
	text.setFillColor(sf::Color::Black);
	text.setPosition(295, 210);
	for (int i = 0; i < 3; i++)
	{
		text.setString(player[i].name + " - " + std::to_string(player[i].score));
		window.draw(text);
		text.move(0, 59);
	}
}
