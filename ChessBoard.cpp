#include "ChessBoard.h"

using namespace std;

/*Create the chessboard, create the game pieces and call resetBoard()*/
ChessBoard::ChessBoard(){
  /*Create an empty board
   start in the bottom left hand corner*/
  string a_square = "A1"; 
  string square_ptr;
  for(int i = 0; i < board_size; i++){
    for(int y = 0; y < board_size; y++){
      /*Update the coordinate label to correspond to the i'th file 
       and the y'th rank*/
      square_ptr = a_square;
      square_ptr[0]+=i;
      square_ptr[1]+=y;
      /*Add that coordinate label to the game_board as a key and
       set that key to point to NULL indicating an empty square.*/
      game_board[square_ptr] = NULL;
    }
  }

  //Create the game pieces
  for(int i = 0; i < board_size; i++){
    /*Each player has 8 pawns*/
    game_pieces.push_back(new Pawn(true,i));
    game_pieces.push_back(new Pawn(false,i));
  }
  for(int i = 0; i < 2; i++){
    /*Each player has 2 rooks, 2 knights and 2 bishops*/
    game_pieces.push_back(new Rook(true,i));
    game_pieces.push_back(new Rook(false,i));
    game_pieces.push_back(new Knight(true,i));
    game_pieces.push_back(new Knight(false,i));
    game_pieces.push_back(new Bishop(true,i));
    game_pieces.push_back(new Bishop(false,i));
  }
  /*Each player has 1 queen and 1 king*/
  game_pieces.push_back(new Queen(true));
  game_pieces.push_back(new Queen(false));
  game_pieces.push_back(new King(true));
  game_pieces.push_back(new King(false));

  /*Call resetBoard to place the game pieces on their starting squares.*/ 
  resetBoard();
}

/*Place all game pieces on their starting squares*/
void ChessBoard::resetBoard(){
  /*Iterate through the game_board and set each square to NULL
   thus 'removing' any pieces from the game board.*/
  Board::iterator it;
  for(it = game_board.begin(); it != game_board.end(); it++){
    it->second = NULL;
  }

  /*Place all game pieces on their starting squares and set their
   first_move attribute to true*/
  for(int i = 0; i < game_pieces.size(); i++){
    game_pieces[i]->set_first_move(true);
    game_board[game_pieces[i]->start_pos()] = game_pieces[i];
  }

  /*White moves first*/
  white_to_play = true;

  /*Confirm to the user that a new chess game has begun*/
  cout << "A new chess game is started!" << endl;
}

/*This is the primary engine of the chess game. This function
tests that start_pos and end_pos are expected, confirms that the
move is a leagal move and checks the state of the game for check,
checkmate and stalemate*/
void ChessBoard::submitMove(string start_pos, string end_pos){

  /*Check that valid coordinates have been entered.
   Otherwise, print an error message and exit the function.*/
  Coordinate square;
  if(!square.is_valid_coordinate(start_pos) 
     || !square.is_valid_coordinate(end_pos)){
    cout << "An invalid coordinate was entered. 'A1' to 'H8' expected" 
	 << endl;
    /*Stop executing if an invalid coordinate entered*/
    return;
  }

  /*Basic checks to ensure move is valid.
   First ensure that a piece exists at start_pos*/
  if(game_board[start_pos] != NULL){
    /*Next check that the piece belongs to the player moving*/
    if(white_to_play == game_board[start_pos]->is_white()){
      /*Next check that the piece is leagally allowed to move to end_pos
       by calling the peice's possible_moves function*/
      vector<string> valid_moves = 
	game_board[start_pos]->possible_moves(start_pos, game_board);
      /*And checking that end_pos is one of the pieces leagal moves*/
      if(string_in_vector(end_pos, valid_moves)){
	/*Next ensure that the move does not leave the player in check*/
	if(try_move(start_pos, end_pos)){
	  /*If all these tests are passed, the move is valid.*/
	  make_move(start_pos, end_pos);
	}else{
	  /*The move leaves the player in check so invalid*/
	  print_invalid_move(start_pos, end_pos);
	}	
      }else{
	/*The piece cannot leagally move to end_pos so invalid*/
	print_invalid_move(start_pos, end_pos);
      }
    }else{
      /*The piece does not belong to the player moving*/
      if(white_to_play){
	cout << "It is not Black's turn to move!" << endl;
      }else{
	cout << "It is not White's turn to move!" << endl;
      }
    }
  }else{
    /*There is no piece present at start_pos*/
    cout << "There is no piece at position " << start_pos << "!" << endl;
  }

  /*It is now the other player's turn*/
  white_to_play = !white_to_play;
  
  /*After the move, check the state of the game:
   If the player is in check*/
  if(player_in_check()){
    /*And no possible move can remove him from check*/
    if(player_in_mate()){
      /*Then the player is in checkmate and the game is over*/
      if(white_to_play){
	cout << "White is in checkmate" << endl;
      }else{
	cout << "Black is in checkmate" << endl;
      }
    }else{
      /*Otherwise the player is only in check*/
      if(white_to_play){
	cout << "White is in check" << endl;
      }else{
	cout << "Black is in check" << endl;
      }
    }
  }else if(player_in_mate()){
    /*If the player is not in check but all possible moves place 
     him in check, then a stalemate occures*/
    if(white_to_play){
      cout << "White is in stalemate" << endl;
    }else{
      cout << "Black is in stalemate" << endl;
    }
  }
}

/*Returns true if the player is in check*/
bool ChessBoard::player_in_check(){
  /*First iterate through the board to find the position of the 
    player's king*/
  string king_location;
  Board::iterator it;
  for(it = game_board.begin(); it != game_board.end(); it++){
    if(it->second != NULL){
      if(it->second->type_of_piece() == "King" 
	 && it->second->is_white() == white_to_play){
	king_location = it->first;
      }
    }
  }
  
  /*Next iterate through the game board again.
   If any of the opponent's pieces can legally move to the king's square
  then the player is in check*/
  for(it = game_board.begin(); it != game_board.end(); it++){
    if(it->second != NULL){
      if(it->second->is_white() != white_to_play){
	vector<string> possible_movs = 
	  it->second->possible_moves(it->first,game_board);
	if(string_in_vector(king_location, possible_movs)){
	  return true;
	}
      }
    }
  }
  /*If none of the opponent's pieces can take the king, then the player
   is not in check*/
  return false;  
}

/*Returns true if all the player's moves place him in check*/
bool ChessBoard::player_in_mate(){

  vector<string> possible_movs;
  Board::iterator it;
  /*Iterate through all the player's pieces*/
  for(it = game_board.begin(); it != game_board.end(); it++){
    if(it->second != NULL){
      if(it->second->is_white() == white_to_play){
	/*Get a list of each piece's possible moves. Then iterate through
	 each of those moves*/
	possible_movs = it->second->possible_moves(it->first,game_board);
	for(int i = 0; i < possible_movs.size(); i++){
	  /*If one of those moves keeps him out of check, he is not in mate*/
	  if(try_move(it->first, possible_movs[i])){
	    return false;
	  }
	}
      }
    }
  }
  /*If no move keeps him out of check, the player is in mate*/
  return true;
}

/*Try a move without updating the gameboard. If the move results in 
the player being in check, return false*/
bool ChessBoard::try_move(std::string start_pos, std::string end_pos){  
  ChessPiece *ptr;
  /*Assume the move is valid*/
  bool result = true;
  /*Move the piece on start_pos to end_pos and if applicable
    keep track of the opponents piece on end_pos*/
  if(game_board[start_pos] != NULL){
    ptr = game_board[end_pos];
    game_board[end_pos] = game_board[start_pos];
    game_board[start_pos] = NULL;
    /*If the player is in check, the move was invalid*/
    if(player_in_check()){
      result = false;
    }
    /*Return the piece(s) to their original position*/
    game_board[start_pos] = game_board[end_pos];
    game_board[end_pos] = ptr;
    
    return result;
  }
  
}

/*Update the gameboard for a move and print an appropriate message to cout*/
void ChessBoard::make_move(string start_pos, string end_pos){
  /*Check that a piece exists at start_pos*/
  if(game_board[start_pos] != NULL){
    /*Either white or black is making the move. Print an appropriate message*/
    if(white_to_play){
      cout << "White's ";
    }else{
      cout << "Black's ";
    }
    cout << game_board[start_pos]->type_of_piece() << " moves from "
	 << start_pos << " to " << end_pos;
  
    /*If the player has taken the opponent's piece, print a message*/
    if(game_board[end_pos] != NULL){
      cout << " taking ";
      if(white_to_play){
	cout << "Black's ";
      }else{
	cout << "White's ";
      }
      cout << game_board[end_pos]->type_of_piece();
    }
    cout << endl;

    /*Updaate the state of the game*/
    if(game_board[start_pos]->is_first_move()){
      game_board[start_pos]->set_first_move(false);
    }
    game_board[end_pos] = game_board[start_pos];
    game_board[start_pos] = NULL;
  }
}

/*Helper function - return true if a string is present in a vector*/
bool ChessBoard::string_in_vector(string str, vector<string> vect){
  for(int i = 0; i < vect.size(); i++){
    if(str == vect[i]){
      return true;
    }
  }
  return false;
}

/*Helper function - print an error message to cout if an invalid
move was made*/
void ChessBoard::print_invalid_move(string start_pos, string end_pos){
  if(game_board[start_pos] != NULL){
    if(white_to_play){
      cout << "White's ";
    }else{
      cout << "Black's ";
    }
    cout << game_board[start_pos]->type_of_piece() << " cannot move to "
	 << end_pos << endl;
  }  
}
