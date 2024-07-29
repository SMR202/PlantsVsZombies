#include "GameState.h"
#include "Sunflower.h"
#include "CherryBomb.h"
#include "MenuState.h"
GameState::GameState() : isPaused(false), lives(3), killCount(0), isGameOver(false)
{
	music.openFromFile("Audio/french.mp3");
	music.setLoop(true);
	music.play();

	gameImage.loadFromFile("Images/background2.png");//load the file for the map
	gameTexture.loadFromImage(gameImage);
	gameSprite.setTexture(gameTexture);
	gameSprite.setPosition(0, 0);

	shopImage.loadFromFile("Images/shop2.png");//load the file for the map
	shopTexture.loadFromImage(shopImage);
	shopSprite.setTexture(shopTexture);
	shopSprite.setPosition(0, 0);

	gameoverImage.loadFromFile("Images/gameover.png");//load the file for the map
	gameoverTexture.loadFromImage(gameoverImage);
	gameoverSprite.setTexture(gameoverTexture);
	gameoverSprite.setPosition(0, 0);

}

GameState::~GameState() {}

void GameState::draw(sf::RenderWindow &window)
{
	window.draw(gameSprite);
	window.draw(shopSprite);
}

void GameState::update(Game& pvz, sf::RenderWindow& window)
{	
	float animationSpeed = 0.1;

	draw(window);

	pvz.getLevel().getSeeds().drawSeeds(window);

	sf::Text text;
	sf::Font font;
	if (!font.loadFromFile("Light Stories.otf")) {}
	text.setFont(font);
	text.setCharacterSize(30);
	text.setPosition(10, 395);
	// Set text string
	text.setFillColor(sf::Color::Black);
	text.setStyle(sf::Text::Bold);

	for (int i = 0; i < 5; i++) {
		pvz.getLevel().getLawnmower(i).drawLawnmower(window);
	}
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		if (sf::Mouse::getPosition(window).x > 726 && sf::Mouse::getPosition(window).x < 797 && sf::Mouse::getPosition(window).y > 66 && sf::Mouse::getPosition(window).y < 96) {
			isPaused = true;
		}
		else if (sf::Mouse::getPosition(window).x > 726 && sf::Mouse::getPosition(window).x < 797 && sf::Mouse::getPosition(window).y > 34 && sf::Mouse::getPosition(window).y < 64) {
			isPaused = false;
		}
		else if (sf::Mouse::getPosition(window).x > 726 && sf::Mouse::getPosition(window).x < 797 && sf::Mouse::getPosition(window).y > 2 && sf::Mouse::getPosition(window).y < 32) {
			pvz.setState(new MenuState());
			pvz.restartLevel();
		}
	}

	int sunNum = 0;

	pvz.getLevel().getSunFactory().drawTotalSun(window);

	for (int i = 0; i < MAX_PLANTS; i++) { 
		if (pvz.getLevel().getPlantFactory().getPlant(i) != nullptr)
			pvz.getLevel().getPlantFactory().getPlant(i)->drawPlant(window); 
	}
	for (int i = 0; i < MAX_ZOMBIES; i++) {
		if (pvz.getLevel().getZombieFactory().getZombie(i) != nullptr) 
			window.draw(pvz.getLevel().getZombieFactory().getZombie(i)->getSprite()); 
	}
	for (int i = 0 ; i < 15; i++) { 
		if (pvz.getLevel().getSunFactory().getSun(i) != nullptr) 
			window.draw(pvz.getLevel().getSunFactory().getSun(i)->getSprite()); 
	}
	if (isPaused) {
		text.setString("PAUSED");
		window.draw(text);
	}
	if (!isPaused) {

		text.setString(pvz.getLevel().getTime()->getTime());

		for (int i = 0; i < MAX_PLANTS; i++) {
			if (pvz.getLevel().getPlantFactory().getPlant(i) != nullptr) {
				pvz.getLevel().getPlantFactory().getPlant(i)->getSprite().setPosition(pvz.getLevel().getPlantFactory().getPlant(i)->getPosition().x, pvz.getLevel().getPlantFactory().getPlant(i)->getPosition().y);
				runSprite(pvz.getLevel().getPlantFactory().getPlant(i)->getClock(), animationSpeed, pvz.getLevel().getPlantFactory().getPlant(i)->getRect(), pvz.getLevel().getPlantFactory().getPlant(i)->getSprite(), pvz.getLevel().getPlantFactory().getPlant(i)->getlimitX(), pvz.getLevel().getPlantFactory().getPlant(i)->getIncrementX());
				pvz.getLevel().getPlantFactory().getPlant(i)->attack(pvz.getLevel().getZombieFactory());
				if (pvz.getLevel().getPlantFactory().getPlant(i)->getName() == "sunflower") {
					((Sunflower*)pvz.getLevel().getPlantFactory().getPlant(i))->produceSun(pvz.getLevel().getSunFactory());
				}
				if (pvz.getLevel().getPlantFactory().getPlant(i)->getName() == "cherrybomb") {
					if (((CherryBomb*)pvz.getLevel().getPlantFactory().getPlant(i))->getExplosionClock().getElapsedTime().asSeconds() >= 1.3) {
						pvz.getLevel().getPlantFactory().killPlant(i, pvz.getGrid());
					}
				}
			}

		}

		for (int i = 0; i < MAX_ZOMBIES; i++) {
			if (pvz.getLevel().getZombieFactory().getZombie(i) != nullptr) {
				runSprite(pvz.getLevel().getZombieFactory().getZombie(i)->getAnimationClock(), animationSpeed, pvz.getLevel().getZombieFactory().getZombie(i)->getRect(), pvz.getLevel().getZombieFactory().getZombie(i)->getSprite(), pvz.getLevel().getZombieFactory().getZombie(i)->getLimitX(), pvz.getLevel().getZombieFactory().getZombie(i)->getIncrementX());
				pvz.getLevel().getZombieFactory().getZombie(i)->attack(pvz.getLevel().getPlantFactory(), pvz.getGrid());
				if (pvz.getLevel().getZombieFactory().getZombie(i)->getPosition().y > 1500) {
					pvz.getLevel().getZombieFactory().killZombie(i);
					lives--;
					cout<< "Lives: " << lives << endl;
				}
			}
			else {
				pvz.getLevel().getZombieFactory().createZombie("simpleZombie");
			}
		}

		if (sunNum > 15) {
			sunNum = 0;
		}
		for (; sunNum < 15; sunNum++) {
			if (pvz.getLevel().getSunFactory().getSun(sunNum) != nullptr) {
				pvz.getLevel().getSunFactory().getSun(sunNum)->moveSun();
				pvz.getLevel().getSunFactory().collectSun();
			}
			else {
				pvz.getLevel().getSunFactory().generateSun(sunNum);
			}
		}

		for (int i = 0; i < 5; i++) {
			pvz.getLevel().getLawnmower(i).checkZombieCollision(pvz.getLevel().getZombieFactory());
			if (pvz.getLevel().getLawnmower(i).isActive())
				pvz.getLevel().getLawnmower(i).moveLawnmower();
		}
	}
	window.draw(text);

	if (lives == 0 && !isGameOver) {
		isPaused = true;
		cout<< "Game Over" << endl;
		gameoverClock.restart();
		isGameOver = true;
	}
	if (isGameOver) {
		if (gameoverClock.getElapsedTime().asSeconds() > 6) {
			pvz.setState(new MenuState());
			pvz.restartLevel();
		}
		else {
			window.draw(gameoverSprite);
		}
	}



}

void GameState::runSprite(Clock& clock, float animationSpeed, IntRect& textureRect, Sprite& textureSprite, int picLimit, float increment) {
	if (clock.getElapsedTime().asSeconds() > animationSpeed) {
		if (textureRect.left >= picLimit)
			textureRect.left = 0;
		else
			textureRect.left += increment;

		textureSprite.setTextureRect(textureRect);

		clock.restart();
	}
}

void GameState::pause() {
	
}
void GameState::resume() {
	
}