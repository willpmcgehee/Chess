/****************************BISHOP***************************

DESCRIPTION: Specific gamepiece inherits from ChessPiece.
Overwrites the possible_moves function to simulate the behavior
of a bishop.

METHOD DESCRIPTIONS:
possible_moves - return the set of squares accessible by a knight
based on the current state of the gameboard.

************************************************************/

#ifndef BISHOP_H
#define BISHOP_H

#include "ChessPiece.h"

class Bishop: public ChessPiece{
 public:
  Bishop(bool white, int start_pos_index);
  virtual std::vector<std::string> possible_moves(std::string start_coordinate, std::map<std::string,ChessPiece*> &board);
};

#endif
