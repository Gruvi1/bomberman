#pragma once

#include "abstract_object.h"


class TField: public IGameObject {
private:
    int maxX = 0;
    int maxY = 0;
    WINDOW* win = nullptr;

    // IBM CP866
    const int upperLeftBorder = 201;
    const int upperRightBorder = 187;
    const int lowerLeftBorder = 200;
    const int lowerRightBorder = 188;
    const int horizontalBorder = 205;
    const int verticalBorder = 186;

public:
    TField (WINDOW* win);
    void Update() override {};
    void Display() override;
    int GetMaxX();
    int GetMaxY();
};
