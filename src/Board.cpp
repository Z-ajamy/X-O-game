#include"../include/Board.hpp"

Board::Board(int r, int c) : row(r), column(c), data(row, vector<char>(column, ' ')) {}

const vector<vector<char>> & Board::getdata() const
{
    return data;
}


void Board::setdata(int r, int cl, char c)
{
    data[r][cl] = c;
}

Board::~Board(){}
