#include "game.h"


TGame::TGame() {}

TGame::~TGame() {
    endwin();
}

void TGame::InitGame() {
    setlocale(LC_ALL, "rus");
    initscr(); // иниц поле
    cbreak(); // убираем буферизацию. Нажатия сразу выводятся
    noecho(); // символы не отображаются
    curs_set(0); // не отображать курсор
    keypad(stdscr, TRUE); // включить стрелочки
    timeout(50);
    start_color();
    const int main_color_pair = 1;
    const int player_color_pair = 2;
    const int bullet_color_pair = 3;
    // colors are COLOR_BLACK, COLOR_RED, COLOR_GREEN, COLOR_YELLOW, COLOR_BLUE, COLOR_MAGENTA, COLOR_CYAN, COLOR_WHITE
    init_pair(main_color_pair, COLOR_WHITE, COLOR_BLACK);
    init_pair(player_color_pair, COLOR_YELLOW, COLOR_BLUE);
    init_pair(bullet_color_pair, COLOR_RED, COLOR_BLACK);

    InitField();
    player = std::make_unique<TPlayer>(field.get()->GetMaxX() / 2, field.get()->GetMaxY() / 2);
    std::cout << "Game started" << std::endl;
}

void TGame::Update(int symbol) {
    player->Update(symbol);
    for (auto& object : allObjects) {
        object->Update();
    }
}

void TGame::Display() {
    field->Display();
    player->Display();
    for (auto& object : allObjects) {
        object->Display();
    }
}

void TGame::InitField() {
    field = std::make_unique<TField>(stdscr);

    for (int i = 3; i <= field.get()->GetMaxX() - 3; i += 6) {
        for (int j = 2; j <= field.get()->GetMaxY() - 2; j += 3) {
            allObjects.push_back(std::make_unique<TUnbreakableBlock>(i, j));
            allObjects.push_back(std::make_unique<TUnbreakableBlock>(i + 1, j));
            if (i % 4 == 1) {
                allObjects.push_back(std::make_unique<TBox>(i - 1, j));
                allObjects.push_back(std::make_unique<TBox>(i - 2, j));
                allObjects.push_back(std::make_unique<TBox>(i, j + 1));
                allObjects.push_back(std::make_unique<TBox>(i + 1, j + 1));
                allObjects.push_back(std::make_unique<TBox>(i + 2, j));
                allObjects.push_back(std::make_unique<TBox>(i + 3, j));
                allObjects.push_back(std::make_unique<TBox>(i, j - 1));
                allObjects.push_back(std::make_unique<TBox>(i + 1, j - 1));
            }
            else {
                allObjects.push_back(std::make_unique<TBox>(i - 1, j - 1));
                allObjects.push_back(std::make_unique<TBox>(i - 2, j - 1));
                allObjects.push_back(std::make_unique<TBox>(i - 1, j + 1));
                allObjects.push_back(std::make_unique<TBox>(i - 2, j + 1));
                allObjects.push_back(std::make_unique<TBox>(i + 2, j - 1));
                allObjects.push_back(std::make_unique<TBox>(i + 3, j - 1));
                allObjects.push_back(std::make_unique<TBox>(i + 2, j + 1));
                allObjects.push_back(std::make_unique<TBox>(i + 3, j + 1));
            }
        }
    }
}

void TGame::Game() {
    int symbol;
    while ((symbol = getch()) != 'q') {
        TGame::Update(symbol);
        clear();
        TGame::Display();

        refresh();
    }
}