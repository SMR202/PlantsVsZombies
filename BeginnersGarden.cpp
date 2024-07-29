#include "BeginnersGarden.h"
#include <iostream>

BeginnersGarden::BeginnersGarden (int& score) : Levels(1,score) {
	loadLevelInfo();
}

void BeginnersGarden::loadLevelInfo() {
	name = "Beginner's Garden";
	description = "A simple garden to get you started.";
	objectives = "Plant at least 3 sunflowers.";
	challenges = "KILL ALL ZOMBIES";
	rewards = "10 ABSOLUTES";
	zombies[0] = "Simple Zombie";
	zombies[1] = "Flying Zombie";
	zombies[2] = "Football Zombie";

	cout<<name<<endl;
	cout<<description<<endl;
	cout<<objectives<<endl;
	cout<<challenges<<endl;
	cout<<rewards<<endl;
	cout<<zombies[0]<<endl;
	cout<<zombies[1]<<endl;
	cout<<zombies[2]<<endl;
	cout<<"Dancing Zombie"<<endl;
}

BeginnersGarden::~BeginnersGarden() {}