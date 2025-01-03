#pragma once

#include "curses.h"
#include <iostream>
#include "abstract_object.h"

class IBomb : public IGameObject {
protected:
    struct TPosition {
        int x = 0;
        int y = 0;
    } position;

public:
    virtual ~IBomb() = default;
    virtual int GetX() const = 0;
    virtual int GetY() const = 0;
    virtual bool IsAlive() const = 0;
    virtual void ReduceHp() = 0;
    virtual void Update() = 0;
    virtual void Display() = 0;
};