#include "SeedSprites.h"

Seeds::Seeds() {
	peaShooterSeedTexture.loadFromFile("Images/peashooter seed.png");
	sunflowerSeedTexture.loadFromFile("Images/sunflower seed.png");
	cherryBombSeedTexture.loadFromFile("Images/cherrybomb seed.png");
	walnutSeedTexture.loadFromFile("Images/walnut seed.png");
	snowPeaSeedTexture.loadFromFile("Images/snowpea seed.png");
	repeaterSeedTexture.loadFromFile("Images/repeater seed.png");
	shovelSeedTexture.loadFromFile("Images/shovel4.png");
	cursorTexture.loadFromFile("Images/cursor2.png");

	peaShooterCursorTexture.loadFromFile("Images/peashootercursor.png");
	sunflowerCursorTexture.loadFromFile("Images/sunflowercursor.png");
	cherryBombCursorTexture.loadFromFile("Images/cherrybombcursor.png");
	walnutCursorTexture.loadFromFile("Images/walnutcursor.png");
	snowPeaCursorTexture.loadFromFile("Images/snowpeacursor.png");
	repeaterCursorTexture.loadFromFile("Images/repeatercursor.png");
	shovelCursorTexture.loadFromFile("Images/shovel4.png");


	peaShooterSeedSprite.setTexture(peaShooterSeedTexture);
	sunflowerSeedSprite.setTexture(sunflowerSeedTexture);
	cherryBombSeedSprite.setTexture(cherryBombSeedTexture);
	walnutSeedSprite.setTexture(walnutSeedTexture);
	snowPeaSeedSprite.setTexture(snowPeaSeedTexture);
	repeaterSeedSprite.setTexture(repeaterSeedTexture);
	shovelSeedSprite.setTexture(shovelSeedTexture);
	cursorSprite.setTexture(cursorTexture);

	peaShooterSeedSprite.setPosition(20, 13);
	sunflowerSeedSprite.setPosition(90, 13);
	cherryBombSeedSprite.setPosition(160, 13);
	walnutSeedSprite.setPosition(230, 13);
	snowPeaSeedSprite.setPosition(300, 13);
	repeaterSeedSprite.setPosition(370, 13);
	shovelSeedSprite.setPosition(450, 13);

	peaShooterSeedSprite.setScale(0.65f, 0.65f);
	sunflowerSeedSprite.setScale(0.65f, 0.65f);
	cherryBombSeedSprite.setScale(0.65f, 0.65f);
	walnutSeedSprite.setScale(0.65f, 0.65f);
	snowPeaSeedSprite.setScale(0.65f, 0.65f);
	repeaterSeedSprite.setScale(0.65f, 0.65f);
	shovelSeedSprite.setScale(0.5f, 0.5f);
	cursorSprite.setScale(0.5f, 0.5f);

	defaultColor = peaShooterSeedSprite.getColor();
	lockedColor = Color(128, 128, 128);
}

Sprite Seeds::updateCursorSprite(RenderWindow& window, bool& clicked, int& selectedSeed, Event& event, int& totalSun) {
	cout << Mouse::getPosition(window).x << " , " << Mouse::getPosition(window).y << "  ";

	if (Mouse::getPosition(window).x >= 20 && Mouse::getPosition(window).x <= 90 && Mouse::getPosition(window).y >= 13 && Mouse::getPosition(window).y <= 79 && totalSun >=100) {
		clicked = true;
		selectedSeed = 1;
		cursorSprite.setTexture(peaShooterCursorTexture);
	}
	else if (Mouse::getPosition(window).x >= 90 && Mouse::getPosition(window).x <= 160 && Mouse::getPosition(window).y >= 13 && Mouse::getPosition(window).y <= 79 && totalSun >= 100) {
		clicked = true;
		selectedSeed = 2;
		cursorSprite.setTexture(sunflowerCursorTexture);
	}
	else if (Mouse::getPosition(window).x >= 160 && Mouse::getPosition(window).x <= 230 && Mouse::getPosition(window).y >= 13 && Mouse::getPosition(window).y <= 79 && totalSun >= 150) {
		clicked = true;
		selectedSeed = 3;
		cursorSprite.setTexture(cherryBombCursorTexture);
	}
	else if (Mouse::getPosition(window).x >= 230 && Mouse::getPosition(window).x <= 300 && Mouse::getPosition(window).y >= 13 && Mouse::getPosition(window).y <= 79 && totalSun >= 50) {
		clicked = true;
		selectedSeed = 4;
		cursorSprite.setTexture(walnutCursorTexture);
	}
	else if (Mouse::getPosition(window).x >= 300 && Mouse::getPosition(window).x <= 370 && Mouse::getPosition(window).y >= 13 && Mouse::getPosition(window).y <= 79 && totalSun >= 175) {
		clicked = true;
		selectedSeed = 5;
		cursorSprite.setTexture(snowPeaCursorTexture);
	}
	else if (Mouse::getPosition(window).x >= 370 && Mouse::getPosition(window).x <= 450 && Mouse::getPosition(window).y >= 13 && Mouse::getPosition(window).y <= 79 && totalSun >= 200) {
		clicked = true;
		selectedSeed = 6;
		cursorSprite.setTexture(repeaterCursorTexture);
	}
	else if (Mouse::getPosition(window).x >= 450 && Mouse::getPosition(window).x <= 520 && Mouse::getPosition(window).y >= 13 && Mouse::getPosition(window).y <= 79) {
		clicked = true;
		selectedSeed = 7;
		cursorSprite.setTexture(shovelCursorTexture);
		cursorSprite.setOrigin(0, cursorSprite.getTexture()->getSize().y);
	}
	else {
		cursorSprite.setTexture(cursorTexture);
		cursorSprite.setOrigin(0, 0);
	}
	if (selectedSeed != 7) {
		cursorSprite.setOrigin(0, 0);
	}
	cursorSprite.setScale(0.5f, 0.5f);
	return cursorSprite;
}

void Seeds::drawSeeds(RenderWindow& window) {
	window.draw(peaShooterSeedSprite);
	window.draw(sunflowerSeedSprite);
	window.draw(cherryBombSeedSprite);
	window.draw(walnutSeedSprite);
	window.draw(snowPeaSeedSprite);
	window.draw(repeaterSeedSprite);
	window.draw(shovelSeedSprite);
}

void Seeds::checkSeedAvailability(int totalSun) {
	if (totalSun < 100) {
		peaShooterSeedSprite.setColor(Color(128, 128, 128));
	}
	else {
		peaShooterSeedSprite.setColor(defaultColor);
	}
	if (totalSun < 100) {
		sunflowerSeedSprite.setColor(Color(128, 128, 128));
	}
	else {
		sunflowerSeedSprite.setColor(defaultColor);
	}
	if (totalSun < 150) {
		cherryBombSeedSprite.setColor(Color(128, 128, 128));
	}
	else {
		cherryBombSeedSprite.setColor(defaultColor);
	}
	if (totalSun < 50) {
		walnutSeedSprite.setColor(Color(128, 128, 128));
	}
	else {
		walnutSeedSprite.setColor(defaultColor);
	}
	if (totalSun < 175) {
		snowPeaSeedSprite.setColor(Color(128, 128, 128));
	}
	else {
		snowPeaSeedSprite.setColor(defaultColor);
	}
	if (totalSun < 200) {
		repeaterSeedSprite.setColor(Color(128, 128, 128));
	}
	else {
		repeaterSeedSprite.setColor(defaultColor);
	}
}