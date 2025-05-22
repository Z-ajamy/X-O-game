#include"../include/HumanPlayer.hpp"


HumanPlayer ::HumanPlayer (const string &n, const string &t, int w, int l, int p, char s) :
Player(n, t, w, l, p, s) {}

void HumanPlayer::makeMove(const Move &move, Board &board) 
{
    if (move.getplayer() != this)
        throw std::invalid_argument("Move does not belong to this player.");

    board.setdata(move.getPosition().first, move.getPosition().second, this->symbol);
}

string HumanPlayer::toString() const 
{
    ostringstream out;

    out << "Name: " << name << "\n"
        << "Type: " << type << "\n"
        << "Symbol: " << symbol << "\n"
        << "Games Played: " << num_played << "\n"
        << "Wins: " << num_win << "\n"
        << "Losses: " << num_lose;

    return out.str();
}

HumanPlayer ::~HumanPlayer (){}
