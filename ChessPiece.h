/************************CHESSPIECE*************************

DESCRIPTION: An abstract superclass for all specific chesspieces.
Specifies common attributes, accessor methods and the pure virtual
possible_moves function. The possible_moves function is the primary
means through which the ChessBoard class interogates the state of 
the chess game.


METHOD DESCRIPTIONS:
is_white - returns a bool indicating whether the piece is white.
start_pos - returns the square allocated as the piece's start position.
type_of_piece - return a string indicating the type of piece.
is_first_move - returns the _is_first_move attribute. 
set_first_move - set the _is_first_move attribute
possible_moves - returns a vector of strings specifying the coordinates
to which the piece is leagally allowed to move

************************************************************/

#ifndef CHESSPIECE_H
#define CHESSPIECE_H

#include <vector>
#include <string>
#include <map>
#include "Coordinate.h"

class ChessPiece{

 protected:
  bool _is_white;
  std::string _start_pos;
  std::string _type_of_piece;
  bool _is_first_move;
  //Convienience class for easy manipulation of coordinates
  Coordinate _square; 
 public:
  ChessPiece(bool white);
  bool is_white();
  std::string start_pos();
  std::string type_of_piece();
  bool is_first_move();
  void set_first_move(bool val);
  virtual std::vector<std::string> possible_moves(std::string start_coordinate, std::map<std::string,ChessPiece*> &board) = 0;
};

#endif
