/*
    Dale Mallette
    December 20th, 2016
    Player class: Current version only supports human players.
*/

#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string> 
#define NUMNAMES 34
#define NUMCHARS 16

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
};

static const char characters_for_computer[NUMCHARS] {
    '!', '$', ';', '9', '1',
    '0', '2', '#', 'a', 'q',
    'f', 'u', 'c', 'k', '&',
    '*'
};

//MARK: Class Definitions
class Player {
    private:
        std::string name;
        char piece;

    public:
        Player();
    
        Player(std::string name_in, char piece_in);
        
        char getPiece();
        
        std::string getName();
   
        // need to finsih this funciton:
        virtual int playPiece() = 0;
};

class Human : public Player {
    public:
        Human();
        
        Human(std::string name_in, char piece_in);
        
        virtual int playPiece();
};

class Simple : public Player {
public:
    Simple();
    
    Simple(std::string name_in, char piece_in);
    
    virtual int playPiece();
    
private:
    char getRandomPiece();
    
    std::string getRandomName();
};

/*
 *  REQUIRED: playerType_in must be all lowercase.
 */

Player* player_factory(std::string playerType_in, std::string name_in, char piece_in);

#endif

