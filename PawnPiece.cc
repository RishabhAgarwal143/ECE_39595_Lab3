#include "PawnPiece.hh"

namespace Student
{
    PawnPiece::PawnPiece(ChessBoard &board, Color color, int row, int column) : ChessPiece(board, color, row, column)
    {
        this->piece_type = Pawn;
    }

    void PawnPiece::setPosition(int row, int column)
    {
    }

    bool PawnPiece::canMoveToLocation(int toRow, int toColumn)
    {
    }

    const char *PawnPiece::toString()
    {
    }

}