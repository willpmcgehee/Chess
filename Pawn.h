/****************************PAWN***************************

DESCRIPTION: Specific gamepiece inherits from ChessPiece.
Overwrites the possible_moves function to simulate the behavior
of a pawn.

METHOD DESCRIPTIONS:
possible_moves - return the set of squares accessible by a pawn
based on the current state of the gameboard.

************************************************************/

#ifndef PAWN_H
#define PAWN_H

#include "ChessPiece.h"

class Pawn: public ChessPiece{
 public:
  Pawn(bool white, int start_pos_index);
  virtual std::vector<std::string> possible_moves(std::string start_coordinate, std::map<std::string,ChessPiece*> &board);
};

#endif
