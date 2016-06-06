/****************************QUEEN***************************

DESCRIPTION: Specific gamepiece inherits from ChessPiece.
Overwrites the possible_moves function to simulate the behavior
of a queen.

METHOD DESCRIPTIONS:
possible_moves - return the set of squares accessible by a queen
based on the current state of the gameboard.

************************************************************/

#ifndef QUEEN_H
#define QUEEN_H

#include "ChessPiece.h"

class Queen: public ChessPiece{
 public: 
  Queen(bool white);
    virtual std::vector<std::string> possible_moves(std::string start_coordinate, std::map<std::string,ChessPiece*> &board);
};

#endif

