#include "ChessBoard.hh"
#include "PawnPiece.hh"
#include "RookPiece.hh"
#include "BishopPiece.hh"
#include "KingPiece.hh"
#include <iostream>
using Student::ChessBoard;

ChessBoard::ChessBoard(int numRow, int numCol)
{
    this->numCols = numCol;
    this->numRows = numRow;
    for (int i = 0; i < numRow; i++)
    {
        std::vector<ChessPiece*> x;
        for (int j = 0; j < numCol; j++)
        { 
            x.push_back(nullptr);
        }
        this->board.push_back(x);
    }
}

void ChessBoard::createChessPiece(Color col, Type ty, int startRow, int startColumn)
{
    if (board.at(startRow).at(startColumn) != nullptr)
    {
        ChessPiece *x = board.at(startRow).at(startColumn);
        delete x;
    }
    if (ty == Pawn)
    {
        ChessPiece* current_piece = new PawnPiece(*this, col, startRow, startColumn);
        board.at(startRow).at(startColumn) = current_piece;
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
        std::cout << "is not valid 1" << std::endl;

        return false;
    }
    if (fromRow == toRow && fromColumn == toColumn)
    {
        std::cout << "is not valid 2" << std::endl;

        return false;
    }
    if (board.at(fromRow).at(fromColumn) == nullptr)
    {
        std::cout << "is not valid 3" << std::endl;

        return false;
    }
    ChessPiece *current_piece = board.at(fromRow).at(fromColumn);
    // if (current_piece->getColor() != this->turn)
    // {
    //     std::cout << "is not valid 4" << std::endl;
    //     return false;
    // }

    if (!current_piece->canMoveToLocation(toRow, toColumn))
    {
        std::cout << "Piece valid" << std::endl;

        return false;
    }

    if (board.at(toRow).at(toColumn) != nullptr)
    {
        if (board.at(toRow).at(toColumn)->getColor() == current_piece->getColor())
        {
            std::cout << "is not valid 5" << std::endl;

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
