#include "bomb_factory.h"


TBombFactory::TBombFactory(TStorage& storage, const int& maxX, const int& maxY) : storage(storage), maxX(maxX), maxY(maxY) {}

void TBombFactory::MakeBomb(std::string_view typeBomb, const int& x, const int& y) {
    if (typeBomb == "bomb") {
        storage.AddBomb(std::make_unique<TBomb>(x, y));
        storage.AddBomb(std::make_unique<TShard>(x - 1, y));
        storage.AddBomb(std::make_unique<TShard>(x, y - 1));
        storage.AddBomb(std::make_unique<TShard>(x + 1, y));
        storage.AddBomb(std::make_unique<TShard>(x, y + 1));
    }
    else if (typeBomb == "line") {
        storage.AddBomb(std::make_unique<TLineBomb>(x, y));
        for (size_t i = 1; i != maxX; ++i) {
            if (i == x) {
                continue;
            }
            storage.AddBomb(std::make_unique<TShard>(i, y));
        }
    }
}