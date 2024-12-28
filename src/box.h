#pragma once

#include "abstract_object.h"


class TBox: public IGameObject {
private:
    int hp = 1;
    TPosition position;
    const int BoxCode = 177;

public:
    TBox(int y, int x);
    // bool IsAlive();
    void Update() override {};
    void Display() override;

};