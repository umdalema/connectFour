/*
 Dale Mallette
 December 20th, 2016
 Player class: Implemntation Current version only supports human players.
 */

#include "player.h"
using namespace std;

Player::Player():
    name("John Doe"), piece('$'){}

Player::Player(string name_in, char piece_in):
    name(name_in), piece(piece_in){}

