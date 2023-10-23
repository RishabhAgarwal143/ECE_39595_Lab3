#include <assert.h>
#include "Chess.h"
#include "ChessBoard.hh"
#include "ChessPiece.hh"
#include <iostream>

using namespace std;

void test_ChessBoard_Constructor() {
    int rows = 4;
    int cols = 5;
    Student::ChessBoard sBoard(rows, cols);
    assert(sBoard.getNumRows() == rows);
    assert(sBoard.getNumCols() == cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            assert(sBoard.getPiece(i, j) == nullptr);
        }
    }
}

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
    
    sBoard.createChessPiece(White, Rook, 3, 2);
    sBoard.createChessPiece(Black, Bishop, 1, 3);
    sBoard.createChessPiece(Black, Rook, 1, 1);
    sBoard.createChessPiece(White, Rook, 2, 3);
    
    Student::ChessPiece* piece = sBoard.getPiece(3,2);
    std::cout << piece->getColumn() << std::endl;
    std::cout << piece->getRow() << std::endl;
    assert(piece->getColor() == White);
    assert(piece->getRow() == 3);
    assert(piece->getColumn() == 2);
    assert(piece->getType() == Rook);

    piece->setPosition(0, 0);
    assert(piece->getRow() == 0);
    assert(piece->getColumn() == 0);


    cout << sBoard.displayBoard().str() << endl;

    // sBoard.movePiece(1,3,0,2);
    cout << sBoard.isPieceUnderThreat(0,2) << endl;
    cout << sBoard.displayBoard().str() << endl;


    // Calls isValidMove() from every position to every
    // other position on the chess board for all pieces.

    return;
}

void test_pawn_move() {
    Student::ChessBoard sBoard(10, 10);

    sBoard.createChessPiece(White, Pawn, 8, 2);
    Student::ChessPiece* piece = sBoard.getPiece(8,2);
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (i == 7 && j == 2 || i == 6 && j == 2) {
                assert(piece->canMoveToLocation(i, j) == true);
            } else {
                assert(piece->canMoveToLocation(i, j) == false);
            }
        }
    }
    sBoard.createChessPiece(Black, Rook, 7, 3);
    sBoard.createChessPiece(White, Rook, 7, 1);
    sBoard.createChessPiece(White, Pawn, 7, 2);

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (i == 7 && j == 3) {
                assert(piece->canMoveToLocation(i, j) == true);
            } else {
                // std::cout << "Piece type: " << piece->getType() << std::endl;
                // std::cout << "Piece Row: " << piece->getRow() << std::endl;
                // std::cout << "Piece Column: " << piece->getColumn() << std::endl;
                // std::cout << "MOVE TO: " << i << ", " << j << "\n";
                // std::cout << sBoard.displayBoard().str() << std::endl;
                assert(piece->canMoveToLocation(i, j) == false);
            }
        }
    }
}

void test_rook_move() {
    Student::ChessBoard sBoard(10, 10);

    sBoard.createChessPiece(White, Rook, 8, 2);
    Student::ChessPiece* piece = sBoard.getPiece(8,2);
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (i == 8 || j == 2) {
                if (i == 8 && j == 2) {
                    assert(piece->canMoveToLocation(i, j) == false);
                }
                else {
                    std::cout << "Piece type: " << piece->getType() << std::endl;
                    std::cout << "Piece Row: " << piece->getRow() << std::endl;
                    std::cout << "Piece Column: " << piece->getColumn() << std::endl;
                    std::cout << "MOVE TO: " << i << ", " << j << "\n";
                    std::cout << sBoard.displayBoard().str() << std::endl;
                    assert(piece->canMoveToLocation(i, j) == true);
                }
            } else {
                assert(piece->canMoveToLocation(i, j) == false);
            }
        }
    }
    sBoard.createChessPiece(Black, Rook, 8, 6);
    sBoard.createChessPiece(White, Rook, 8, 1);
    sBoard.createChessPiece(White, Pawn, 5, 2);

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (i == 8 && j == 6) {
                assert(piece->canMoveToLocation(i, j) == true);
            }
            if (i == 8 && j  == 1) {
                assert(piece->canMoveToLocation(i, j) == false);
            }
            if (i == 5 && j  == 2) {
                assert(piece->canMoveToLocation(i, j) == false);
            }
        }
    }
}

// int main() {
//     test_ChessBoard_Constructor();
//     test_part1_4x4_1();
//     // test_pawn_move();
//     // test_rook_move();
//     return EXIT_SUCCESS;
// }


// #include <assert.h>
// #include "Chess.h"
// #include "ChessBoard.hh"
// #include <iostream>
// #include "ChessPiece.hh"

// void test_part1_4x4_1()
// {
//     // Config file content:
//     // 0
//     // 4 4
//     // w r 3 2
//     // b b 1 3
//     // b r 1 1
//     // w r 2 3
//     // ~
//     // isValidScan

//     // Corresponding code
//     Student::ChessBoard sBoard(4, 4);
//     // sBoard.createChessPiece(White, Pawn, 2, 2);
//     // sBoard.createChessPiece(Black, Pawn, 1, 1);


//     sBoard.createChessPiece(White, Rook, 3, 2);
//     sBoard.createChessPiece(Black, Bishop, 1, 3);
//     sBoard.createChessPiece(Black, Rook, 1, 1);
//     sBoard.createChessPiece(White, Rook, 2, 3);
    
//     // std::cout << "Hey " << sBoard.isValidMove(1, 1, 2, 2) << std::endl;;
//     std::cout << sBoard.displayBoard().str() << std::endl;

//     // Calls isValidMove() from every position to every
//     // other position on the chess board for all pieces.

//     return;
// }

// int main()
// {
//     test_part1_4x4_1();
//     return EXIT_SUCCESS;
// }
