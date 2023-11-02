#include <iostream>
#include <stdio.h>
#include <string.h>
#include "ChessBoard.hh"
#include "ChessPiece.hh"

int main(int argc, char** argv) {

    
    // Student::ChessBoard board(4,4);
    // board.createChessPiece(White, King, 2,0);
    // board.createChessPiece(Black, King, 1,2);
    // board.createChessPiece(White, Rook, 2,2);
    // std::cout << "INITAL BOARD: \n";
    // std::cout << board.displayBoard().str();
    
    // std::cout <<  board.movePiece(2,0,3,0)<< std::endl;
    // std::cout <<  board.isValidMove(1,2,0,2)<< std::endl;

    // std::cout <<  board.movePiece(1,2,1,3)<< std::endl;
    // std::cout <<  board.movePiece(2,2,2,0)<< std::endl;
    // std::cout <<  board.movePiece(1,3,0,2)<< std::endl;
    // std::cout <<  board.movePiece(2,0,2,1)<< std::endl;
    // std::cout <<  board.movePiece(0,2,0,3)<< std::endl;
    // std::cout <<  board.movePiece(3,0,2,0)<< std::endl;
    

    // std::cout << board.displayBoard().str();

    char* test_path = argv[1];
// 

    FILE* test_file = fopen(test_path, "r");

    if (test_file == NULL) {
        printf("File not found\n");
        return 1;
    }

    // create board with data in file
    int num_rows, num_cols;
    int points;
    fscanf(test_file, "%d\n", &points);
    fscanf(test_file, "%d %d\n", &num_rows, &num_cols);

    Student::ChessBoard board(num_rows, num_cols);

    // piece color type row column is in next line
    char piece_color_int;
    char piece_type_int;
    Color piece_color;
    Type piece_type;
    int piece_row, piece_col;
    
    // int test = fscanf(test_file, "%c %c %d %d\n", &piece_color_int, &piece_type_int, &piece_row, &piece_col);
    // std::cout << test << "\n";
    while (fscanf(test_file, "%c %c %d %d\n", &piece_color_int, &piece_type_int, &piece_row, &piece_col) == 4) {
        if (piece_color_int == 'w') {
            piece_color = White;
        } else {
            piece_color = Black;
        }

        if (piece_type_int == 'r') {
            piece_type = Rook;
        } else if (piece_type_int == 'b') {
            piece_type = Bishop;
        } else if (piece_type_int == 'k') {
            piece_type = King;
        } else {
            piece_type = Pawn;
        }

        board.createChessPiece(piece_color, piece_type, piece_row, piece_col);
    }
//     // board.createChessPiece(Black, Bishop, 3, 3);
    std::cout << "INITAL BOARD: \n";
    std::cout << board.displayBoard().str();
    std::cout << board.movePiece(0,1,1,2) << std::endl;
    std::cout << board.movePiece(0,2,2,0) << std::endl;
    std::cout << board.movePiece(0,7,0,6) << std::endl;
    
//     std::cout << board.movePiece(1,3,0,2) << std::endl;
//     std::cout << board.movePiece(2,3,1,3) << std::endl;
//     std::cout << board.movePiece(1,1,0,1) << std::endl;
//     std::cout << board.movePiece(1,2,0,3) << std::endl;
//     std::cout << board.movePiece(2,0,3,0) << std::endl;
//     std::cout << board.movePiece(0,1,2,1) << std::endl;
//     std::cout << board.movePiece(3,2,0,2) << std::endl;
//     std::cout << board.movePiece(2,1,0,1) << std::endl;




    // std::cout << board.isValidMove(2,0,2,1) << std::endl;
    // std::cout << board.isValidMove(1,3,1,1) << std::endl;
    // std::cout << board.movePiece(1,3,1,1) << std::endl;
    // std::cout << board.isPieceUnderThreat(1,3) << std::endl;
    // std::cout << board.isPieceUnderThreat(1,1) << std::endl;
    // std::cout << board.isPieceUnderThreat(2,3) << std::endl;
    // std::cout <<  board.movePiece(1,0,3,0)<< std::endl;
    // std::cout << board.displayBoard().str();

    // std::cout <<  board.movePiece(0,1,1,1)<< std::endl;
    // std::cout << board.displayBoard().str();

    // std::cout << board.movePiece(2,2,3,3) << std::endl;
    // std::cout << board.getPiece(2,2)->getType() << std::endl;
    // std::cout << board.movePiece(2,2,3,3) << std::endl;


    std::cout << "Final BOARD: \n";
    std::cout << board.displayBoard().str();


    return 0;
}