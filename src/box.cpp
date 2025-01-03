#include "box.h"


TBox::TBox(const int& x, const int& y) {
    position.x = x;
    position.y = y;
}

int TBox::GetX() const {
    return position.x;
}

int TBox::GetY() const {
    return position.y;
}

bool TBox::IsAlive() const {
    return hp != 0;
}

void TBox::ReduceHp() {
    hp -= 1;
}

void TBox::Update() {
}

void TBox::Display() {
    if (hp == 1) {
        mvprintw(position.y, position.x, "%c", BoxCode);
    }
}