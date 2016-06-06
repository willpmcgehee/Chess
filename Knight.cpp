#include "Knight.h"

using namespace std;

Knight::Knight(bool white, int start_pos_index):ChessPiece(white){
  _type_of_piece = "Knight";
  /*White knights are on the 1st rank while black knights are on the 8th*/
  if(_is_white){
    _start_pos = "B1";
  }else{
    _start_pos = "B8";
  }
  /*The start position is the A file offset by the start_pos_index x 5*/
  _square.get_square_in_rank(start_pos_index*5, _start_pos);
}

/*Overwrite the possible_moves function*/
vector<string> Knight::possible_moves(string start_coordinate, map<string,ChessPiece*> &board){
  /*Declare the vector of strings to be returned*/
  vector<string> vect;
  /*Iterate through the 8 possible knight moves testing each for validity*/
  knight_move(start_coordinate,vect,board, -2, -1);
  knight_move(start_coordinate,vect,board, -2, 1);
  knight_move(start_coordinate,vect,board, -1, -2);
  knight_move(start_coordinate,vect,board, -1, 2);
  knight_move(start_coordinate,vect,board, 1, -2);
  knight_move(start_coordinate,vect,board, 1, 2);
  knight_move(start_coordinate,vect,board, 2, -1);
  knight_move(start_coordinate,vect,board, 2, 1);
  
  return vect;
}

/*Test one individual move of the knight*/
void Knight::knight_move(string start_coordinate, vector<string> &vect, map<string,ChessPiece*> &board, int rank, int file){
  /*Test the square rank and file away*/
  if(_square.get_square_in_rank(rank, start_coordinate) 
       && _square.get_square_in_file(file, start_coordinate)){
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
}
