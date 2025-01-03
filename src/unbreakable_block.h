#pragma once

#include "abstract_object.h"


class TUnbreakableBlock: public IGameObject {
private:
    const int unbreakableBlockCode = 219;
public:
    TUnbreakableBlock(const int& x, const int& y);
    int GetX() const override;
    int GetY() const override;
    bool IsAlive() const override {return 1;};
    void ReduceHp() override {};
    void Update() override {};
    void Display() override;
};