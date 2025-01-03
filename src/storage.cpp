#include "storage.h"


void TStorage::AddObject(std::unique_ptr<IGameObject> object) {
    allObjects.push_back(std::move(object));
}

std::vector<std::unique_ptr<IGameObject>>& TStorage::GetObjects() {
    return allObjects;
}

void TStorage::AddBomb(std::unique_ptr<IBomb> bomb) {
    allBombs.push_back(std::move(bomb));
}

std::vector<std::unique_ptr<IBomb>>& TStorage::GetBombs() {
    return allBombs;
}
