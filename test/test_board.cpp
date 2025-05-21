#include "gtest/gtest.h"
#include "../include/Board.hpp"

TEST(BoardTest, InitializationCreatesEmptyBoard) {
    Board b(3, 3);
    EXPECT_EQ(b.getRowCount(), 3);
    EXPECT_EQ(b.getColCount(), 3);

    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            EXPECT_TRUE(b.isCellEmpty(i, j));
}

TEST(BoardTest, SetAndGetData) {
    Board b(3, 3);
    b.setdata(1, 1, 'X');
    EXPECT_EQ(b.getCell(1, 1), 'X');
    EXPECT_FALSE(b.isCellEmpty(1, 1));
}

TEST(BoardTest, SetDataInvalidPositionThrows) {
    Board b(3, 3);
    EXPECT_THROW(b.setdata(-1, 0, 'X'), invalid_argument);
    EXPECT_THROW(b.setdata(0, 3, 'O'), invalid_argument);
    EXPECT_THROW(b.setdata(0, 0, 'Z'), invalid_argument);
}

TEST(BoardTest, GetCellInvalidThrows) {
    Board b(3, 3);
    EXPECT_THROW(b.getCell(10, 10), invalid_argument);
}

TEST(BoardTest, IsCellEmptyCheck) {
    Board b(2, 2);
    b.setdata(0, 1, 'X');
    EXPECT_TRUE(b.isCellEmpty(0, 0));
    EXPECT_FALSE(b.isCellEmpty(0, 1));
}

TEST(BoardTest, GetEmptyCellsReturnsCorrectPositions) {
    Board b(2, 2);
    b.setdata(0, 0, 'X');
    b.setdata(1, 1, 'O');

    vector<pair<int, int>> expected = {{0, 1}, {1, 0}};
    vector<pair<int, int>> result = b.getEmptyCells();

    EXPECT_EQ(result.size(), 2);
    EXPECT_EQ(result, expected);
}

TEST(BoardTest, ResetClearsBoard) {
    Board b(3, 3);
    b.setdata(0, 0, 'X');
    b.setdata(1, 1, 'O');
    b.reset();

    for (int i = 0; i < b.getRowCount(); ++i)
        for (int j = 0; j < b.getColCount(); ++j)
            EXPECT_TRUE(b.isCellEmpty(i, j));
}

TEST(BoardTest, ResizeBoardWorksCorrectly) {
    Board b(2, 2);
    b.resizeBoard(4, 5);
    EXPECT_EQ(b.getRowCount(), 4);
    EXPECT_EQ(b.getColCount(), 5);

    for (int i = 0; i < b.getRowCount(); ++i)
        for (int j = 0; j < b.getColCount(); ++j)
            EXPECT_TRUE(b.isCellEmpty(i, j));
}

TEST(BoardTest, ResizeBoardInvalidThrows) {
    Board b(2, 2);
    EXPECT_THROW(b.resizeBoard(0, 5), invalid_argument);
    EXPECT_THROW(b.resizeBoard(3, -1), invalid_argument);
}

TEST(BoardTest, BoardIsFullDetection) {
    Board b(2, 2);
    b.setdata(0, 0, 'X');
    b.setdata(0, 1, 'O');
    b.setdata(1, 0, 'X');
    b.setdata(1, 1, 'O');

    EXPECT_TRUE(b.isFull());
}

TEST(BoardTest, BoardIsNotFull) {
    Board b(2, 2);
    b.setdata(0, 0, 'X');
    EXPECT_FALSE(b.isFull());
}

TEST(BoardTest, GetBoardSnapshotMatchesData) {
    Board b(2, 2);
    b.setdata(0, 0, 'X');
    b.setdata(1, 1, 'O');

    vector<vector<char>> snapshot = b.getBoardSnapshot();
    EXPECT_EQ(snapshot[0][0], 'X');
    EXPECT_EQ(snapshot[1][1], 'O');
    EXPECT_EQ(snapshot[0][1], ' ');
    EXPECT_EQ(snapshot[1][0], ' ');
}
