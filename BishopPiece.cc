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
        if (toRow == this->piece_row && toColumn == this->piece_column)
        {
            return false;
        }

        if (toRow < 0 || (toRow > this->piece_board->getNumRows() - 1) || toColumn < 0 || toColumn > this->piece_board->getNumCols() - 1)
        {
            return false;
        }

        int curRow = this->piece_row;
        int curColumn = this->piece_column;

        if (abs(toRow - curRow) == abs(toColumn - curColumn))
        {
            while(curRow != toRow || curColumn != toColumn)
            {
                if (curRow < toRow)
                {
                    curRow++;
                }
                else
                {
                    curRow--;
                }

                if (curColumn < toColumn)
                {
                    curColumn++;
                }
                else
                {
                    curColumn--;
                }

                if (this->piece_board->getPiece(curRow, curColumn) != nullptr)
                {
                    if (curColumn == toColumn && this->piece_color != this->piece_board->getPiece(curRow, curColumn)->getColor()) {
                        return true;
                    }
                    return false;
                }
            }

            if (this->piece_board->getPiece(toRow, toColumn) != nullptr)
            {
                if (this->piece_board->getPiece(toRow, toColumn)->getColor() == this->piece_color)
                {
                    return false;
                }
            }

            return true;
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