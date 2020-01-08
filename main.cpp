#include <iostream>
#include "header.h"

int main() {
	char gameBoard[9] = { 0 };
	bool circle = 1;
	short row = 0, col = 0, numTurn = 0;
	
	std::cout << "A game of tic-tac-toe\n";

	while (numTurn < 9 && !IsWinner(gameBoard)) {
		if (numTurn % 2 == 0) {
			std::cout << "Cross' turn, enter row and column: ";
			circle = 0;
		}
		else {
			std::cout << "Circle's turn, enter row and column: ";
			circle = 1;
		}
		std::cin >> row >> col;
		while (!ValidPosition(gameBoard, row, col)) {
			std::cout << "Not a valid position, enter valid row and column: ";
			std::cin >> row >> col;
		}
		AddPosition(gameBoard, row, col, circle);
		PrintBoard(gameBoard);
		numTurn++;
	}
	if (numTurn == 9)
		std::cout << "It is a tie!\n";
	else if (numTurn % 2 == 0)
		std::cout << "Circle wins!\n";
	else
		std::cout << "Cross wins!\n";
	system("PAUSE");
}
