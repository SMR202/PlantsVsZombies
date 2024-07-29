#include "Game.h"
#include "MenuState.h"
#include "BeginnersGarden.h"
#include <iostream>
#include <fstream>
Game::Game() : scoreboard(), state(nullptr), grid(), levels(new BeginnersGarden(player.score)), player() {

}

void Game::startGame() {
    // Implement logic
    state = new MenuState();
}

Levels& Game::getLevel() {
    return *levels;
}

void Game::setLevel(Levels& level) {
    levels = &level;
}

void Game::setScoreboard(Scoreboard& scoreboard) {
    this->scoreboard = scoreboard;
}

Scoreboard Game::getScoreboard() {
    return scoreboard;
}

Grid& Game::getGrid() {
    return grid;
}

Game::~Game() {
	delete state;
    delete levels;
    state = nullptr;
    levels = nullptr;
}
void Game::setState(State* state) {
    delete this->state;
	this->state = state;
}
State*& Game::getState() {
	return state;
}

void Game::restartLevel() {
    delete levels;
    levels = new BeginnersGarden(player.score);
}