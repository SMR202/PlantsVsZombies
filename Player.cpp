#include "Player.h"
#include <fstream>
#include <string>

Player::Player() {

    cout<<"Enter your name: ";
	string inputName;
	cin >> inputName;

    std::ifstream file("player_data.txt");
    std::string line;

    int score = 0;
    int currentLine = 0;
    int fileLines = 0;

    if (file.is_open()) {
        while (std::getline(file, line)) {
            if (currentLine % 2 == 0) {
                if (line == inputName) {
                    this->name = inputName;
                    cout<<"Welcome back, " << this->name << "!" << endl;
                }
			}
			else if (currentLine % 2 == 1 && this->name == inputName) {
				score = std::stoi(line);
                break;
			}
            currentLine++;
        }
        file.close();
    }
    else {
        std::cout << "Error: Unable to open file.\n";
    }

	this->name = inputName;
    this->score = score;

    cout<< "Your current score is: " << this->score << endl;
    
}

Player::~Player() {
	std::ofstream file("player_data.txt", ios::app);
    if (file.is_open()) {
		file << this->name << std::endl;
		file << this->score << std::endl;
		file.close();
        cout<<"Player data saved successfully."<<endl;
	}
    else {
		std::cout << "Error: Unable to open file.\n";
	}
}