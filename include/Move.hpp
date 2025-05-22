#ifndef MOVE_HPP
#define MOVE_HPP
#include <utility>
using namespace std;

class Player; 

class Move
{
private:
    const Player *player;
    pair<int, int> position;
public:
    Move(Player *player ,int row, int column);
    ~Move();

    pair<int, int> getPosition() const;
    const Player* getplayer() const;
};



#endif
