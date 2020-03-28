#include "game.hpp"


game::game(char sign1, char sign2)
    : round_(0), spaceLeft_(9), winner_(0), player1_(sign1, 1), player2_(sign2, 2)
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

    while (!isNextMovePoss(pos))
    {
        pos = player1_.nextMoveMulTries();

    }
    
    
    gameMap_[pos.posY - 1][pos.poX - 1] = player1_.getSign();
    spaceLeft_--;

}

void game::playNextMovePlayer2()
{
    position pos = player2_.nextMove();

    while (!isNextMovePoss(pos))
    {
        pos = player2_.nextMoveMulTries();

    }
    
    gameMap_[pos.posY - 1][pos.poX - 1] = player2_.getSign();
    spaceLeft_--;

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
    round_++;
    std::cout  << "-----------------" << "Round " << round_ << "-----------------" << std::endl;

}

void game::endGame(int winner)
{

    std::cout << "Game ended, ";
    if(winner == 1)
        std::cout << "Player 1 won the game in " << round_ - 1 << " rounds!!!!" << std::endl;
    else if(winner == 2)
        std::cout << "Player 2 won the game in " << round_ - 1  << " rounds!!!!" << std::endl;
    else if (winner == 0) std::cout << "in a tie" << std::endl;

}

int game::run()
{
    bool end = false;
    
    while (!end)
    {
        incrementRound();
        playNextMovePlayer1();
        if(spaceLeft_ == 0) break;
        printmap();
        if(isgamewon())
        {
            winner_ = player1_.getPlayerNum();
            break;
        } 
        //playNextMovePlayer2();
        position posi = findbestMove();
        gameMap_[posi.posY][posi.poX] = player2_.getSign();
        if(isgamewon())
        {
            winner_ = player2_.getPlayerNum();
            break;
        } 
        printmap();
        std::cout << std::endl;
    }

    endGame(winner_);
    return 1;
    
}

int game::minimax(int depth, bool isMax)
{
    if(isgamewon() || spaceLeft_ == 0)
    {
        if(winner_ == player1_.getPlayerNum())
            return 10;
        else if(winner_ == player2_.getPlayerNum())
            return -10;
        else return 0;
    }

    int bestVal, currVal;
    if(isMax)
    {
        bestVal == -100;
        for (size_t i = 0; i < 3; i++)
        {
            for (size_t j = 0; j < 3; j++)
            {
                position pos; pos.posY = i; pos.poX = j;
                if(gameMap_[i][j] == '_')
                {
                    gameMap_[i][j] = player1_.getSign();
                    currVal = minimax(depth+1, !isMax);
                    bestVal = std::max(bestVal, currVal);
                    gameMap_[i][j] = '_';
                }

            }
            
        }
        return bestVal - depth;
    }
    else
    {
        bestVal = 100;
        for (size_t i = 0; i < 3; i++)
        {
            for (size_t j = 0; j < 3; j++)
            {
                position pos; pos.posY = i; pos.poX = j;
                if(gameMap_[i][j] == '_')
                {
                    gameMap_[i][j] = player2_.getSign();
                    currVal = minimax(depth+1, !isMax);
                    bestVal = std::min(bestVal, currVal);
                    gameMap_[i][j] = '_';
                }
            }
            
        }
        return bestVal - depth;

    }
    
}

position game::findbestMove()
{
    // function findBestMove(board):
    // bestMove = NULL
    // for each move in board :
    //     if current move is better than bestMove
    //         bestMove = current move
    // return bestMove

    position bestMove;
    int bestVal = 100;

    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            if(gameMap_[i][j] == '_')
            {
                gameMap_[i][j] = player2_.getSign();
                int val = minimax(0, false);
                gameMap_[i][j] = '_';

                if(val < bestVal)
                {
                    bestMove.posY = i;
                    bestMove.poX = j ;
                }
            }

        }
        
    }
    
    return bestMove;

}
