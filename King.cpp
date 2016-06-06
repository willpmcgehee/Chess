#include "King.h"

using namespace std;

King::King(bool white):ChessPiece(white){
  _type_of_piece = "King";
  /*The white king is located at E1 while the black king is located at E8*/
  if(_is_white){
    _start_pos = "E1";
  }else{
    _start_pos = "E8";
  }
}

vector<string> King::possible_moves(string start_coordinate, map<string,ChessPiece*> &board){
  /*Declare the vector of strings to be returned*/
  vector<string> vect;
  string start = start_coordinate;
  
  /*Nested for loop, iterates through every diagonal, rank and file*/
  for(int i = -1; i < 2; i++){
    for(int y = -1; y < 2; y++){
      /*If the coordinate is on the board test the coordinate*/
      if(_square.get_square_in_rank(i, start_coordinate) 
	 && _square.get_square_in_file(y, start_coordinate)){
	/*Add the square if empty*/
	if(board[start_coordinate] == NULL){
	  vect.push_back(start_coordinate);
	}else{
	  /*Or occupied by the opponent's piece*/
	  if(board[start_coordinate]->is_white() != _is_white){
	    vect.push_back(start_coordinate);
	  }
	}
      }
      /*Reset the coordinate to the starting square*/
      start_coordinate = start;
    }
  }
  
  return vect;
}

