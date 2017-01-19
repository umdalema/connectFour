/*
    Dale Mallette
    December 20th, 2016
    Player class: Current version only supports human players.
*/

#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string> 
#define NUMNAMES = 34
#define NUMCHARS = 

static const std::string names_for_Computer[NUMNAMES] {
    "Dale", "Micheal", "Brad", "Ankit",
    "Carl", "Richard", "Richie","Scott",
    "Becky", "Michelle", "Sarah", "Sara",
    "Jamie", "Moriah", "Sam", "Jessica",
    "Chris", "Tara", "Elizabeth", "Charlie",
    "Philip", "Tim", "Aaron", "Erin",
    "Anna", "Ana", "Rachel", "Rebecca",
    "Ethan", "Ben", "Hannah","Katie",
    "Ryan", "Afreen"
}

static const char characters_for_computer[NUMCHARS] {
    '!', '$', ';', '9', '1',
    '0', '2', '#', 'a', 'q',
    'f', 'u', 'c', 'k', '&',
    '*'
}


class Player {
    public:
        Player():
        name("John Doe"), piece('$'){}
    
        Player(std::string name_in, char piece_in):
        name(name_in), piece(piece_in){}
    
        // need to finsih this funciton:
        virtual int playPiece() = 0;
        std:string name;
        char piece
};

class Human : public Player {
public:
    Human():
    Player(){}
    
    Human(std::string name_in, char piece_in):
    Player(name_in, piece_in){}
    
    virtual int playPiece() {
        int col;
        
        cout << name << " it's your turn.\n";
        cout << "Please select which coloumn you'd like to play in: ";
        cin >> col;
        cout << "\n";
        return col;
    }
};


class Simple : public Player {
public:
    Simple():
    Player(getRandomName(), getRandomPiece()){}
    
    Simple(std::string name_in, char piece_in):
    Player(name_in, piece_in){}
    
    virtual int playPiece(){
        // in the easyversion it will just chose a player at random.
        // return number out of 1000.
        return rand() % 1000;
    }
    
private:
    char getRandomPiece(){
        int index = rand() % NUMCHARS;
        
        return characters_for_computer[index];
    }
    
    std::string getRandomName(){
        int index = rand() % NUMNAMES;
        
        return names_for_Computer[index];
    }
};

Player* player_facotry(std::string playerType_in, std::string name_in, char piece_in){
    
    std::string playerType_in_lower = " ";
    transform(playerType_in.begin(), playerType_in.end(), playerType_in_lower.begin(), tolower());
    
    if (playerType_in == "human"){
        return new Human(name_in, piece_in);
    } else if (playerType_in_lower = "simple"){
        return new Simple();
    }
    
    return nullptr;
}
#endif

