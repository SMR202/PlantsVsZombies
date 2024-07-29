#include "Waves.h"

Waves::Waves(int waveNumber, int totalWaves) : waveNumber(waveNumber), totalWaves(totalWaves) {}

void Waves::startNextWave() {
    // Implement logic for starting the next wave
}

int Waves::getCurrentWave() {
    return waveNumber;
}

int Waves::getTotalWaves() {
    return totalWaves;
}

void Waves::setCurrentWave(int newWave) {
    waveNumber = newWave;
}

void Waves::setTotalWave(int newTotalWaves) {
    totalWaves = newTotalWaves;
}
