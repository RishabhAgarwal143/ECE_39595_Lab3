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
        // check which quadrant the bishop is moving to
        // check if there is a piece in the way
        // check if there is a piece in the destination
        // check if the destination is in the board
        // check if the destination is the same as the current position

        if (this->piece_row == toRow && this->piece_column == toColumn)
        {
            return false;
        }

        
       
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