#pragma once

#include "abstract_bomb.h"
#include "abstract_object.h"
#include "bomb_factory.h"
#include "box.h"
#include "game_field.h"
#include "player.h"
#include "storage.h"
#include "unbreakable_block.h"


class TGame {
private:
    TStorage storage;
    std::unique_ptr<TField> field;
    std::unique_ptr<TPlayer> player;

public:
    TGame();
    ~TGame();
    void Update(const int& symbol);
    void Display();
    void Game();

private:
    void InitField();
    void UpdateBombs();
    void UpdateObjects();
    void DisplayBombs();
    void DisplayObjects();
    bool IsCollision(const IGameObject* objectOne, const IGameObject* objectTwo);
    void CheckCollisions(const int& symbol);
    void MovePlayerBack(const int& symbol);
    void BombExplosion(const IGameObject* bomb);
    void DisplayStatistics();
    void DisplayEndGame();
};