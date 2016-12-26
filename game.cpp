
#include "game.h"
using namespace std;

Game::Game():
playerA("JohnDoeA", 'x'), playerB("JohnDoneB", 'o'), board(vector<vector<char> > (6, vector<char>(7, '-'))), playerA_score(0), playerB_score(0) {}

Game::Game(char playerA_pieceIN, string playerA_nameIN, 
           char playerB_pieceIN, string playerB_nameIN,
           int num_rows, int num_cols):
playerA(playerA_nameIN, playerA_pieceIN),playerB(playerB_nameIN, playerB_pieceIN),
board(vector<vector<char> > (num_rows, vector<char>(num_cols, '-'))), playerA_score(0),
playerB_score(0) {}


void Game::printBoard(){
    
    for (size_t row = (board.size() - 1); row >= 0; row--){
        cout << "|" << board[row][0];
        for (size_t col = board[i].size() - 1; col >= 0; col--){
            cout << " " << board[row][col];
        }
        cout << "|\n";
    }
 
    for (int i = 0; i < board[0].size(); i++){
        cout << " " << (i + 1);
    }
    
    cout << endl;
}

void printScore(){
    
    cout << playerA.name << ": " << playerA_score << " points\n"
    cout << playerb.name << ": " << playerB_score << " points\n"
}

bool Game::checkBoardForSolution(){
    
    // we could go with the queue method.
    
    
    
}
void Game::updateBoard(int col, Player* currentPlayer){
    
    
    // we can loop through the rows:
    // when we find something in the column that we're playing in, we can
    // simply move forward one row:
    
    for (size_t row = 0; row < board.size(); row++){
        
        if (board[row][col] == '-'){
            board[row][col] = currentPlayer->piece;
            return;
        }
    }
    
    return;
}

void Game::playGame(){
    
    printBoard();
    
    while ((playerA_score < 5) && (playerB_score < 5)) {
        
        while (true){
            int col = playerA.playPiece();
            
            updateBoard(col, &playerA);
            
            if (checkBoardForSolution()){
                cout << playerA.name << " has won this round!" << endl;
                playerA_score++;
            }
            
            printBoard();
            col = playerB.playPiece();
            
            updateBoard(col, &playerB);
            if (checkBoardForSolution()){
                cout << playerB.name << " has won this round!" << endl;
                playerB_score++;
            }
            
        } // while(true)
    } // while (score)
    
    return;
} // playGame()
