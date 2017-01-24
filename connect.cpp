/*
    Dale Mallette
    December 12th, 2016
    Personal project: just a simple little texted based c++ game.
*/

#include <iostream>
#include <vector>
#include <string>
#include <getopt.h>

#define computerNameHolder "void"
#define computerPieceHolder '-'
#define standardRows 6
#define standardCols 7

#include "game.h"
using namespace std;

void printHelpInfo();
void original();
void custom();
void simple();

int main(int argc, char* argv[]){
    
    static struct option longOpts[] = {
        {"mode", optional_argument, nullptr, 'm'},
        {"help", no_argument, nullptr, 'h'},
        {nullptr, 0, nullptr, 0}
    }; // longOpts
    
    int option, index;
    int mode = 'o';
    
    while ((option = getopt_long(argc, argv, "m:h", longOpts, &index)) != -1){
        switch (option) {
            case 'm':
                mode = tolower(optarg[0]);
                break;
            case 'h':
                printHelpInfo();
                exit(0);
            default:
                cerr << "You've provide an un-recognized flag." << endl;
                printHelpInfo();
                exit(1);
        } // switch
    } // while getopt_long
    
   
    
    switch (mode) {
        case 'o':
            // run simple mode with 2 human players on a 6x7 board.
            original();
            break;
        case 'c':
            custom();
            // run custom mode with 2 human players on a custom board.
            break;
        case 's':
            // run simple mode with 1 human and 1 computer player. 
            simple();
            break;
        default:
            cout << "Invalid mode selected!";
            printHelpInfo(); 
            break;
    }
    
    
    return 0;
} // main()

void printHelpInfo(){
    
    cout << "Text based connect 4 varient:\n";
    cout << "Discalimer: I do not own any rights to this game!!\n";
    cout << "\n";
    cout << "USAGE:\n";
    cout << "-h, --help: get helpful information about the game\n";
    cout << "-m, --mode <MODE>: MODE is optional. If unspecified will default to SIMPLE.\n";
    cout << "MODE option:\n";
    cout << "   s: simple mode. two players will vs eachother on a standard 6x7 board.\n";
    cout << "   c: custom mode. two players will play eachother on a board the size of which they choose.\n";
    cout << "      Players will also get to chose what piece they use throught the game.\n";
    
    return;
}

void original(){
    string playerA_name;
    string playerB_name;
    int score;
    
    cout << "Original is a two player mode with two human players.\n\n";
    cout << "Player 1, please enter the name you'd like to use:";
    getline(cin, playerA_name);
    cout << playerA_name << " you will be playing with x.\n\n";
    cout << "Player 2, please enter the name you'd like to use:";
    getline(cin, playerB_name);
    cout << playerB_name << " you will be playing with o.\n\n";
    
    cout << "Discuss amongst yourselves to what score you'd like to play to.\n";
    cout << "What score would you like to play to? ";
    cin >> score;
    
    cout << "\nThank you for you patience and good luck to both of you! Enjoy!\n\n";
    
    Game game('x', playerA_name, "human", 'o', playerB_name, "human", 6, 7, score);
    
    game.playGame();
    cout << "Thanks for playing!";
    return;
}

void custom() {
    
    string playerA_name;
    string playerB_name;
    char   playerA_piece;
    char   playerB_piece;
    int numRows = 0;
    int numCols = 0;
    int score;
    
    cout << "Custom mode is a two player mode with two human players.\n\n";
    cout << "Player 1, please enter the name you'd like to use:";
    getline(cin, playerA_name);
    cout << playerA_name << " please select the piece you would like to use.\n";
    cout << "Please select only one character: ";
    cin >> playerA_piece;
    cout << "\nPlayer2, please enter the name you'd like to use:";
    cin.ignore();
    //getline(cin, playerB_name);
    getline(cin, playerB_name);
    cout << "\n" << playerB_name << " please select the piece you would like to use.\n";
    cout << "Please select only one character: ";
    cin >> playerB_piece;
    
    cout << "\nPlease enter the dimensions of the board you'd like to use.\n";
    cout << "Use the format numRows numCols (notice the space inbetween): ";
    cin >> numRows >> numCols;
    
    while (numRows < 6){
        cout << "\nThe number of rows you entered was invalid.\n";
        cout << "Please choose a number greater than or equal to 6: ";
        cin >> numRows;
    }
    
    while (numCols < 7){
        cout << "\nThe number of columns you entered was invalid.\n";
        cout << "Please choose a number greater than or equal to 7: ";
        cin >> numCols;
    }
    
    
    cout << "\nDiscuss amongst yourselves to what score you'd like to play to.\n";
    cout << "What score would you like to play to? ";
    cin >> score;
    
    cout << "\nThank you for you patience and good luck to both of you! Enjoy!\n\n";
    
    Game game(playerA_piece, playerA_name, "human", playerB_piece, playerB_name, "human", numRows, numCols, score);
    
    game.playGame();
    cout << "Thanks for playing!";
    return;
}

void simple(){
    
    
    string playerA_name;
    string playerB_name;
    char   playerA_piece;
    int score;
    
    
    cout << "Simple mode is a one player mode in which Player 2 will be a \"computer\" player.\n";
    cout << "Simple mode is played on a standard 6x7 board.\n";
    cout << "Player 1, please enter the name you'd like to use:";
    getline(cin, playerA_name);
    
    
    cout << playerA_name << " please select the piece you would like to use.\n";
    cout << "Please select only one character: ";
    cin >> playerA_piece;
    
    cin >> score;
    
    cout << "\nThank you for you patience and good luck to both of you! Enjoy!\n\n";
    
    Game game(playerA_piece, playerA_name, "human", computerPieceHolder, computerNameHolder, "simple", standardRows, standardCols, score);
    game.playGame();
    cout << "Thanks for playing!";
    return;
}









