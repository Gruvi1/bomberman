#include "bomb.h"


TBomb::TBomb(const int& x, const int& y) {
    position.x = x;
    position.y = y;
}

int TBomb::GetX() const {
    return position.x;
}

int TBomb::GetY() const {
    return position.y;
}

bool TBomb::IsAlive() const {
    return lifeTime != 0;
}

void TBomb::Update() {
    if (lifeTime > 0) {
        lifeTime -= 1;
    }
}

void TBomb::Display() {
    init_pair(bombColor, COLOR_RED, COLOR_BLACK);
    attron(COLOR_PAIR(bombColor));
    mvprintw(position.y, position.x, "%c", bombCode);
    attroff(COLOR_PAIR(bombColor));
}