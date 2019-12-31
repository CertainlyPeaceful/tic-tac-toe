#pragma once

void PrintBoard(char const board[9]);
short GetIndex(short row, short col);
void AddPosition(char board[9], short row, short col, bool circle);
bool ValidPosition(char const board[9], short row, short col);
bool IsWinner(char const board[9]);