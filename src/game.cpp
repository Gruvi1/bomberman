#include "bomberman/game.h"


TGame::TGame() {
    setlocale(LC_ALL, "rus");
    initscr();
    cbreak();
    noecho();
    curs_set(0);
    timeout(50);
    start_color();

    InitField();
    player = std::make_unique<TPlayer>(field.get()->GetMaxX() / 2, field.get()->GetMaxY() / 2,
                storage, field.get()->GetMaxX(), field.get()->GetMaxY());
}

TGame::~TGame() {
    endwin();
}

void TGame::Update(const int& symbol) {
    if (player.get()->IsAlive() == 0) {
        DisplayEndGame();
        exit(0);
    }
    player->Update(symbol, storage, field.get()->GetMaxX());
    UpdateBombs();
    CheckCollisions(symbol);
    UpdateObjects();
}

void TGame::Display() {
    field->Display();
    player->Display();
    DisplayObjects();
    DisplayBombs();
    DisplayStatistics();
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

void TGame::InitField() {
    field = std::make_unique<TField>(stdscr);

    for (int i = 3; i <= field.get()->GetMaxX() - 3; i += 6) {
        for (int j = 2; j <= field.get()->GetMaxY() - 2; j += 3) {
            storage.AddObject(std::make_unique<TUnbreakableBlock>(i, j));
            storage.AddObject(std::make_unique<TUnbreakableBlock>(i + 1, j));

            if (i % 4 == 1) {
            storage.AddObject(std::make_unique<TBox>(i - 1, j));
            storage.AddObject(std::make_unique<TBox>(i - 2, j));
            storage.AddObject(std::make_unique<TBox>(i, j + 1));
            storage.AddObject(std::make_unique<TBox>(i + 1, j + 1));
            storage.AddObject(std::make_unique<TBox>(i + 2, j));
            storage.AddObject(std::make_unique<TBox>(i + 3, j));
            storage.AddObject(std::make_unique<TBox>(i, j - 1));
            storage.AddObject(std::make_unique<TBox>(i + 1, j - 1));
            }
        }
    }
}

void TGame::UpdateBombs() {
    for (auto& bomb : storage.GetBombs()) {
        bomb->Update();
        if (!bomb->IsAlive()) {
            BombExplosion(bomb.get());
        }
    }
}

void TGame::UpdateObjects() {
    for (auto& object : storage.GetObjects()) {
        object->Update();
    }
}

void TGame::DisplayBombs() {
    for (size_t i = 0; i != storage.GetBombs().size(); ++i) {
        if (storage.GetBombs()[i].get()->IsAlive() == 0) {
            storage.GetBombs().erase(storage.GetBombs().begin() + i);
            i -= 1;
        }
        else {
            storage.GetBombs()[i].get()->Display();
        }
    }
}

void TGame::DisplayObjects() {
    for (size_t i = 0; i != storage.GetObjects().size(); ++i) {
        if (storage.GetObjects()[i].get()->IsAlive() == 0) {
            storage.GetObjects().erase(storage.GetObjects().begin() + i);
            i -= 1;
        }
        else {
            storage.GetObjects()[i].get()->Display();
        }
    }
}

bool TGame::IsCollision(const IGameObject* objectOne, const IGameObject* objectTwo) {
    return objectOne->GetX() == objectTwo->GetX() && objectOne->GetY() == objectTwo->GetY();
}

void TGame::CheckCollisions(const int& symbol) {
    for (auto& object : storage.GetObjects()) {
        if (IsCollision(player.get(), object.get())) {
            MovePlayerBack(symbol);
        }
    }
}

void TGame::MovePlayerBack(const int& symbol) {
    switch (symbol) {
        case 'w':
            player->Update('s', storage, field.get()->GetMaxX());
            break;
        case 's':
            player->Update('w', storage, field.get()->GetMaxX());
            break;
        case 'a':
            player->Update('d', storage, field.get()->GetMaxX());
            break;
        case 'd':
            player->Update('a', storage, field.get()->GetMaxX());
            break;
        default:
            break;
    }
}

void TGame::BombExplosion(const IGameObject* bomb) {
    if (IsCollision(bomb, player.get())) {
        player->ReduceHp();
    }
    for (auto& object : storage.GetObjects()) {
        if (IsCollision(bomb, object.get())) {
            object->ReduceHp();
        }
    }
}

void TGame::DisplayStatistics() {
    mvprintw(2, field.get()->GetMaxX() + 2, "HP: %d", player.get()->GetHp());
}

void TGame::DisplayEndGame() {
    clear();
    mvprintw(field.get()->GetMaxY() / 2, field.get()->GetMaxX() / 2, "Game over. Press 'q' to exit");
    refresh();
    while (getch() != 'q') {}
}