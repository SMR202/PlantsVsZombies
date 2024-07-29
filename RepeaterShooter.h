#pragma once
#ifndef REPEATER_SHOOTER_H
#define REPEATER_SHOOTER_H

#include "Shooter.h"


class RepeaterShooter : public Shooter {
public:
    RepeaterShooter(int x = 0, int y = 0);
    virtual void attack(ZombieFactory& zombies) override;
    virtual ~RepeaterShooter();
};

#endif // REPEATER_SHOOTER_H