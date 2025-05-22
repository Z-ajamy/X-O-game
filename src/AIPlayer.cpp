#include"../include/AIPlayer.hpp"


AIPlayer::AIPlayer(const string &n, const string &t, int w, int l, int p, char s) :
Player(n, t, w, l, p, s){}


void AIPlayer::makeMove(const Move &move, Board &board)
{
    for (int i = 0; i < board.getRowCount(); i++)
    {
        for (int j = 0; j < board.getColCount(); j++)
        {
            if (board.isCellEmpty(i, j))
            {
                move.setPosition(std::make_pair(i, j));
                move.setPlayer(this);
                board.setdata(i, j, getSymbol());
                return;
            }
        }
    }
}
string AIPlayer::toString() const
{
    ostringstream out;

    out << "Name: " << name << "\n"
        << "Type: " << type << "\n"
        << "Symbol: " << symbol << "\n"
        << "Level: " << level;

    return out.str();
}

AIPlayer::~AIPlayer(){}
