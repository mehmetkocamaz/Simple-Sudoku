#include <iostream>
#include "Functions.h"

int main() {

	int puzzle[PUZZLE_SIZE][PUZZLE_SIZE];
	GeneratePuzzle(puzzle);
	PrintPuzzle(puzzle);
	return 0;
}