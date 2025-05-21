#include"../include/Player.hpp"


Player::Player(const string n, const string t, int w, int l, int p, char s) :
name(n), type(t), num_win(w), num_lose(l), num_played(p), symbol(s) {}

string Player::getName() const
{
    return name;
}

string Player::getType() const
{
    return type;
}

int Player::getNumWin() const
{
    return num_win;
}

int Player::getNumLose() const
{
    return num_lose;
}

int Player::getNumPlayed() const
{
    return num_played;
}

char Player::getSymbol() const
{
    return symbol;
}

int Player::getLevel() const
{
    return level;
}

int Player::getconsecutiveWins() const
{
    return consecutiveWins;
}

// ===== Setters =====
void Player::setName(const string& newName)
{
    name = newName;
}

void Player::setType(const string& newType)
{
    type = newType;
}

void Player::setSymbol(char s)
{
    symbol = s;
}

void Player::setLevel(int l)
{
    level = l;
}

void Player::updateStats(bool win)
{
    if (win)
    {
        num_win++;
        consecutiveWins++;
    }
    else
    {
        consecutiveWins = 0;
        num_lose++;
    }
    if (consecutiveWins == 3) 
    {
        consecutiveWins = 0;
        level++;
    }
    num_played++;
}

void Player::resetProgress()
{
    num_played = 0;
    num_win = 0;
    consecutiveWins = 0;
    level = 1; 
}

Player::~Player(){}
