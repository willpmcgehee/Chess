#include "Pawn.h"

using namespace std;

/*Set the color, type_of_piece and the start position.*/
Pawn::Pawn(bool white, int start_pos_index):ChessPiece(white){
  _type_of_piece = "Pawn";

  /*White pawns are on the 2nd rank while black pawns are on the 7th*/
  if(_is_white){
    _start_pos = "A2";
  }else{
    _start_pos = "A7";
  }

  /*The start position is the A file offset by the start_pos_index*/
  _square.get_square_in_rank(start_pos_index,_start_pos);
}

/*Overwright the possible_moves function*/
vector<string> Pawn::possible_moves(string start_coordinate, map<string,ChessPiece*> &board){

  /*Declare the vector of strings to be returned*/
  vector<string> vect;

  /*White pawns move up ranks while black pawns move down ranks. Therefore
   change the direction of the increment depending on the pawn's color.*/
  int increment;
  if(_is_white){
    increment = 1;
  }else{
    increment = -1;
  }

  /*A pawn can move one square forward, unless it at the edge of the board*/
  if(_square.get_square_in_file(increment,start_coordinate)){
    //Unless there is a piece occupying that square
    if(board[start_coordinate] == NULL){
      vect.push_back(start_coordinate);
      /*if it is the pawn's first move, it can move two spaces forward*/
      if(_is_first_move 
	 && _square.get_square_in_file(increment,start_coordinate)){
	//unless a piece occupies that square
	if(board[start_coordinate] == NULL){
	  vect.push_back(start_coordinate);
	}
	//move the square pointer back a space
	_square.get_square_in_file(-increment,start_coordinate);
      }    	
    }

    /*Pawns can also take pieces one square diagonally left or right
      First check (relative) left*/
    if(_square.get_square_in_rank(-increment,start_coordinate)){ 
      /*Assuming a piece is present in one of those two squares*/
      if(board[start_coordinate] != NULL){
	/*And that piece is a different color*/
	if(board[start_coordinate]->is_white() != _is_white){
	  vect.push_back(start_coordinate);
	} 
      }
      /*move coordinate pointer back to the (relative) right*/
      _square.get_square_in_rank(increment,start_coordinate);
    }
    
    /*Next check (relative) right*/
    if(_square.get_square_in_rank(increment,start_coordinate)){
      /*check that if a piece exists it is the opponent's piece*/
      if(board[start_coordinate] != NULL){
	if(board[start_coordinate]->is_white() != _is_white){
	  vect.push_back(start_coordinate);
	}
      }
      //move coordinate pointer back to the (relative) left
      _square.get_square_in_rank(-increment,start_coordinate);
    }
  }
  
  return vect;
}



  
  



