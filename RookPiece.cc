#include "RookPiece.hh"
#include "ChessBoard.hh"
#include <iostream>

using Student::ChessBoard;
namespace Student
{
    RookPiece::RookPiece(ChessBoard &board, Color color, int row, int column) : ChessPiece(board, color, row, column)
    {
        this->piece_type = Rook;
    }

    void RookPiece::setPosition(int row, int column)
    {
        this->piece_row = row;
        this->piece_column = column;
    }

    bool RookPiece::canMoveToLocation(int toRow, int toColumn)
    {
       
        return false;
    }

    const char *RookPiece::toString()
    {
        if (this->piece_color == White)
        {
            return "\u2656";
        }
        else
        {
            return "\u265C";
        }
    }

}