#pragma once
#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
using namespace std;

class Player {
public:
	string name;
	int score;
	
	Player();
	~Player();
};

#endif // !PLAYER_H