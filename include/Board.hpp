#ifndef BOARD_HPP
#define BOARD_HPP
#include<iostream>
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

    const vector<vector<char>> & getdata() const;

    void setdata(int r, int cl, char c);
};

#endif
