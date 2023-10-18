#include "ChessPiece.hh"
// #include "ChessBoard.hh"
// #include "PawnPiece.hh"
// #include "RookPiece.hh"
// #include "BishopPiece.hh"
// #include "KingPiece.hh"
    
using Student::ChessBoard;
namespace Student
{
    ChessPiece::ChessPiece(ChessBoard &board, Color color, int row, int column)
    {
        this->piece_board = &board;
        this->piece_row = row;
        this->piece_color = color;
        this->piece_column = column;
    }

    void ChessPiece::setPosition(int row, int column)
    {
        this->piece_row = row;
        this->piece_column = column;
    }

}