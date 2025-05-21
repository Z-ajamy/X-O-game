#include "../include/Board.hpp"

Board::Board(int r, int c) : row(r), column(c), data(row, vector<char>(column, ' ')) {}

const vector<vector<char>>& Board::getdata() const 
{
    return data;
}

vector<vector<char>> Board::getBoardSnapshot() const
{
    return data;
}

void Board::setdata(int r, int cl, char c) 
{
    if (r < 0 || r >= row || cl < 0 || cl >= column || (c != 'X' && c != 'O')) {
        throw invalid_argument("Invalid position or character. Must be 'X' or 'O' in a valid cell.");
    }
    data[r][cl] = c;
}

bool Board::isCellEmpty(int r, int cl) const 
{
    if (r < 0 || r >= row || cl < 0 || cl >= column) {
        throw invalid_argument("Invalid cell position.");
    }
    if (data[r][cl] == ' ')
    {
        return true;
    }
    
    return false;
}

bool Board::isValidPosition(int r, int cl) const 
{
    if (r >= 0 && r < row && cl >= 0 && cl < column)
    {
        return true;
    }
    return false;
}

void Board::reset() 
{
    for (int i = 0; i < row; ++i)
        for (int j = 0; j < column; ++j)
            data[i][j] = ' ';
}

void Board::resizeBoard(int r, int cl) 
{
    if (r <= 0 || cl <= 0) {
        throw invalid_argument("Board dimensions must be positive.");
    }
    row = r;
    column = cl;
    data = vector<vector<char>>(row, vector<char>(column, ' '));
}

char Board::getCell(int r, int cl) const 
{
    if (!isValidPosition(r, cl)) {
        throw invalid_argument("Invalid cell access.");
    }
    return data[r][cl];
}

bool Board::isFull() const 
{
    for (int i = 0; i < row; i++)
        for (int j = 0; j < column; j++)
            if (data[i][j] == ' ')
                return false;
    return true;
}

int Board::getRowCount() const 
{
    return row;
}

int Board::getColCount() const 
{
    return column;
}

vector<pair<int, int>> Board::getEmptyCells() const
{
    vector<pair<int, int>> empty;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            if (isCellEmpty(i, j))
            {
                empty.push_back({i, j});
            }
        }
    }
    return empty;
}

Board::~Board() {}
