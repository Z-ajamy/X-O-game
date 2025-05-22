#ifndef HUMAN_HPP
#define HUMAN_HPP

#include "Player.hpp"
#include "Move.hpp"
#include "Board.hpp"
#include <sstream>
#include <string>
#include <stdexcept>

using namespace std;


class HumanPlayer : public Player
{
public:
    HumanPlayer (const string &n, const string &t, int w, int l, int p, char s);
    ~HumanPlayer ();

    void makeMove(const Move &move, Board &board) override;
    string toString() const override;
};



#endif
