#include "ChessPiece.h"
#include "Coordinate.h"

using namespace std;

/*Set the color of the piece and set is_first_move to true*/
ChessPiece::ChessPiece(bool white){
  _is_white = white;
  _is_first_move = true;
}

/*Return the color of the piece*/
bool ChessPiece::is_white(){
  return _is_white;
}

/*Return the starting position of the piece*/
string ChessPiece::start_pos(){
  return _start_pos;
}

/*Return the type of the piece*/
string ChessPiece::type_of_piece(){
  return _type_of_piece;
}

/*Return the bool indicating whether the piece has been moved*/
bool ChessPiece::is_first_move(){
  return _is_first_move;
}

/*Set the bool indicating whether the piece has been moved*/
void ChessPiece::set_first_move(bool val){
  _is_first_move = val;
}

