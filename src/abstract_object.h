#pragma once

#include <iostream>
#include "curses.h"


class IGameObject {
protected:
    struct TPosition {
        int x;
        int y;
    };

public:
    virtual ~IGameObject() = default;
    virtual void Update() = 0;
    virtual void Display() = 0;
};