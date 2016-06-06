#include "Bishop.h"
#include <iostream>

using namespace std;

Bishop::Bishop(bool white, int start_pos_index):ChessPiece(white){
  _type_of_piece = "Bishop";
  /*White bishops are on the 1st rank while black bishops are on the 8th*/
  if(_is_white){
    _start_pos = "C1";
  }else{
    _start_pos = "C8";
  }
  /*The start position is the C file offset by the start_pos_index x 3*/
  _square.get_square_in_rank(start_pos_index*3, _start_pos);
}

vector<string> Bishop::possible_moves(string start_coordinate, map<string,ChessPiece*> &board){
  /*Declare the vector of string to be returned*/
  vector<string> vect;
  string start = start_coordinate;
  
  /*A nested for loop iterates through each of the bishop's 4 diagonals.
   Each for loop generates -1 then 1.*/
  for(int i = -1; i < 2; i+=2){ 
    for(int y = -1; y < 2; y+=2){
      /*Iterate through every square on the diagonal*/
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
