#pragma once
#ifndef WAVES_H
#define WAVES_H
class Waves {
protected:
    int totalWaves;
    int waveNumber;

public:
    Waves(int waveNumber = 1, int totalWaves = 2);

    void startNextWave();
    int getCurrentWave();
    int getTotalWaves();
    void setCurrentWave(int newWave);
    void setTotalWave(int newTotalWaves);
};

#endif // WAVES_H