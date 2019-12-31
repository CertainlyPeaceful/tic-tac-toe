#include <iostream>

void PrintBoard(char const board[9]) {
	for (short index = 0; index < 9; index++) {
		if (board[index] == 'x')
			std::cout << board[index];
		else if (board[index] == 'o')
			std::cout << board[index];
		else
			std::cout << ' ';
		std::cout << ' ';
		if (index == 2 || index == 5 || index == 8)
			std::cout << '\n';
	}
	std::cout << '\n';
}
short GetIndex(short row, short col) {
	short index = row + col;
	if (row == 1)
		return index - 2;
	else if (row == 3)
		return index + 2;
	return index;
}
void AddPosition(char board[9], short row, short col, bool circle) {
	char fill = ' ';
	short index = GetIndex(row, col);
	if (circle)
		fill = 'o';
	else
		fill = 'x';
	board[index] = fill;
}
bool ValidPosition(char const board[9], short row, short col) {
	short index = GetIndex(row, col);
	if (row > 3 || row < 1 || col > 3 || col < 0)
		return false;
	if (board[index] != 0)
		return false;
	return true;
}
bool IsWinner(char const board[9]) {
	for (int row = 0; row <= 6; row += 3)
		if (board[row] != 0 && board[row] == board[row + 1] && board[row] == board[row + 2])
			return true;
	for (int col = 0; col < 3; col++)
		if (board[col] != 0 && board[col] == board[col + 3] && board[col] == board[col + 6])
			return true;
	if (board[0] != 0 && board[0] == board[4] && board[0] == board[8] || board[2] != 0 && board[2] == board[4] && board[2] == board[6])
		return true;
	return false;
}