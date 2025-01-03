#include "unbreakable_block.h"


TUnbreakableBlock::TUnbreakableBlock(const int& x, const int& y) {
    position.x = x;
    position.y = y;
}

int TUnbreakableBlock::GetX() const {
    return position.x;
}

int TUnbreakableBlock::GetY() const {
    return position.y;
}

void TUnbreakableBlock::Display() {
    mvprintw(position.y, position.x, "%c", unbreakableBlockCode);
}
