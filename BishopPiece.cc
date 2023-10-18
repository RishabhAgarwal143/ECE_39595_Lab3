#include "BishopPiece.hh"
#include "ChessBoard.hh"
#include <iostream>

using Student::ChessBoard;
namespace Student
{
    BishopPiece::BishopPiece(ChessBoard &board, Color color, int row, int column) : ChessPiece(board, color, row, column)
    {
        this->piece_type = Bishop;
    }

    void BishopPiece::setPosition(int row, int column)
    {
        this->piece_row = row;
        this->piece_column = column;
    }

    bool BishopPiece::canMoveToLocation(int toRow, int toColumn)
    {
       
        return false;
    }

    const char *BishopPiece::toString()
    {
        if (this->piece_color == White)
        {
            return "\u2657";
        }
        else
        {
            return "\u265D";
        }
    }

}