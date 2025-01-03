#include "player.h"


TPlayer::TPlayer(const int& x, const int& y, TStorage& storage, const int& maxX, const int& maxY) : maxX(maxX), maxY(maxY) {
    position.x = x;
    position.y = y;
    bombFactory = std::make_unique<TBombFactory>(storage, maxX, maxY);
}

int TPlayer::GetX() const {
    return position.x;
}

int TPlayer::GetY() const {
    return position.y;
}

bool TPlayer::IsAlive() const {
    return hp != 0;
}

void TPlayer::ReduceHp() {
    hp -= 1;
}

void TPlayer::Update(const int& symbol, TStorage& storage, const int& lineX) {
    TPlayer::Move(symbol);
    TPlayer::SpawnBomb(symbol, storage);
}

void TPlayer::Display() {
    mvprintw(position.y, position.x, "%c", playerCode);
}

int TPlayer::GetHp() const {
    return hp;
}

void TPlayer::Move(const int& symbol) {
    switch (symbol) {
        case 'w':
            if (position.y > 1) {
                position.y--;
            }
            break;
        case 's':
            if (position.y < maxY - 1) {
                position.y++;
            }
            break;
        case 'a':
            if (position.x > 1) {
                position.x--;
            }
            break;
        case 'd':
            if (position.x < maxX - 1) {
                position.x++;
            }
            break;
        default:
            break;
    }
}

void TPlayer::SpawnBomb(const int& symbol, TStorage& storage) {
    if (symbol == ' ') {
        bombFactory->MakeBomb("bomb", position.x, position.y);
    }
    else if (symbol == 'l') {
        bombFactory->MakeBomb("line", position.x, position.y);
    }
}