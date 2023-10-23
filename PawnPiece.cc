#include "PawnPiece.hh"
#include "ChessBoard.hh"
#include <iostream>

using Student::ChessBoard;
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
        // check if normal move or capture
        bool capture = false;
        // check if piece is there in pos
        if (this->piece_board->getPiece(toRow, toColumn) != nullptr)
        {
            capture = true;
            if (this->piece_color == (this->piece_board->getPiece(toRow, toColumn)->getColor()))
            {
                return false;
            }
        }



        if (this->piece_color == White)
        {
            if (!capture) 
            {
                if (toColumn == this->piece_column)
                {
                    if (this->piece_row - toRow == 2 && (this->piece_row == this->piece_board->getNumRows() - 2) && (this->piece_board->getPiece(this->piece_row - 1, this->piece_column) == nullptr))
                    {
                        return true;
                    }
                    else if (this->piece_row - toRow == 1 && toRow >= 0)
                    {
                        return true;
                    }
                }
            } 
            else 
            {
                if (toColumn == this->piece_column + 1 || toColumn == this->piece_column - 1)
                {

                    if (this->piece_row - toRow == 1 && toRow >= 0)
                    {
                    
                        return true;
                    }
                }
            }
        }
        else
        {
            if (!capture) 
            {
                if (toColumn == this->piece_column)
                {
                    if (toRow - this->piece_row == 2 && (this->piece_row == 1) && (this->piece_board->getPiece(this->piece_row + 1, this->piece_column) == nullptr))
                    {
                        return true;
                    }
                    else if (toRow - this->piece_row == 1 && toRow <= this->piece_board->getNumRows() - 1)
                    {
                        return true;
                    }
                }
            }
            else 
            {
                if (toColumn == this->piece_column + 1 || toColumn == this->piece_column - 1)
                {
                    if (toRow - this->piece_row == 1 && toRow <= this->piece_board->getNumRows() - 1)
                    {
                        return true;
                    }
                }
            }
        }

        return false;
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