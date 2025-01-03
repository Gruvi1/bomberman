#include "game_field.h"


TField::TField(WINDOW* win) : win(win) {
    getmaxyx(win, maxY, maxX);
    maxY -= 1;
    maxX -= 10;
}

int TField::GetMaxX() {
    return maxX;
}

int TField::GetMaxY() {
    return maxY;
}

void TField::Display() {
    mvwprintw(win, 0, 0, "%c", upperLeftBorder);
    mvwprintw(win, 0, maxX, "%c", upperRightBorder);
    mvwprintw(win, maxY, maxX, "%c", lowerRightBorder);
    mvwprintw(win, maxY, 0, "%c", lowerLeftBorder);

    for (size_t i = 1; i != maxX; ++i) {
        mvwprintw(win, 0, i, "%c", horizontalBorder);
        mvwprintw(win, maxY, i, "%c", horizontalBorder);
    }

    for (size_t i = 1; i != maxY; ++i) {
        mvwprintw(win, i, 0, "%c", verticalBorder);
        mvwprintw(win, i, maxX, "%c", verticalBorder);
    }
    wrefresh(win);
}