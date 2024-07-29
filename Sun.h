#pragma once
#ifndef SUN_H
#define SUN_H
#include <SFML/Graphics.hpp>

class Sun {
private:
    sf::Clock moveClock, spriteClock;
    sf::Texture sunTexture;
    sf::IntRect sunRect;
    sf::Sprite sunSprite;
    bool isDeleting;
    int speed;

public:
    Sun();
    void moveSun();
    sf::Sprite& getSprite();
    sf::IntRect& getRect();
    void setSprite(sf::Sprite& sunsprite);
    bool getIsDeleting();
    void setIsDeleting(bool isDeleting);
    void setSpeed(int speed);
    int getSpeed();
    sf::Clock& getMoveClock();
    sf::Clock& getSpriteClock();

};

#endif // !SUN_H