#include <iostream>
#include <unistd.h>
#include "knights.h"

int main()
{
  std::string board[5];
  int lines;
  bool solved = false;

  lines = load_board(board);
  print_board(board,lines);
  usleep(80000);

  print_board(board, lines);
  solve(board, lines, 0, 0, solved, 1);
  return 0;
}