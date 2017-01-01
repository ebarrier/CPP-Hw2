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
	std::vector<std::vector<Cell>>& getMatrix() { return matrix; }
	int getOffset() { return offset; }
	int getSquareSize() { return squareSize; }

	void Grid::drawGrid(sf::RenderWindow &window);
	std::array<int, 2> getWidthHeight();
	void changeSquareLife(const sf::Vector2i &cursorPos, const int &squareSize, const int &offset);
	void checkLiveNeighbours();
	void nextGeneration();

	Grid();
	~Grid();
};

#endif