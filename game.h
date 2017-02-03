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
class Game {
public:
    Game();
    Game(char playerA_pieceIN, std::string playerA_nameIN, std::string playerA_typeIn,
         char playerB_pieceIN, std::string playerB_nameIN, std::string playerB_typeIn,
         int num_rows, int num_cols, int score_in);
    
    void playGame();
private:
    
    Player* playerA;
    Player* playerB;
    std::vector<std::vector<char> > board;
    int playerA_score;
    int playerB_score;
    int score; 
    
    bool checkBoardForSolution(char piece, int played_in);
    void printBoard();
    void printScore();
    void resetBoard(); 
    void updateBoard(int col_num, Player* currentPlayer);
    bool checkDiag(char piece);
    bool checkSide(char piece);
    bool checkUp(char piece, int played_in);
    bool checkBackDiag(char piece);
    int checkFullColumn(int colSelected, Player* currentPlayer);
    bool boardIsFull();
};

#endif
