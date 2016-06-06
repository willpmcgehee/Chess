/****************************KING***************************

DESCRIPTION: Specific gamepiece inherits from ChessPiece.
Overwrites the possible_moves function to simulate the behavior
of a king.

METHOD DESCRIPTIONS:
possible_moves - return the set of squares accessible by a king
based on the current state of the gameboard.

************************************************************/

#ifndef KING_H
#define KING_H

#include "ChessPiece.h"

class King: public ChessPiece{
 public: 
  King(bool white);
    virtual std::vector<std::string> possible_moves(std::string start_coordinate, std::map<std::string,ChessPiece*> &board);
};

#endif
