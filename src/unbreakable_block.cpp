#include "unbreakable_block.h"


TUnbreakableBlock::TUnbreakableBlock(int x, int y) : position({x, y}) {}

void TUnbreakableBlock::Display() {
    mvprintw(position.y, position.x, "%c", unbreakableBlockCode);
}