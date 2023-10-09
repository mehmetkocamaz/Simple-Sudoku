#pragma once
#include <iostream>
#include <math.h>
#include <chrono>
#include <random>
#include <time.h>
#include <thread>
#include <array>

const int PUZZLE_SIZE = 9;
const int EMPTY_VALUE = 0;
std::array<int, 9> values = { 1,2,3,4,5,6,7,8,9 };

void PrintPuzzle(int puzzle[PUZZLE_SIZE][PUZZLE_SIZE]) {
	for (size_t i = 0; i < PUZZLE_SIZE; i++)
	{
		for (size_t j = 0; j < PUZZLE_SIZE; j++)
		{
			if (ceil(j % 3) == 0)
			{
				if (j != 0)
				{
					std::cout << " - ";
				}
				if (ceil(j % 9) == 0 && i != 0) {
					std::cout << "\n----------------\n";
				}
			}
			std::cout << puzzle[i][j];
		}
	}
}

bool IsValid(int puzzle[PUZZLE_SIZE][PUZZLE_SIZE], int row, int column, int value) {
	// Checking the row
	for (int c = 0; c < PUZZLE_SIZE; c++) {
		if (puzzle[row][c] == value)
			return false;
	}

	// Checking the column
	for (int r = 0; r < PUZZLE_SIZE; r++) {
		if (puzzle[r][column] == value)
			return false;
	}

	// Checking the 3x3 Grid
	int startRow = floor(row / 3) * 3;
	int startColumn = floor(column / 3) * 3;
	for (size_t r = startRow; r < startRow + 3; r++) {
		for (size_t c = startColumn; c < startColumn +3; c++)
		{
			if (puzzle[r][c] == value)
				return false;
		}
	}

	return true;
}

bool HasEmptyCell(int puzzle[PUZZLE_SIZE][PUZZLE_SIZE]) {
	for (size_t i = 0; i < PUZZLE_SIZE; i++)
	{
		for (size_t j = 0; j < PUZZLE_SIZE; j++)
		{
			if (puzzle[i][j] == EMPTY_VALUE)
				return true;
		}
	}

	return false;
}

bool FillPuzzle(int(&puzzle)[PUZZLE_SIZE][PUZZLE_SIZE]) {

	int row, column;

	for (size_t i = 0; i < PUZZLE_SIZE * PUZZLE_SIZE; i++)
	{
		row = floor(i / PUZZLE_SIZE);
		column = i % PUZZLE_SIZE;
	
		if (puzzle[row][column] == EMPTY_VALUE)
		{
			unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
			std::shuffle(values.begin(), values.end(), std::default_random_engine(seed));

			for (size_t j = 0; j < PUZZLE_SIZE; j++)
			{
				if (IsValid(puzzle, row, column, values[j])) {
					puzzle[row][column] = values[j];

					if (!HasEmptyCell(puzzle) || FillPuzzle(puzzle))
					{
						return true;
					}
				}
			}
			break;
		}
	}
	puzzle[row][column] = EMPTY_VALUE;
	return false;
}

void GeneratePuzzle(int(&puzzle)[PUZZLE_SIZE][PUZZLE_SIZE]) {
	for (size_t i = 0; i < PUZZLE_SIZE; i++)
	{
		for (size_t j = 0; j < PUZZLE_SIZE; j++)
		{
			puzzle[i][j] = EMPTY_VALUE;
		}
	}

	FillPuzzle(puzzle);
}
