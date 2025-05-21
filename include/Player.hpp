#ifndef PLAYER_H
#define PLAYER_H
#include <string>

using namespace std;

class Board;

class Player
{
private:
    string name;
    string type;
    int num_win;
    int num_lose;
    int num_played;
    char symbol;
    int level = 1;
    int consecutiveWins = 0;
public:
    Player(string n, string t, int w, int l, int p, char s);
    virtual ~Player();

    virtual void makeMove(Board&) = 0;
    
    // Getters
    string getName() const;
    string getType() const;
    int getNumWin() const;
    int getNumLose() const;
    int getNumPlayed() const;
    char getSymbol() const;
    int getlevel() const;

    // Setters
    void setName(const string& newName);
    void setType(const string& newType);
    void setSymbol(char s);

    void updateStats(bool win);
    void resetProgress();

};


#endif
