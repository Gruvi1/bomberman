#pragma once

#include "abstract_object.h"


class TBox: public IGameObject {
private:
    int hp = 1;
    const int BoxCode = 177;

public:
    TBox(const int& y, const int& x);
    int GetX() const override;
    int GetY() const override;
    bool IsAlive() const override;
    void ReduceHp() override;
    void Update() override;
    void Display() override;
};