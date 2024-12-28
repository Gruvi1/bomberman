#include "player.h"


TPlayer::TPlayer(int x, int y) : position({x, y}) {}

void TPlayer::Display() {
    mvprintw(position.y, position.x, "%c", playerCode);
}

void TPlayer::Update() {}

void TPlayer::Update(int symbol) {
    TPlayer::Move(symbol);
}

void TPlayer::Move(int symbol) {
    switch (symbol) {
        case 'w':
            position.y--;
            break;
        case 's':
            position.y++;
            break;
        case 'a':
            position.x--;
            break;
        case 'd':
            position.x++;
            break;
        default:
            break;
    }
}