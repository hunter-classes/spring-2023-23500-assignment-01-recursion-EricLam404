#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>

bool filled(int board[][5], int length){
  for (int i = 0; i < length; i++){
    for(int j = 0; j < length; j++){
        if(board[i][j] == 0) return false;
    }
  }
  return true;
}

void fill_board(int board[][5]){
    for (int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            board[i][j] = 0;
        }
    }
}

void print_board(int board[][5], int length){
    std::cout << "[0;0H\n";

    for(int i = 0; i < length; i++){
        for(int j = 0; j < length; j++){
            if(board[i][j] < 10){
                std::cout << " " << board[i][j] << " ";
            }
            else{
                std::cout << board[i][j] << " ";
            }
        }
        std::cout << "\n\n";
    }
  
}

void solve(int board[][5], int length, int row, int col, int move){
    if(row < 0 || row >= length || col < 0 || col >= length){
        return;
    }
    if(board[row][col] > 0) return;

    board[row][col] = move;
    //print_board(board, length);

    solve(board, length, row + 1, col + 2, move + 1);
    solve(board, length, row + 1, col - 2, move + 1);
    solve(board, length, row - 1, col + 2, move + 1);
    solve(board, length, row - 1, col - 2, move + 1);
    solve(board, length, row + 2, col + 1, move + 1);
    solve(board, length, row + 2, col - 1, move + 1);
    solve(board, length, row - 2, col + 1, move + 1);
    solve(board, length, row - 2, col - 1, move + 1);

    if(filled(board, length)) return;

    board[row][col] = 0;
}