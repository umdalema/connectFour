/*
    Dale Mallette
    December 20th, 2016
    GAME Class header
*/

#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <string>
#include <vector>
#include "player.h"
struct Game {
    
    Game(); 
    Game(char playerA_pieceIN, std::string playerA_nameIN,
         char playerB_pieceIN, std::string playerB_nameIN,
         int num_rows, int num_cols);
    
    std::vector<std::vector<char> > board;
    Player playerA;
    Player playerB;
    
    void playGame();
    void checkBoardForSolution(); 
};

#endif
