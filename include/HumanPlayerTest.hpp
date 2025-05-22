#ifndef HUMAN_PLAYER_TEST_HPP
#define HUMAN_PLAYER_TEST_HPP

#include <gtest/gtest.h>
#include "../include/HumanPlayer.hpp"
#include "../include/Board.hpp"
#include "../include/Move.hpp"

class DummyBoard : public Board {
public:
    DummyBoard() : Board(3, 3) { }
    using Board::setdata;
    using Board::getdata;
};

void test_HumanPlayerToString();
void test_HumanPlayerMakeMoveValid();
void test_HumanPlayerMakeMoveInvalid();

#endif
