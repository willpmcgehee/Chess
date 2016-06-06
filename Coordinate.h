/************************COORDINATE*************************

DESCRIPTION: A convienceince class that allows for coordinate
checking and easy navigation around the chess baord.

METHOD DESCRIPTIONS:
is_valid_coordinate - returns true if the string cooresponds to
a position on the chess board. False if not.
get_square_in_rank/file - Updates a coordinate string to correspond 
to the square on the same rank/file 'offset' number of squares over. 
Returns true if the opperation succeds, false if an error occurs.

************************************************************/

#ifndef COORDINATE_H
#define COORDINATE_H

#include <vector>
#include <string>

#define board_size 8
#define valid_coordinate_size 2

class Coordinate{

 public:
  bool is_valid_coordinate(std::string square);
  bool get_square_in_rank(int offset, std::string &square);
  bool get_square_in_file(int offset, std::string &square);
};

#endif
