#include "Queen.h"

using namespace std;

Queen::Queen(bool white):ChessPiece(white){
  _type_of_piece = "Queen";
  /*The white queen is located at D1 while the black queen is located at D8*/
  if(_is_white){
    _start_pos = "D1";
  }else{
    _start_pos = "D8";
  }
}

vector<string> Queen::possible_moves(string start_coordinate, map<string,ChessPiece*> &board){
  /*Declare the vector of strings to be returned*/
  vector<string> vect;
  string start = start_coordinate;

  /*Nested for loop, iterates through every diagonal, rank and file*/
  for(int i = -1; i < 2; i++){
    for(int y = -1; y < 2; y++){
      /*While the coordinate is still on the board test the coordinate*/
      while(_square.get_square_in_rank(i, start_coordinate) 
	    && _square.get_square_in_file(y, start_coordinate)){
	/*Add the square if empty*/
	if(board[start_coordinate] == NULL){
	  vect.push_back(start_coordinate);
	}else{
	  /*Or occupied by the opponent's piece*/
	  if(board[start_coordinate]->is_white() != _is_white){
	    vect.push_back(start_coordinate);
	  }
	  /*Break the while loop as cannot move through pieces*/
	  break;
	}
      }
      /*Reset the coordinate to the starting square*/
      start_coordinate = start;
    }
  }

  return vect;
}


