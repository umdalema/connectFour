
#include "game.h"
using namespace std;

Game::Game():
playerA(player_factory("human", "JohnDoeA", 'x')), playerB(player_factory("human", "JohnDoeB", 'o')), board(vector<vector<char> > (6, vector<char>(7, '-'))), playerA_score(0), playerB_score(0), score(5) {}

Game::Game(char playerA_pieceIN, string playerA_nameIN, string playerA_typeIn,
           char playerB_pieceIN, string playerB_nameIN, string playerB_typeIn,
           int num_rows, int num_cols, int score_in):
playerA(player_factory(playerA_typeIn, playerA_nameIN, playerA_pieceIN)),
playerB(player_factory(playerB_typeIn, playerB_nameIN, playerB_pieceIN)),
board(vector<vector<char> > (num_rows, vector<char>(num_cols, '-'))), playerA_score(0),
playerB_score(0), score(score_in) {}


void Game::printBoard(){
    
    for (int row = int(board.size() - 1); row >= 0; row--){
        cout << "|" << board[row][0];
        for (size_t col = 1; col < board[row].size(); col++){
            cout << " " << board[row][col];
        }
        cout << "|\n";
    }
 
    for (size_t i = 0; i < board[0].size(); i++){
        cout << " " << (i + 1);
    }
    
    cout << endl;
}

void Game::printScore(){
    
    cout << playerA->getName() << ": " << playerA_score << " points\n";
    cout << playerB->getName() << ": " << playerB_score << " points\n\n";
}

bool Game::checkBackDiag(char piece){
    for (size_t row = 0; row < (board.size() - 3); row++){
        for (size_t col = board[row].size(); col > 2; col--){
            if ((board[row][col] == piece) &&
                (board[row + 1][col - 1] == piece) &&
                (board[row + 2][col - 2] == piece) &&
                (board[row + 3][col - 3] == piece)){
                return true;
            }
        }
    }
    return false; 
}
bool Game::checkDiag(char piece){
    for (size_t row = 0; row < (board.size() - 3); row++){
        for (size_t col = 0; col < (board[row].size() - 3); col++){
            if ((board[row][col] == piece) &&
                (board[row + 1][col + 1] == piece) &&
                (board[row + 2][col + 2] == piece) &&
                (board[row + 3][col + 3] == piece)){
                return true;
            }
        }
    }
    return false;
}

bool Game::checkSide(char piece){
    for (size_t row = 0; row < board.size(); row++) {
        for (size_t col = 0; col < (board[row].size() - 3); col++) {
            if ((board[row][col] == piece) &&
                (board[row][col + 1] == piece) &&
                (board[row][col + 2] == piece) &&
                (board[row][col + 3] == piece)){
                
                return true;
            } // if
        } // inner for
    } // outter for
    
    return false;
}

bool Game::checkUp(char piece){
    
    for (size_t col = 0; col < board[0].size(); col++){
        for(size_t row = 0; row < (board.size() - 3); row++){
            if ((board[row][col] == piece) &&
                (board[row + 1][col] == piece) &&
                (board[row + 2][col] == piece) &&
                (board[row + 3][col] == piece)){
                
                return true;
            }
        } // for innter
    } // for outter
    return false;
}
bool Game::checkBoardForSolution(char piece){
    
    /*     
           4 0 1 2 3 4
           3 0 1 2 3 4
           2 0 1 2 3 4
           1 0 1 2 3 4
           0 0 1 2 3 4
     */
    
    // start with the first square and check every square;
    if (checkUp(piece) ||
        checkSide(piece) ||
        checkDiag(piece) ||
        checkBackDiag(piece)) {
        return true;
    }
   
    return false;
    
}
void Game::updateBoard(int col, Player* currentPlayer){
    
    
    // we can loop through the rows:
    // when we find something in the column that we're playing in, we can
    // simply move forward one row:
    col--;
    
    for (size_t row = 0; row < board.size(); row++){
        
        if (board[row][col] == '-'){
            board[row][col] = currentPlayer->getPiece();
            return;
        }
    }
    
    return;
}
void Game::resetBoard(){
    //cout << endl << "Reset" << endl;
    vector<vector<char> > newBoard(board.size(), vector<char>(board[0].size(), '-'));
    board = newBoard;
    return;
}

void Game::playGame(){
    
    //printBoard();
    
    while ((playerA_score < score) && (playerB_score < score)) {
        
        resetBoard();
        printBoard();
        
        int col = -1;
        string trash;
        while (true){
            try {
                col = playerA->playPiece();
                if ((col < 1) || col > int(board[0].size()))
                    throw 'a';
            } catch (char) {
                
                while ((col < 1) || col > int(board[0].size())) {
                    cin.clear();
                    getline(cin, trash);
                    cout << playerA->getName() << " the move you selected is invalid.\n";
                    cout << "Please select a valid column number: ";
                    cin >> col;
                    cout << "\n";
                }
            }
            
            
            updateBoard(col, playerA);
            
            if (checkBoardForSolution(playerA->getPiece())){
                cout << playerA->getName()<< " has won this round!" << endl;
                playerA_score++;
                printBoard();
                break; 
            }
            
            printBoard();
            col = playerB->playPiece();
            
            while ((col < 1) || col > int(board[0].size())) {
                cin.clear();
                getline(cin, trash);
                cout << playerB->getName()<< " the move you selected is invalid.\n";
                cout << "Please select a valid column number: ";
                cin >> col;
                cout << "\n";
            }

            
            updateBoard(col, playerB);
            if (checkBoardForSolution(playerB->getPiece())){
                cout << playerB->getName() << " has won this round!" << endl;
                playerB_score++;
                printBoard();
                break;
            }
            printBoard();
            
        } // while(true)
        
        printScore();
    } // while (score)
    return;
} // playGame()
