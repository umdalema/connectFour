#include "game.h"
using namespace std;

Game::Game():
playerA(player_factory("human", "JohnDoeA", 'x')), playerB(player_factory("human", "JohnDoeB", 'o')), board(vector<vector<char> > (7, vector<char>(6, '-'))), playerA_score(0), playerB_score(0), score(5) {}

Game::Game(char playerA_pieceIN, string playerA_nameIN, string playerA_typeIn,
           char playerB_pieceIN, string playerB_nameIN, string playerB_typeIn,
           int num_rows, int num_cols, int score_in):
playerA(player_factory(playerA_typeIn, playerA_nameIN, playerA_pieceIN)),
playerB(player_factory(playerB_typeIn, playerB_nameIN, playerB_pieceIN)),
board(vector<vector<char> > (num_rows, vector<char>(num_cols, '-'))), playerA_score(0),
playerB_score(0), score(score_in) {}


void Game::printBoard(){
    
    // we want to move across and then down.
    
    

    for (int col = int(board[0].size()) - 1; col >= 0; col --){
        
        cout << "|" << board[0][col];
        
        for (size_t row = 1; row < board.size(); row++){
            cout << " " << board[row][col];
        }
        cout << "|\n";
    }
    
    for (size_t i = 0; i < board.size(); i++){
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
bool Game::checkDiag(char piece, int played_in){
    
   // we can find the row we're playing in the easy way now:
    // we have the column that we played in, so we first need to get the row.
    vector<char>::iterator it = find(board[played_in].begin(), board[played_in].end(), '-');
    
    // get the correct row. Need to subtract one because of zero index.
    int row =  int(distance(board[played_in].begin(), it)) - 1;
    
    // Check to make sure that the row and column are not out of bounds by going backwards:
    int difference = 0;
    int diff_forward = 0;
    
    if ( (row - 4) < (played_in - 4)){
        int rowStart = ((row - 4) > 0) ? (row - 4) : 0;
        difference = row - rowStart;
    } else {
        int colStart = ((played_in - 4) > 0) ? (played_in - 4) : 0;
        difference = played_in - colStart;
    }
    
    // check to make sure that the row and column are inbounds going forward.
    // using that number we can then
    if ( (row + 4) > (played_in + 4)){
        int rowEnd = ((row + 4) < int(board[0].size())) ? (row + 4) : int(board[0].size() - 1);
        diff_forward = rowEnd - row;
    } else {
        int colEnd = ((played_in + 4) < int(board.size())) ? (played_in + 4) : int(board.size() - 1);
        diff_forward = colEnd - played_in;
    }
    
    int counter = 0;
    for (int col = (played_in - difference); col <= played_in + diff_forward; col++){
        
        int rowCurrent =  row - difference;
        
        counter++;
        difference--;
        
        if (board[col][rowCurrent] != piece){
            counter = 0;
        }
        if (counter == 4){
            return true;
        }
        
    }
    
    return false;


    
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

bool Game::checkSide(char piece, int played_in){
  
    // we have the column that we played in, so we first need to get the row.
    vector<char>::iterator it = find(board[played_in].begin(), board[played_in].end(), '-');
    
    // get the correct row. Need to subtract one because of zero index.
    int row =  int(distance(board[played_in].begin(), it)) - 1;
    
    // start and end columns to look at.
    int colStart = ((played_in - 4) > 0) ? (played_in - 4) : 0;
    int colEnd = ((played_in + 4) < int(board.size()) - 1) ? (played_in + 4) : int(board.size() - 1);
    
    int counter = 0;
    
    for (int col = colStart; col <= colEnd; col++){
        
        counter++;
        
        if (board[col][row] != piece){
            counter = 0;
        }
        if (counter == 4){
            return true;
        }
    }
    
    return false;
}

bool Game::checkUp(char piece, int played_in){
  
    vector<char>::iterator it = find(board[played_in].begin(), board[played_in].end(), '-');
    
    for (int i = 0; i < 4; i++){
        
        it--;
        
        if (*it != piece){
            return false;
        }
        
    }
    
    
    return true;
}
bool Game::checkBoardForSolution(char piece, int played_in){
    
    /*     
           4 0 1 2 3 4
           3 0 1 2 3 4
           2 0 1 2 3 4
           1 0 1 2 3 4
           0 0 1 2 3 4
     */
    played_in -= 1;
    
    // start with the first square and check every square;
    if (checkUp(piece, played_in ) ||
        checkSide(piece, played_in) ||
        checkDiag(piece, played_in) ||
        checkBackDiag(piece)) {
        return true;
    }
   
    return false;
    
}
void Game::updateBoard(int col, Player* currentPlayer){
    
    
    // we can loop through the rows:
    // when we find something in the column that we're playing in, we can
    // simply move forward one row:
    
    /*col--;
    
    for (size_t row = 0; row < board.size(); row++){
        
        if (board[row][col] == '-'){
            board[row][col] = currentPlayer->getPiece();
            return;
        }
    }*/
    col--;
    vector<char>::iterator it = find(board[col].begin(), board[col].end(), '-');
   
    
    *it = currentPlayer->getPiece();
    
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
            
            if (boardIsFull()) {
                cout << "The Board is full! Good luck in the next game!\n";
                break; 
            }
            
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
            
            
            updateBoard(checkFullColumn(col, playerA), playerA);
            
            if (checkBoardForSolution(playerA->getPiece(), col)){
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

            
            updateBoard(checkFullColumn(col, playerB), playerB);
            if (checkBoardForSolution(playerB->getPiece(), col)){
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

int Game::checkFullColumn(int colSelected, Player* currentPlayer){
    

        if (board[board.size() -1][colSelected - 1] != '-'){
            // the last piece in this column isn't the void piece so the column is full
            
            while (board[board.size() -1][colSelected - 1] != '-'){
                colSelected = currentPlayer->playFullColumn(colSelected);
            }
    
        }
    return colSelected;
}

bool Game::boardIsFull(){
    
    for (size_t col = 0; col < board[0].size(); col++){
        if(board[board.size() - 1][col] == '-'){
            return false;
        }
    }
    
    
    return true;
}
