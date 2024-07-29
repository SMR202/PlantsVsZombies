#pragma once
#ifndef BEGINNERSGARDEN_H
#define BEGINNERSGARDEN_H

#include "Levels.h"

class BeginnersGarden : public Levels {
protected:

public:
    BeginnersGarden(int& score);
	void loadLevelInfo();
	virtual ~BeginnersGarden();
};

#endif // !BEGINNERSGARDEN_H