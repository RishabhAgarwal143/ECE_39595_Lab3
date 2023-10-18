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
        if (toRow == this->piece_row && toColumn == this->piece_column)
        {
            return false;
        }

        int curRow = this->piece_row;
        int curColumn = this->piece_column;

        // check if rook is moving along a row or column
        if (toRow == this->piece_row || toColumn == this->piece_column)
        {
            while(curRow != toRow || curColumn != toColumn)
            {
                if (curRow != toRow)
                {
                    if (curRow < toRow)
                    {
                        curRow++;
                    }
                    else
                    {
                        curRow--;
                    }
                }
                else
                {
                    if (curColumn < toColumn)
                    {
                        curColumn++;
                    }
                    else
                    {
                        curColumn--;
                    }
                }

                if (this->piece_board->getPiece(curRow, curColumn) != nullptr)
                {
                    return false;
                }
            }
                        
        }
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