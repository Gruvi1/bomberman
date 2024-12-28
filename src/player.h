#pragma once

#include "abstract_object.h"


class TPlayer: public IGameObject {
private:
    TPosition position;
    const int playerCode = 87;

public:
    TPlayer(int y, int x);
    void Update() override;
    void Update(int symbol);
    void Display() override;

private:
    void Move(int symbol);

};