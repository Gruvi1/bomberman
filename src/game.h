#pragma once

#include "abstract_object.h"
#include "game_field.h"
#include "unbreakable_block.h"
#include "box.h"
#include "player.h"

#include <vector>
#include <memory>


class TGame {
private:
    std::unique_ptr<TField> field;
    std::unique_ptr<TPlayer> player;
    std::vector<std::unique_ptr<IGameObject>> allObjects;

public:
    TGame();
    ~TGame();
    void InitGame();
    void DataCapture();
    void Update(int symbol);
    void Display();
    void Game();

private:
    void InitField();
};