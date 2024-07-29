#pragma once
#ifndef GAME_H
#define GAME_H

#include "Scoreboard.h"
#include "Levels.h"
#include "Grid.h"
#include "State.h"
#include "Player.h"

class Game {
protected:
    string currentState;
    Scoreboard scoreboard;
    Levels* levels;
    Grid grid;
    State* state;
    Player player;

public:
    Game();
    void startGame();
    void beginLevel();
    Levels& getLevel();
    void setLevel(Levels& level);
    void setScoreboard(Scoreboard& scoreboard);
    Scoreboard getScoreboard();
    Grid& getGrid();
    virtual ~Game();
    void setState(State* state);
    State*& getState();
    void restartLevel();
};

#endif // !GAME_H