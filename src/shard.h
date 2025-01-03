#pragma once

#include "abstract_bomb.h"


class TShard: public IBomb {
private:
    int lifeTime = 50;
    const int shardCode = 253;
    const int shardColor = 1;
    TPosition realPosition;

public:
    TShard(const int& x, const int& y);
    int GetX() const override;
    int GetY() const override;
    bool IsAlive() const override;
    void ReduceHp() override {};
    void Update() override;
    void Display() override;
};