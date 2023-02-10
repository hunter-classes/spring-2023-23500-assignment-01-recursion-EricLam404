#include <iostream>
#include <unistd.h>
#include "knights.h"

int main()
{   
    int length = 5;

    int board[length][5];

    fill_board(board);
    print_board(board, length);
    solve(board, length, 0, 0, 1);
    print_board(board, length);

    return 0;
}