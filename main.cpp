#include <iostream>
#include <curses.h>
#include "game.h"


int main(int argc, char* argv[]) {
    TGame game;
    game.InitGame();
    game.Game();
    return 0;
}