#pragma once
#ifndef SCOREBOARD_H
#define SCOREBOARD_H
#include <string>

class Scoreboard {
protected:
    int score;
    std::string name;

public:
    Scoreboard(int score = 0, std::string name = "player 1");
};

#endif // !SCOREBOARD_H