#include"../include/Move.hpp"


Move::Move(Player *p, int r, int cl) : player(p), position(r, cl) {}

pair<int, int> Move::getPosition() const
{
    return position;
}

const Player* Move::getplayer() const
{
    return player;
}

Move::~Move(){}
