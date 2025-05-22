#include "../include/HumanPlayerTest.hpp"

void test_HumanPlayerToString() {
    HumanPlayer player("Abdo", "Human", 3, 1, 4, 'X');
    std::string description = player.toString();

    EXPECT_NE(description.find("Name: Abdo"), std::string::npos);
    EXPECT_NE(description.find("Type: Human"), std::string::npos);
    EXPECT_NE(description.find("Symbol: X"), std::string::npos);
    EXPECT_NE(description.find("Games Played: 4"), std::string::npos);
    EXPECT_NE(description.find("Wins: 3"), std::string::npos);
    EXPECT_NE(description.find("Losses: 1"), std::string::npos);
}

void test_HumanPlayerMakeMoveValid() {
    HumanPlayer player("Abdo", "Human", 0, 0, 0, 'X');
    DummyBoard board;
    Move move(&player, 1, 2);

    player.makeMove(move, board);

    auto &data = board.getdata();
    EXPECT_EQ(data[1][2], 'X');

}

void test_HumanPlayerMakeMoveInvalid() {
    HumanPlayer player1("P1", "Human", 0, 0, 0, 'X');
    HumanPlayer player2("P2", "Human", 0, 0, 0, 'O');
    DummyBoard board;
    Move move(&player2, 0, 0);

    EXPECT_THROW(player1.makeMove(move, board), std::invalid_argument);
}

TEST(HumanPlayerTestSuite, ToStringTest) {
    test_HumanPlayerToString();
}

TEST(HumanPlayerTestSuite, MakeMoveValidTest) {
    test_HumanPlayerMakeMoveValid();
}

TEST(HumanPlayerTestSuite, MakeMoveInvalidTest) {
    test_HumanPlayerMakeMoveInvalid();
}
