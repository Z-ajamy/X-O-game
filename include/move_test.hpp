#ifndef MOVE_TEST_HPP
#define MOVE_TEST_HPP

#include <gtest/gtest.h>
#include "../include/Move.hpp"
#include "../include/Player.hpp"

class DummyPlayer : public Player {
public:
    DummyPlayer() : Player(name, type, 0, 0, 0, 'X') {}
    void makeMove(const Move &move, Board &board) override{}
    string toString() const {
        return "";
    }

private:
    static std::string name;
    static std::string type;
};

std::string DummyPlayer::name = "TestPlayer";
std::string DummyPlayer::type = "Human";

void movePositionTest();
void movePlayerTest();

#endif
