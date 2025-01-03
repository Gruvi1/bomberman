#pragma once

#include "abstract_bomb.h"


class TLineBomb: public IBomb {
private:
    int lifeTime = 50;
    const int bombCode = 253;
    const int bombColor = 1;

public:
    TLineBomb(const int& x, const int& y);
    int GetX() const override;
    int GetY() const override;
    bool IsAlive() const override;
    void ReduceHp() override {};
    void Update() override;
    void Display() override;
};