#include "ChessBoard.hh"
#include "PawnPiece.hh"
#include "RookPiece.hh"
#include "BishopPiece.hh"
#include "KingPiece.hh"

using Student::ChessBoard;

ChessBoard::ChessBoard(int numRow, int numCol)
{
    // this->numCols = numCol;
    // this->numRows = numRow;
    // for (int i = 0; i < numRow; i++)
    // {
    //     for (int j = 0; j < numRow; j++)
    //     {
    //         ChessPiece* ptr = nullptr;
    //         this->board.at(i).at(j) = ptr;
    //     }
    // }
}

void ChessBoard::createChessPiece(Color col, Type ty, int startRow, int startColumn)
{
    ChessPiece *current_piece = nullptr;
    if (ty == Pawn)
    {
        current_piece = new PawnPiece(*this, col, startRow, startColumn);
    }
    // else if (ty == Rook)
    // {
    //     current_piece = new RookPiece(*this,col,startRow,startColumn);
    // }
    // else if(ty == Bishop){
    //     current_piece = new BishopPiece(*this,col,startRow,startColumn);
    // }
    // else{
    //     current_piece = new KingPiece(*this,col,startRow,startColumn);
    // }

    if (board.at(startRow).at(startColumn) != nullptr)
    {
        ChessPiece *x = board.at(startRow).at(startColumn);
        delete x;
    }

    board.at(startRow).at(startColumn) = current_piece;
}

// This function is only needed for Part 2 and Part 3.
bool ChessBoard::movePiece(int fromRow, int fromColumn, int toRow, int toColumn)
{
    return false;
}

bool ChessBoard::isValidMove(int fromRow, int fromColumn, int toRow, int toColumn)
{
    if (toRow > this->numRows || toColumn > this->numCols)
    {
        return false;
    }
    if (fromRow == toRow && fromColumn == toColumn)
    {
        return false;
    }
    if (board.at(fromRow).at(fromColumn) == nullptr)
    {
        return false;
    }
    ChessPiece *current_piece = board.at(fromRow).at(fromColumn);
    if (current_piece->getColor() != this->turn)
    {
        return false;
    }

    if (!current_piece->canMoveToLocation(toRow, toColumn))
    {
        return false;
    }

    if (board.at(toRow).at(toColumn) != nullptr)
    {
        if (board.at(toRow).at(toColumn)->getColor() == current_piece->getColor())
        {
            return false;
        }
    }

    return true;
}

// This function is only needed for Part 2 and Part 3.
bool ChessBoard::isPieceUnderThreat(int row, int column)
{
    return false;
}

std::ostringstream ChessBoard::displayBoard()
{
    std::ostringstream outputString;
    // top scale
    outputString << "  ";
    for (int i = 0; i < numCols; i++)
    {
        outputString << i;
    }
    outputString << std::endl
                 << "  ";
    // top border
    for (int i = 0; i < numCols; i++)
    {
        outputString << "-";
    }
    outputString << std::endl;

    for (int row = 0; row < numRows; row++)
    {
        outputString << row << "|";
        for (int column = 0; column < numCols; column++)
        {
            ChessPiece *piece = board.at(row).at(column);
            outputString << (piece == nullptr ? " " : piece->toString());
        }
        outputString << "|" << std::endl;
    }

    // bottom border
    outputString << "  ";
    for (int i = 0; i < numCols; i++)
    {
        outputString << "-";
    }
    outputString << std::endl
                 << std::endl;

    return outputString;
}
