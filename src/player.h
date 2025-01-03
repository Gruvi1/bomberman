#pragma once

#include "abstract_object.h"
#include "abstract_bomb.h"
#include "bomb_factory.h"
#include "storage.h"


class TPlayer: public IGameObject {
private:
    int hp = 3;
    const int maxX;
    const int maxY;
    const int playerCode = 87;
    std::unique_ptr<TBombFactory> bombFactory;

public:
    TPlayer(const int& y, const int& x, TStorage& storage, const int& maxX, const int& maxY);
    int GetX() const override;
    int GetY() const override;
    bool IsAlive() const override;
    void ReduceHp() override;
    void Update() override {};
    void Update(const int& symbol, TStorage& storage, const int& lineX);
    void Display() override;
    int GetHp() const;

private:
    void Move(const int& symbol);
    void SpawnBomb(const int& symbol, TStorage& storage);
};