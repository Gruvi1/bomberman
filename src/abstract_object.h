#pragma once

#include "curses.h"
#include <iostream>


class IGameObject {
protected:
    struct TPosition {
        int x = 0;
        int y = 0;
    } position;

public:
    virtual ~IGameObject() = default;
    virtual int GetX() const = 0;
    virtual int GetY() const = 0;
    virtual bool IsAlive() const = 0;
    virtual void ReduceHp() = 0;
    virtual void Update() = 0;
    virtual void Display() = 0;
};