#include <assert.h>
#include "Chess.h"
#include "ChessBoard.hh"
#include <iostream>
#include "ChessPiece.hh"

void test_part1_4x4_1()
{
    // Config file content:
    // 0
    // 4 4
    // w r 3 2
    // b b 1 3
    // b r 1 1
    // w r 2 3
    // ~
    // isValidScan

    // Corresponding code
    Student::ChessBoard sBoard(4, 4);
    sBoard.createChessPiece(White, Pawn, 2, 2);
    sBoard.createChessPiece(Black, Pawn, 1, 1);
    
    std::cout << "Hey " << sBoard.isValidMove(1, 1, 2, 2) << std::endl;;
    std::cout << sBoard.displayBoard().str() << std::endl;


    // sBoard.createChessPiece(White, Rook, 3, 2);s
    // sBoard.createChessPiece(Black, Bishop, 1, 3);
    // sBoard.createChessPiece(Black, Rook, 1, 1);
    // sBoard.createChessPiece(White, Rook, 2, 3);

    // Calls isValidMove() from every position to every
    // other position on the chess board for all pieces.

    return;
}

int main()
{
    test_part1_4x4_1();
    return EXIT_SUCCESS;
}
