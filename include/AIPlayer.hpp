#ifndef AIPLAYER_HPP
#define AIPLAYER_HPP
#include"Player.hpp"
#include"board.hpp"
#include"Move.hpp"

using namespace std;

class AIPlayer : public Player
{
public:
    AIPlayer();
    ~AIPlayer();

    
    void makeMove(const Move &move, Board &board)override;
    string toString() const override;

};


#endif
