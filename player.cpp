/*
 Dale Mallette
 December 20th, 2016
 Player class: Implemntation Current version only supports human players.
 */

#include "player.h"
using namespace std;

Player* player_factory(std::string playerType_in, std::string name_in, char piece_in){
    
    if (playerType_in == "human"){
        return new Human(name_in, piece_in);
    } else if (playerType_in == "simple"){
        return new Simple();
    }
    
    return nullptr;
}
/******************************************************************************
 IMPLEMENTATION OF PLAYER CLASS
 ******************************************************************************/
Player::Player():
name("John Doe"), piece('$'){}

Player::Player(std::string name_in, char piece_in):
name(name_in), piece(piece_in){}

char Player::getPiece(){
    return piece;
}
std::string Player::getName(){
    return name;
}
/******************************************************************************
 IMPLEMENTATION OF HUMAN CLASS
 ******************************************************************************/

Human::Human():
Player(){}

Human::Human(std::string name_in, char piece_in):
Player(name_in, piece_in){}

int Human::playPiece() {
    int col;
    
    std::cout << getName() << " it's your turn.\n";
    std::cout << "Please select which coloumn you'd like to play in: ";
    std::cin >> col;
    std::cout << "\n";
    return col;
}

int Human::playFullColumn(int colSelected){
    
    cout << "\nColumn " << colSelected << " is full. Please sleect a different column: ";
    cin >> colSelected;
    
    return colSelected; 
}


/******************************************************************************
 IMPLEMENTATION OF SIMPLE CLASS
 ******************************************************************************/

Simple::Simple():
Player(getRandomName(), getRandomPiece()){}

Simple::Simple(std::string name_in, char piece_in):
Player(name_in, piece_in){}

int Simple::playPiece(){
    // in the easyversion it will just chose a player at random.
    // return number out of 1000.
    return ((rand() % 1000) % 6) + 1;
}

int Simple::playFullColumn(int colSelected){
    // try to select another random column.
    colSelected = playPiece();  
    return  colSelected; 
}

char Simple::getRandomPiece(){
    int index = rand() % NUMCHARS;
    
    return characters_for_computer[index];
}

std::string Simple::getRandomName(){
    int index = rand() % NUMNAMES;
    
    return names_for_Computer[index];
}
