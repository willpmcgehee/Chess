#include "Coordinate.h"

using namespace std;

/*Checks that a string is 2 characters long and specifies
a coordinate on the chessboard in the form A1 to H8 */
bool Coordinate::is_valid_coordinate(string square){
  if(square.length() == valid_coordinate_size){
    if(square[0] >= 'A' && square[0] <= 'H'){
      if(square[1] >= '1' && square[1] <= '8'){
	return true;
      }
    }
  }
  return false;
}

/*Updates 'square' to  corespond to the square on the same rank
offset number of squares over. Also perform sanity checks. Offset
can be either negative or positive.*/
bool Coordinate::get_square_in_rank(int offset, string &square){
  //Ensure that 'square' represents a valid coordinate
  if(is_valid_coordinate(square)){ 
    //Update the value of rank by the offset.
    square[0] += offset;
    //Check that the new coordinate value is valid
    if(is_valid_coordinate(square)){
      return true;
    }else{
      //If the new coordinate is invalid, reset to original value
      square[0]-=offset;
    }
  }
  return false;
}

/*Same implimentation as get_square_in_rank*/
bool Coordinate::get_square_in_file(int offset, string &square){
  if(is_valid_coordinate(square)){
    //Update the file of the coordinate by the offset
    square[1] += offset;
    if(is_valid_coordinate(square)){
      return true;
    }else{
      square[1]-=offset;
    }
  }  
  return false;
}
  
