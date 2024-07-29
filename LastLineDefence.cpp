#include "LastLineDefence.h"

LastLineDefence::LastLineDefence() {
    for (int i = 0; i < ROWS; i++) {
        lawnMowers[i] = false;
        poolCleaners[i] = false;
        roofCleaners[i] = false;
    }
}
