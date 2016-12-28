#ifndef GRID_H
#define GRID_H
#include "cell.h"
#include <vector>
#include <array>

class Grid
{
private:
	int numberSquareWidth;
	int numberSquareHeight;
	int squareSize;
	int offset;
	std::vector<std::vector<Cell>> matrix;

public:
	Grid(int numberSquareWidth, int numberSquareHeight, int squareSize, int offset);
	std::array<int, 2> getWidthHeight();
	std::vector<std::vector<Cell>> getMatrix() { return matrix; }

	Grid();
	~Grid();
};

#endif