#include "game.hpp"


game::game(char sign1, char sign2)
    : round_(1), player1_(sign1, 1), player2_(sign2, 2)
{
    //Initalizing map to underscrores
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            gameMap_[i][j] = '_';
        }
    }

}

void game::printmap()
{

    std::cout << "=============" << std::endl;
    
    for(int i = 0; i < 3; i++){
        std::cout << "|" << std::setw(2) << gameMap_[i][0] << std::setw(2) <<  "|" << std::setw(2) << gameMap_[i][1] << std::setw(2) << "|" 
        << std::setw(2) << gameMap_[i][2] << std::setw(2) << "|" << std::endl;
        if(i < 2)
            std::cout << std::endl;
    }    
    std::cout << "=============" << std::endl;

}

bool game::isNextMovePoss(const position& pos)
{
    if(pos.poX > 3 || pos.poX <= 0 || pos.posY > 3 || pos.posY <= 0 || gameMap_[pos.posY-1][pos.poX-1]  == player1_.getSign() || gameMap_[pos.posY-1][pos.poX-1] == player2_.getSign())
        return false;
    else
        return true;
}

void game::playNextMovePlayer1()
{
    position pos = player1_.nextMove();
    
    if(isNextMovePoss(pos))
    {

        gameMap_[pos.posY - 1][pos.poX - 1] = player1_.getSign();

    } else{
        while (!isNextMovePoss(pos))
        {
            std::cout << "Error, enter another set of coordiantes: ", std::cin >> pos.posY >> pos.poX;
        }
        
    }
}

void game::playNextMovePlayer2()
{
    position pos = player2_.nextMove();
    
    if(isNextMovePoss(pos))
    {

        gameMap_[pos.posY - 1][pos.poX - 1] = player2_.getSign();

    } else{
        while (!isNextMovePoss(pos))
        {
            std::cout << "Error, enter another set of coordiantes: ", std::cin >> pos.posY >> pos.poX;
        }
        
    }
}

bool game::isgamewon()
{
    if((gameMap_[0][0] == gameMap_[0][1]) && (gameMap_[0][0] == gameMap_[0][2]) && (gameMap_[0][0] != '_' )) //First line across
        return true;
    else if( (gameMap_[1][0] == gameMap_[1][1]) && (gameMap_[1][0] == gameMap_[1][2]) && (gameMap_[1][0] != '_' )) //Second line across
        return true;
    else if( (gameMap_[2][0] == gameMap_[2][1]) && (gameMap_[2][0] == gameMap_[2][2]) && (gameMap_[2][0] != '_' )) //Third line across
        return true;
    else if((gameMap_[0][0] == gameMap_[1][0]) && (gameMap_[0][0] == gameMap_[2][0]) && (gameMap_[0][0] != '_' )) // first line down
        return true;
    else if((gameMap_[0][1] == gameMap_[1][1]) && (gameMap_[0][1] == gameMap_[2][1]) && (gameMap_[0][1] != '_' )) // Second line down
        return true;
    else if( (gameMap_[0][2] == gameMap_[1][2]) && (gameMap_[0][2] == gameMap_[2][2]) && (gameMap_[0][2] != '_' )) //Third right down
        return true;
    else if ((gameMap_[0][0] == gameMap_[1][1]) && (gameMap_[0][0] == gameMap_[2][2]) && (gameMap_[0][0] != '_' )) // diagonal right
        return true;
    else if ((gameMap_[0][2] == gameMap_[1][1]) && (gameMap_[0][2] == gameMap_[2][0]) && (gameMap_[0][2] != '_' )) // diagonal left
        return true;

    return false;

}

int game::getRound() const
{
    return round_;
}

void game::incrementRound()
{
    std::cout << "------------------------------------------" << std::endl;
    round_++;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout  << "-----------------" << "Round " << round_ << "-----------------" << std::endl;

}

void game::endGame()
{

    std::cout << "Game ended, ";
    if(player1_.getPlayerNum() && round_ < 5)
        std::cout << "Player 1 won the game in " << round_ - 1 << " rounds!!!!" << std::endl;
    else if(player2_.getPlayerNum() == 0)
        std::cout << "Player 2 won the game in " << round_ - 1  << " rounds!!!!" << std::endl;
    else if (round_ == 5) std::cout << "in a tie" << std::endl;

}

void game::run()
{
    std::cout  << "-----------------" << "Round " << 1 << "-----------------" << std::endl;

    while (!isgamewon())
    {
        playNextMovePlayer1();
        printmap();
        if(isgamewon()) break;
        playNextMovePlayer2();
        printmap();
        incrementRound();
    }

    endGame();
    
}
