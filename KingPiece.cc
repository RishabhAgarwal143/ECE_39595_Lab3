#include "KingPiece.hh"
#include "ChessBoard.hh"
#include <iostream>

using Student::ChessBoard;
namespace Student
{
    KingPiece::KingPiece(ChessBoard &board, Color color, int row, int column) : ChessPiece(board, color, row, column)
    {
        this->piece_type = King;
    }

    void KingPiece::setPosition(int row, int column)
    {
        this->piece_row = row;
        this->piece_column = column;
    }

    bool KingPiece::canMoveToLocation(int toRow, int toColumn)
    {
        // this->piece_board->movePiece
        if(!(this->getRow()  + 1 >= toRow and this->getRow() - 1 <= toRow))
        {
            return false;
        }
        if(!(this->getColumn()  + 1 >= toColumn and this->getColumn() - 1 <= toColumn))
        {
            return false;
        }

        // this->piece_board->isPieceUnderThreat(toRow,toColumn);
        
        return true;
    }

    const char *KingPiece::toString()
    {
        if (this->piece_color == White)
        {
            return "\u2654";
        }
        else
        {
            return "\u265A";
        }
    }

}