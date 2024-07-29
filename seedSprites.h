#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class Seeds {
protected:
    Texture peaShooterSeedTexture;
    Texture sunflowerSeedTexture;
    Texture cherryBombSeedTexture;
    Texture walnutSeedTexture;
    Texture snowPeaSeedTexture;
    Texture repeaterSeedTexture;
    Texture shovelSeedTexture;
    Texture cursorTexture;

    Texture peaShooterCursorTexture;
    Texture sunflowerCursorTexture;
    Texture cherryBombCursorTexture;
    Texture walnutCursorTexture;
    Texture snowPeaCursorTexture;
    Texture repeaterCursorTexture;
    Texture shovelCursorTexture;

    Sprite peaShooterSeedSprite;
    Sprite sunflowerSeedSprite;
    Sprite cherryBombSeedSprite;
    Sprite walnutSeedSprite;
    Sprite snowPeaSeedSprite;
    Sprite repeaterSeedSprite;
    Sprite shovelSeedSprite;
    Sprite cursorSprite;

    Color defaultColor;
    Color lockedColor;

public:
    Seeds();
    Sprite updateCursorSprite(RenderWindow& window, bool& clicked, int& selectedSeed, Event& event, int& totalSun);
    void drawSeeds(RenderWindow& window);
    void checkSeedAvailability(int totalSun);
};