#pragma once
#ifndef LASTLINEDEFENCE_H
#define LASTLINEDEFENCE_H
#include "Constants.h"

class LastLineDefence {
protected:
    bool lawnMowers[ROWS];
    bool poolCleaners[ROWS];
    bool roofCleaners[ROWS];

public:
    LastLineDefence();
};

#endif // !LASTLINEDEFENCE_H