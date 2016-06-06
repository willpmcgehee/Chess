/************************CHESSBOARD*************************

DESCRIPTION: The main engine of the chess program. The chessboard
contains all the pieces, places those pieces in the correct starting
locations, keeps track of who's turn it is to move and checks the
status of the game (specifically, check, checkmate and stalemate).

METHOD DESCRIPTIONS:
try_move - tests whether a move will result in the player being in check
make_move - updates the 'game_board' simulating a move being made
string_in_vector - helper method, returns true if a string exists in the
vector
print_invalid_move - if a move is invalid, prints an error message to cout
player_in_check - returns true if the player is in check
player_in_mate - returns true if the player is in checkmate
resetBoard - returns all game pieces to their starting positions
submitMove - attempt to update the 'game_board' with a specific move


************************************************************/

#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include "ChessPiece.h"
#include "Pawn.h"
#include "Rook.h"
#include "Bishop.h"
#include "Knight.h"
#include "Queen.h"
#include "King.h"
#include <iostream>

#define Board std::map<std::string,ChessPiece*>

class ChessBoard{

 private:
  Board game_board;
  std::vector<ChessPiece*> game_pieces;
  bool white_to_play;
  bool try_move(std::string start_pos, std::string end_pos);
  void make_move(std::string start_pos, std::string end_pos);
  bool string_in_vector(std::string str, std::vector<std::string> vect);
  void print_invalid_move(std::string start_pos, std::string end_pos);
  bool player_in_check(); 
  bool player_in_mate(); 
public:
  ChessBoard();
  void resetBoard();
  void submitMove(std::string start_pos, std::string end_pos);  
};

#endif
