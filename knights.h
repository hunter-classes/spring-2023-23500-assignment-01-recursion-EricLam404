#pragma once

int load_board(std::string *maze);
void print_board(std::string maze[], int lines);
void solve(std::string maze[], int lines, int row, int col,bool &solved, int moves);