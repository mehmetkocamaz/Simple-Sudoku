#include <iostream>
#include "Functions.h"

int main() {

	int puzzle[PUZZLE_SIZE][PUZZLE_SIZE];
	GeneratePuzzle(puzzle);
	PrintPuzzle(puzzle);

	std::string choice;
	std::cout << "Do you want to run algorithm to solve this puzzle (y/n): ";
	std::cin >> choice;

	if (choice == "N" || choice == "n")
	{
		return 0;
	}
	SolveSudoku(puzzle, true);


	return 0;
}