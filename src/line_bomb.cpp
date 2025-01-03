#include "line_bomb.h"


TLineBomb::TLineBomb(const int& x, const int& y) {
    position.x = x;
    position.y = y;
}

int TLineBomb::GetX() const {
    return position.x;
}

int TLineBomb::GetY() const {
    return position.y;
}

bool TLineBomb::IsAlive() const {
    return lifeTime != 0;
}

void TLineBomb::Update() {
    if (lifeTime > 0) {
     lifeTime--;
    }
}

void TLineBomb::Display() {
    init_pair(bombColor, COLOR_RED, COLOR_BLACK);
    attron(COLOR_PAIR(bombColor));
    mvprintw(position.y, position.x, "%c", bombCode);
    attroff(COLOR_PAIR(bombColor));
}