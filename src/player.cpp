#include "player.hpp"


player::player(char sign, int playerNum)
    :sign_(sign), playerNumber_(playerNum)
{
}

position player::nextMove()
{
    position pos;
    std::cout << "Player " << playerNumber_ << ", please enter coordinates ", std::cin >> pos.posY >> pos.poX;
    return {pos};

}

    
char player::getSign() const
{
    return sign_;
}

int player::getPlayerNum() const
{
    return playerNumber_;
}