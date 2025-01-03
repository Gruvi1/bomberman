#pragma once

#include "bomb.h"
#include "line_bomb.h"
#include "shard.h"
#include "storage.h"

#include <string_view>
#include <memory>


class TBombFactory {
private:
    TStorage& storage;
    int maxX;
    int maxY;
public:
    TBombFactory(TStorage& storage, const int& maxX, const int& maxY);
    ~TBombFactory() = default;
    void MakeBomb(std::string_view bombType, const int& x, const int& y);
};