/*
    Dale Mallette
    December 20th, 2016
    Player class: Current version only supports human players.
*/

#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string> 

class Player {
    public:
        Player();
        Player(std::string name_in, char piece_in);
    
        // need to finsih this funciton:
        int playPiece();
        std::string name;
        char piece;
};
#endif
