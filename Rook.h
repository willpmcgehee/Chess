/****************************ROOK***************************

DESCRIPTION: Specific gamepiece inherits from ChessPiece.
Overwrites the possible_moves function to simulate the behavior
of a rook.

METHOD DESCRIPTIONS:
possible_moves - return the set of squares accessible by a rook
based on the current state of the gameboard.

************************************************************/

#ifndef ROOK_H
#define ROOK_H

#include "ChessPiece.h"

class Rook: public ChessPiece{
 public:
  Rook(bool white, int start_pos_index);
  virtual std::vector<std::string> possible_moves(std::string start_coordinate, std::map<std::string,ChessPiece*> &board);
};

#endif
