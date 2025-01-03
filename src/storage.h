#pragma once


#include "abstract_object.h"
#include "abstract_bomb.h"

#include <vector>
#include <memory>

class TStorage {
private:
    std::vector<std::unique_ptr<IGameObject>> allObjects;
    std::vector<std::unique_ptr<IBomb>> allBombs;

public:
    void AddObject(std::unique_ptr<IGameObject> object);
    std::vector<std::unique_ptr<IGameObject>>& GetObjects();
    void AddBomb(std::unique_ptr<IBomb> bomb);
    std::vector<std::unique_ptr<IBomb>>& GetBombs();
};