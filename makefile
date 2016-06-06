chess: ChessMain.o  ChessBoard.o Pawn.o Rook.o ChessPiece.o Bishop.o Knight.o Queen.o King.o Coordinate.o
	g++ ChessMain.o ChessBoard.o Pawn.o Rook.o ChessPiece.o Bishop.o Knight.o Queen.o King.o Coordinate.o -o chess

ChessMain.o: ChessMain.cpp ChessBoard.h
	g++ -c ChessMain.cpp

ChessPiece.o:ChessPiece.h Coordinate.h ChessPiece.cpp
	g++ -c ChessPiece.cpp

Pawn.o: Pawn.h ChessPiece.h Pawn.cpp 
	g++ -c Pawn.cpp

Bishop.o: Bishop.h Bishop.cpp ChessPiece.h
	g++ -c Bishop.cpp

Rook.o:Rook.h Rook.cpp ChessPiece.h
	g++ -c Rook.cpp

Knight.o:Knight.h Knight.cpp ChessPiece.h
	g++ -c Knight.cpp

Queen.o:Queen.h Queen.cpp ChessPiece.h
	g++ -c Queen.cpp

King.o:King.h King.cpp ChessPiece.h
	g++ -c King.cpp

Coordinate.o: Coordinate.h Coordinate.cpp
	g++ -c Coordinate.cpp

ChessBoard.o: ChessBoard.h ChessBoard.cpp Pawn.h Bishop.h Rook.h Knight.h Queen.h King.h Coordinate.h
	g++ -c ChessBoard.cpp
