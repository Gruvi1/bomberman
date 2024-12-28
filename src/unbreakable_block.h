#pragma once

#include "abstract_object.h"


class TUnbreakableBlock: public IGameObject {
private:
    TPosition position;
    const int unbreakableBlockCode = 219;

public:
    TUnbreakableBlock(int x, int y);
    void Update() override {};
    void Display() override;
};