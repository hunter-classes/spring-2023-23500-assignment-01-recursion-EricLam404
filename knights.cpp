#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>

bool filled(int board[], int length){
  for (int i = 0; i < length; i++){
    for(int j = 0; j < length; j++){
        if(board[(i * length) + j] == 0) return false;
    }
  }
  return true;
}

void fill_board(int *board){
    for(int i = 0; i < 25; i++){
        board[i] = 0;
    }
}

void print_board(int board[], int length){
    std::cout << "[0;0H\n";

    for(int i = 0; i < length; i++){
        for(int j = 0; j < length; j++){
            int s = (i * length) + j;
            if(board[(i * length) + j] < 10){
                std::cout << " " << board[s] << " ";
            }
            else{
                std::cout << board[s] << " ";
            }
        }
        std::cout << "\n\n";
    }
  
}

void solve(int board[], int length, int row, int col, int move){
    if(row < 0 || row >= length || col < 0 || col >= length){
        return;
    }
    int curr = (row * length) + col;
    if(board[curr] > 0) return;

    board[curr] = move;
    print_board(board, length);

    solve(board, length, row + 1, col + 2, move + 1);
    solve(board, length, row + 1, col - 2, move + 1);
    solve(board, length, row - 1, col + 2, move + 1);
    solve(board, length, row - 1, col - 2, move + 1);
    solve(board, length, row + 2, col + 1, move + 1);
    solve(board, length, row + 2, col - 1, move + 1);
    solve(board, length, row - 2, col + 1, move + 1);
    solve(board, length, row - 2, col - 1, move + 1);

    if(filled(board, length)) return;
    
    board[curr] = 0;
}