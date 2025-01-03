#include "shard.h"


TShard::TShard(const int& x, const int& y) {
    realPosition.x = x;
    realPosition.y = y;
}

int TShard::GetX() const {
    if (lifeTime <= 10) {
        return realPosition.x;
    }
    return position.x;
}

int TShard::GetY() const {
    if (lifeTime <= 10) {
        return realPosition.y;
    }
    return position.y;
}

bool TShard::IsAlive() const {
    return lifeTime != 0;
}

void TShard::Update() {
    if (lifeTime > 0) {
        lifeTime--;
    }
}

void TShard::Display() {
    if (lifeTime <= 10) {
        init_pair(shardColor, COLOR_YELLOW, COLOR_BLACK);
        attron(COLOR_PAIR(shardColor));
        mvprintw(realPosition.y, realPosition.x, "%c", shardCode);
        attroff(COLOR_PAIR(shardColor));
    }
}
