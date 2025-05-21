#ifndef MOVE_HPP
#define MOVE_HPP

class Player; 

class Move
{
private:
    const Player *player;
    pair<int, int> position({-1, -1});
public:
    Move(Player *player ,int row, int column);
    ~Move();

    pair<int, int> getPosition() const;
    const Player* getplayer() const;
};



#endif
