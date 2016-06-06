/****************************KNIGHT***************************

DESCRIPTION: Specific gamepiece inherits from ChessPiece.
Overwrites the possible_moves function to simulate the behavior
of a knight.

METHOD DESCRIPTIONS:
knight_move - helper function. Returns one move of the knight.
To be iterated in all 8 possible directions by possible_moves
possible_moves - return the set of squares accessible by a knight
based on the current state of the gameboard.

************************************************************/

#ifndef KNIGHT_H
#define KNIGHT_H

#include "ChessPiece.h"

class Knight: public ChessPiece{
 private:
  void knight_move(std::string start_coordinate,std::vector<std::string> &vect, std::map<std::string,ChessPiece*> &board, int rank, int file);
 public:
  Knight(bool white, int start_pos_index);
  virtual std::vector<std::string> possible_moves(std::string start_coordinate, std::map<std::string,ChessPiece*> &board);
};

#endif
