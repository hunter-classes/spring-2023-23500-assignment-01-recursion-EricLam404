#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>

int load_board(std::string *board) {
  for(int i = 0; i < 5; i++){
    board[i] = "00000";
  }
  return 5;
}

bool filled(std::string board[], int lines){
  for (int i = 0; i < lines; i++){
    for(int j = 0; j < lines; j++){
        if(board[i][j] == '0') return false;
    }
  }
  return true;
}

void print_board(std::string board[], int lines){
  std::cout << "[0;0H\n";

  for (int i = 0; i < lines; i++){
    for(int j = 0; j < lines; j++){
        std::cout << board[i][j] << " ";
    }
    std::cout << "\n\n";
  }
  
}

void solve(std::string board[], int lines, int row, int col,bool &solved, int move){
  if(solved || row < 0 || row >= lines || col < 0 || col >= lines){
    return;
  }

  if(board[row][col] == '1' || board[row][col] == '-' ) return;

  board[row][col] = '1';
  sleep(1);
  print_board(board,lines);

  solved = filled(board, lines);

  if (!solved) solve(board,lines,row + 1,col + 2, solved, move + 1);
  if (!solved) solve(board,lines,row + 1,col - 2, solved, move + 1);
  if (!solved) solve(board,lines,row - 1,col + 2, solved, move + 1);
  if (!solved) solve(board,lines,row - 1,col - 2, solved, move + 1);
  if (!solved) solve(board,lines,row + 2,col + 1, solved, move + 1);
  if (!solved) solve(board,lines,row + 2,col - 1, solved, move + 1);
  if (!solved) solve(board,lines,row - 2,col + 1, solved, move + 1);
  if (!solved) solve(board,lines,row - 2,col - 1, solved, move + 1);
}
