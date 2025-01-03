#pragma once

#include "abstract_bomb.h"


class TBomb: public IBomb {
private:
    int lifeTime = 50;
    const int bombCode = 253;
    const int bombColor = 1;

public:
    TBomb(const int& x, const int& y);
    int GetX() const override;
    int GetY() const override;
    bool IsAlive() const override;
    void ReduceHp() override {};
    void Update() override;
    void Display() override;
};