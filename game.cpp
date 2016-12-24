
#include "game.h"
using namespace std;

Game::Game():
playerA("JohnDoeA", 'x'), playerB("JohnDoneB", 'o'), board(vector<<vector<char> > (6, vector<char>(7, ' '))) {}

Game::Game(char playerA_pieceIN, string playerA_nameIN, 
           char playerB_pieceIN, string playerB_nameIN,
           int num_rows, int num_cols):
playerA(playerA_nameIN, playerA_pieceIN), playerB(playerB_nameIN, playerB_pieceIN),
board(vector<vector<char> > (num_rows, vector<char>(num_cols, " "))) {}

