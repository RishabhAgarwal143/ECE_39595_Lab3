#include "PawnPiece.hh"
#include "ChessBoard.hh"

namespace Student
{
    PawnPiece::PawnPiece(ChessBoard &board, Color color, int row, int column) : ChessPiece(board, color, row, column)
    {
        this->piece_type = Pawn;
    }

    void PawnPiece::setPosition(int row, int column)
    {
        this->piece_row = row;
        this->piece_column = column;
    }

    bool PawnPiece::canMoveToLocation(int toRow, int toColumn)
    {
        if (this->piece_board->getPiece(toRow, toColumn) != nullptr && this->piece_column == toColumn)
        {
            return false;
        }
        if (this->piece_color == White)
        {
            if (toColumn == this->piece_column)
            {
                if (this->piece_row - toRow == 2 && (this->piece_row == this->piece_board->getNumRows() - 2))
                {
                    // check if piece in n - 2
                }
                else if (this->piece_row - toRow == 1)
                {
                    // check if piece
                }

                // check if piece is there in pos - false else return true
            }
        }
        else
        {
            if (toColumn == this->piece_column)
            {
                // if piecerow - toRow
            }
        }

        return true;
    }

    const char *PawnPiece::toString()
    {
        if (this->piece_color == White)
        {
            return "\u2659";
        }
        else
        {
            return "\u265F";
        }
    }

}