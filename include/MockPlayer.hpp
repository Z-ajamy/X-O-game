#ifndef MOCKPLAYER_H
#define MOCKPLAYER_H

#include "Player.hpp"
#include "Board.hpp"

class MockPlayer : public Player {
public:
    MockPlayer(const std::string& n, const std::string& t, int w, int l, int p, char s)
        : Player(n, t, w, l, p, s) {}

        void makeMove(const Move &move, Board &board) override
        {
        // Mock implementation - do nothing
        }
    string toString() const {
        return "";
    }

};

#endif
