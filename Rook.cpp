#include "Rook.h"

using namespace std;

/*Set the color, type_of_piece and the start position.*/
Rook::Rook(bool white, int start_pos_index):ChessPiece(white){
  _type_of_piece = "Rook";
  
  /*White rooks are on the 1st rank while black rooks are on the 8th*/
  if(_is_white){
    _start_pos = "A1";
  }else{
    _start_pos = "A8";
  }
  
  /*The start position is the A file offset by the start_pos_index x 7*/
  _square.get_square_in_rank(start_pos_index*7, _start_pos);
}

/*Overwrite the possible_moves function*/
vector<string> Rook::possible_moves(string start_coordinate, map<string,ChessPiece*> &board){
  /*Declare the vector of strings to be returned*/
  vector<string> vect;
  string start = start_coordinate;

  /*Test all squares on the rook's rank
  For loop sets i to -1 and 1, representing left and right respectively*/
  for(int i = -1; i < 2; i+=2){ 
    /*While the coordinate is still on the board test the coordinate*/
    while(_square.get_square_in_rank(i, start_coordinate)){
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

  /*Test all squares on the rook's file
  For loop sets i to -1 and 1, representing down and up respectively*/
  for(int i = -1; i < 2; i+=2){
    /*While the coordinate is still on the board test the coordinate*/
    while(_square.get_square_in_file(i, start_coordinate)){
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

  return vect;
}
