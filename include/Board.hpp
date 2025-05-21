#ifndef BOARD_HPP
#define BOARD_HPP

#include <iostream>
#include <vector>
using namespace std;

class Board
{
private:
    int row;
    int column;
    vector<vector<char>> data;

public:
    Board(int r, int c);
    ~Board();

    const vector<vector<char>>& getdata() const;
    char getCell(int r, int cl) const;

    void setdata(int r, int cl, char c);
    bool isCellEmpty(int r, int cl) const;
    bool isValidPosition(int r, int cl) const;
    bool isFull() const;

    void reset();
    void resizeBoard(int r, int cl);

    int getRowCount() const;
    int getColCount() const;
};

#endif
