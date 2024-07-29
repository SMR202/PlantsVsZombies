/*
Muhammad Sameer - Humayun Bilal
23i-0634 ------ 23i-0832
CS-D
*/


#include <iostream>
#include <SFML/Graphics.hpp>
#include <ctime>
#include "Game.h"

//#include"../SFML/Images/"
using namespace sf;
using namespace std;



int main()
{
	srand(time(0));
	//Create a window, n*n
	RenderWindow window(VideoMode(800, 429), "Plants VS Zombies");
	window.setMouseCursorVisible(false); // Hide cursor
	//Game icon
	Image icon;
	if (!icon.loadFromFile("Images/icon3.png"))
	{
		return 1;
	}
	window.setIcon(32, 32, icon.getPixelsPtr());

	sf::Texture cursorTexture;
	if (!cursorTexture.loadFromFile("Images/cursor2.png"))
		return 1; // Load your custom cursor image


	sf::Sprite cursor(cursorTexture);
	cursor.setScale(0.5f, 0.5f);
	//cursor.setOrigin(cursor.getTexture()->getSize().x / 2, cursor.getTexture()->getSize().y / 2);

	//Game field (5*9)
	//Point 137*79 - leftmost point
	//length 41; width 53
	const int ROWS = 5;
	const int COLS = 9;
	Game pvz;

	pvz.startGame();

	bool clicked = false;


	int selectedSeed = 0;


	while (window.isOpen())
	{
		window.clear();


		int& totalSun = pvz.getLevel().getSunFactory().getTotalSun();
		pvz.getLevel().getSeeds().checkSeedAvailability(totalSun);

		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();

			// Handle mouse button press
			if (event.type == Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == Mouse::Left)
				{
					// Left mouse button is pressed
					// Add your logic here (e.g., shoot, select, etc.)
					cursor = pvz.getLevel().getSeeds().updateCursorSprite(window, clicked, selectedSeed, event, totalSun);
					cout<<clicked<<endl;

					if (Mouse::getPosition(window).x >= 179 && Mouse::getPosition(window).x <= 690 && Mouse::getPosition(window).y >= 60 && Mouse::getPosition(window).y <= 400) {
						int x = Mouse::getPosition(window).x;
						int y = Mouse::getPosition(window).y;
						coordinates temp = pvz.getGrid().checkBounds(x, y);
						x = temp.x;
						y = temp.y;
						cout << x << " , " << y << endl;
						if (pvz.getGrid().getIsPlantable(x, y) == true && clicked) {
							// Check if the tile already contains a plant
							if (pvz.getGrid().getTile(x, y).getPlant() == nullptr) {
								pvz.getGrid().setIsPlantable(x, y, true);
								if (selectedSeed == 1 && totalSun >= 100) {
									pvz.getGrid().getTile(x, y).addPlant(pvz.getLevel().getPlantFactory().createPlant("peaShooter", Mouse::getPosition(window).x - 25, Mouse::getPosition(window).y - 25));
									totalSun -= 100;
								}
								else if (selectedSeed == 2 && totalSun >= 100) {
									pvz.getGrid().getTile(x, y).addPlant(pvz.getLevel().getPlantFactory().createPlant("sunflower", Mouse::getPosition(window).x - 25, Mouse::getPosition(window).y - 25));
									totalSun -= 100;
								}
								else if (selectedSeed == 3 && totalSun >= 150) {
									pvz.getGrid().getTile(x, y).addPlant(pvz.getLevel().getPlantFactory().createPlant("cherryBomb", Mouse::getPosition(window).x - 25, Mouse::getPosition(window).y - 25));
									totalSun -= 150;
								}
								else if (selectedSeed == 4 && totalSun >= 50) {
									pvz.getLevel().getPlantFactory().createPlant("walnut", Mouse::getPosition(window).x - 25, Mouse::getPosition(window).y - 25);
									totalSun -= 50;
								}
								else if (selectedSeed == 5 && totalSun >= 175) {
									pvz.getGrid().getTile(x, y).addPlant(pvz.getLevel().getPlantFactory().createPlant("snowPeaShooter", Mouse::getPosition(window).x - 25, Mouse::getPosition(window).y - 25));
									totalSun -= 175;
								}
								else if (selectedSeed == 6 && totalSun >= 200) {
									pvz.getGrid().getTile(x, y).addPlant(pvz.getLevel().getPlantFactory().createPlant("repeaterShooter", Mouse::getPosition(window).x - 25, Mouse::getPosition(window).y - 25));
									totalSun -= 200;
								}
								clicked = false;
								cursor.setTexture(cursorTexture);
							}
						}
					}
					if (selectedSeed == 7) {
						// Check if the shovel is selected
						for (int i = 0; i < MAX_PLANTS; i++) {
							if (pvz.getLevel().getPlantFactory().getPlant(i) != nullptr) {
								// Check if the mouse position is within the bounds of the plant sprite
								if (pvz.getLevel().getPlantFactory().getPlant(i)->getSprite().getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y)) {
									// Call the use function of the shovel to remove the plant
									coordinates mousePoint;
									mousePoint.x = Mouse::getPosition(window).x;
									mousePoint.y = Mouse::getPosition(window).y;
									pvz.getLevel().getShovel().use(pvz.getGrid(), mousePoint, pvz.getLevel().getPlantFactory());
								}
							}
						}
					}
					pvz.getLevel().getSunFactory().isSunClicked(Mouse::getPosition(window).x, Mouse::getPosition(window).y);
				}
			}
		}

		// Get mouse position
		Vector2i mousePosition = Mouse::getPosition(window);


		pvz.getState()->update(pvz, window);

		cursor.setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)));

		window.draw(cursor);

		//window.setSize(sf::Vector2u(1170, 604.5));
		window.display();
	}
	return 0;
}
