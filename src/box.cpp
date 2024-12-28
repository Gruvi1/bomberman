#include "box.h"


TBox::TBox(int x, int y) : position({x, y}) {}

void TBox::Display() {
    if (hp == 1) {
        mvprintw(position.y, position.x, "%c", BoxCode);
    }
}