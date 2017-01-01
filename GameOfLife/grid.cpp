#include "grid.h"
#include "cell.h"
#include <vector>
#include <array>
#include <SFML/Graphics.hpp>
#include <iostream>

Grid::Grid(int numberSquareWidth, int numberSquareHeight, int squareSize, int offset)
	: numberSquareWidth(numberSquareWidth), numberSquareHeight(numberSquareHeight), squareSize(squareSize), offset(offset)
{
	//make the matrix big enough for all elements
	matrix.resize(numberSquareHeight, std::vector<Cell>(numberSquareWidth)); 

	int previousY = 0; //store Y coordinate of previous cell to start from it for next one
	for (size_t row = 0; row < numberSquareHeight; row++)
	{
		int offsetv; //gap between two cells in vertical position (one up and one down)
		if (row == 0)
		{
			offsetv = 0; //for first row of cells, no gap between the window's top and the cells
		}
		else
		{
			offsetv = offset;
		}
		int previousX = 0; //store X coordinate of previous cell to start from it for next one
		for (size_t col = 0; col < numberSquareWidth; col++)
		{
			int offseth; //gap between two cells in horizontal position (one left and one right)
			if (col == 0)
			{
				offseth = 0; //for first col of cells, no gap between the window's left and the cells
			}
			else
			{
				offseth = offset;
			}
			Cell square(squareSize);
			square.setPosition(previousX + offseth, previousY + offsetv);
			matrix[row][col] = square;
			//std::cout << "Square position:" << row << "," << col << " x:" << square.getPosition().x << " y:" << square.getPosition().y << std::endl;
			previousX = previousX + squareSize + offseth;
		}
		previousY = previousY + squareSize + offsetv;
		//std::cout << std::endl;
	}
}

void Grid::resetGrid()
{
	std::cout << "resetGrid Called" << std::endl;
	for (auto &vector : matrix)
	{
		for (auto &cell : vector)
		{
			cell.setIsAlive(false);
		}
	}
}

void Grid::nextGeneration()
{
	for (auto &vector : matrix)
	{
		for (auto &cell : vector)
		{
			//If a live cell has fewer than two live neighbours, it dies
			if (cell.getIsAlive() && cell.getNumAliveNeighbours() < 2)
				cell.setIsAlive(false);

			//If a live cell has two or three live neighbours, it lives
			if (cell.getIsAlive() && (cell.getNumAliveNeighbours() == 2 || cell.getNumAliveNeighbours() == 3))
				cell.setIsAlive(true);

			//If a live cell has more than five live neighbours, it dies
			if (cell.getIsAlive() && cell.getNumAliveNeighbours() > 3)
				cell.setIsAlive(false);

			//If a dead cell has three live neighbours, it becomes alive
			if (!cell.getIsAlive() && cell.getNumAliveNeighbours() == 3)
				cell.setIsAlive(true);
		}
	}
}

//For each cell, count number of live neighbours
void Grid::checkLiveNeighbours()
{
	int count = 0;
	for (size_t row = 0; row < numberSquareHeight; row++)
	{
		for (size_t col = 0; col < numberSquareWidth; col++)
		{
			//top row of grid
			if (row == 0)
			{
				//top-left cell of grid
				if (col == 0)
				{
					if (matrix[row][col + 1].getIsAlive())
						count++;
					if (matrix[row + 1][col].getIsAlive())
						count++;
					if (matrix[row + 1][col + 1].getIsAlive())
						count++;
				}

				//top-right cell of grid
				if (col == numberSquareWidth - 1)
				{
					if (matrix[row][col - 1].getIsAlive())
						count++;
					if (matrix[row + 1][col - 1].getIsAlive())
						count++;
					if (matrix[row + 1][col].getIsAlive())
						count++;
				}

				//top-middle cells of grid
				if (col > 0 && col < numberSquareWidth - 1)
				{
					if (matrix[row][col - 1].getIsAlive())
						count++;
					if (matrix[row][col + 1].getIsAlive())
						count++;
					if (matrix[row + 1][col - 1].getIsAlive())
						count++;
					if (matrix[row + 1][col].getIsAlive())
						count++;
					if (matrix[row + 1][col +1].getIsAlive())
						count++;
				}
			}

			//bottom row of grid
			if (row == numberSquareHeight - 1)
			{
				//bottom-left cell of grid
				if (col == 0)
				{
					if (matrix[row][col + 1].getIsAlive())
						count++;
					if (matrix[row - 1][col].getIsAlive())
						count++;
					if (matrix[row - 1][col + 1].getIsAlive())
						count++;
				}

				//bottom-right cell of grid
				if (col == numberSquareWidth - 1)
				{
					if (matrix[row][col - 1].getIsAlive())
						count++;
					if (matrix[row - 1][col - 1].getIsAlive())
						count++;
					if (matrix[row - 1][col].getIsAlive())
						count++;
				}

				//bottom-middle cells of grid
				if (col > 0 && col < numberSquareWidth - 1)
				{
					if (matrix[row][col - 1].getIsAlive())
						count++;
					if (matrix[row][col + 1].getIsAlive())
						count++;
					if (matrix[row - 1][col - 1].getIsAlive())
						count++;
					if (matrix[row - 1][col].getIsAlive())
						count++;
					if (matrix[row - 1][col + 1].getIsAlive())
						count++;
				}
			}

			//left-middle cells of grid
			if (col == 0 && row > 0 && row < numberSquareHeight - 1)
			{
				if (matrix[row - 1][col].getIsAlive())
					count++;
				if (matrix[row - 1][col + 1].getIsAlive())
					count++;
				if (matrix[row][col + 1].getIsAlive())
					count++;
				if (matrix[row + 1][col].getIsAlive())
					count++;
				if (matrix[row + 1][col + 1].getIsAlive())
					count++;
			}

			//right-middle cells of grid
			if (col == numberSquareWidth - 1 && row > 0 && row < numberSquareHeight - 1)
			{
				if (matrix[row - 1][col].getIsAlive())
					count++;
				if (matrix[row - 1][col - 1].getIsAlive())
					count++;
				if (matrix[row][col - 1].getIsAlive())
					count++;
				if (matrix[row + 1][col].getIsAlive())
					count++;
				if (matrix[row + 1][col - 1].getIsAlive())
					count++;
			}

			//middle cells of grid
			if (row > 0 && row < numberSquareHeight - 1 && col > 0 && col < numberSquareWidth - 1)
			{
				for (int i = -1; i <= 1; i++)
				{
					for (int j = -1; j <= 1; j++)
					{
						if (i == 0 && j == 0) //skip cell we are focusing on
							continue;
						if (matrix[row + i][col + j].getIsAlive())
							count++;
					}
				}
			}
			matrix[row][col].setNumAliveNeighbours(count);
			//std::cout << "cell position [" << row << "][" << col << "]: " << count << std::endl;
			count = 0;
		}
	}
}

//Change the life status of the cell under the cursos
void Grid::changeSquareLife(const sf::Vector2i &cursorPos, const int &squareSize, const int &offset)
{
	int colIndex = floor((cursorPos.x - (offset * floor(cursorPos.x / squareSize))) / squareSize);
	int rowIndex = floor((cursorPos.y - (offset * floor(cursorPos.y / squareSize))) / squareSize);
	matrix[rowIndex][colIndex].getIsAlive() ? matrix[rowIndex][colIndex].setIsAlive(false) : matrix[rowIndex][colIndex].setIsAlive(true);
	//std::cout << "cell position [" << rowIndex << "][" << colIndex << "]" << std::endl;
	//std::cout << "cell status: " << matrix[rowIndex][colIndex].getIsAlive() << std::endl;
}

/*
Depending on number of cells for width/height, cell size and offet, determine best widht and height for the windows (in pixels)
This is to avoid extreme large/small windows
*/
std::array<int, 2> Grid::getWidthHeight()
{
	std::array<int, 2> widthHeight;
	int width;
	int height;
	//if grid values are too big, set a max
	if (numberSquareWidth * squareSize + offset * (numberSquareWidth - 1) > 1800 || numberSquareHeight * squareSize + offset * (numberSquareHeight - 1) > 900)
	{
		numberSquareWidth = floor(1600 / squareSize);
		numberSquareHeight = floor(900 / squareSize);
		width = ceil(numberSquareHeight * squareSize + offset * (numberSquareHeight - 1));
		height = ceil(numberSquareHeight * squareSize + offset * (numberSquareHeight - 1));
	}
	//if grid values are too big, set a minimun
	else if (numberSquareWidth < 5 || numberSquareHeight < 5)
	{
		numberSquareHeight = 5;
		numberSquareHeight = 5;
		width = ceil(numberSquareHeight * squareSize + offset * (numberSquareHeight - 1));
		height = ceil(numberSquareHeight * squareSize + offset * (numberSquareHeight - 1));
	}
	//otherwise set the values chosen
	else
	{
		width = ceil(numberSquareWidth * squareSize + offset * (numberSquareWidth - 1));
		height = ceil(numberSquareHeight * squareSize + offset * (numberSquareHeight - 1));
	}
	widthHeight[0] = width;
	widthHeight[1] = height;
	return widthHeight;
}

void Grid::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (const auto vector : matrix)
	{
		for (const auto square : vector)
		{
			target.draw(square, states);
		}
	}
}

Grid::Grid()
{
}


Grid::~Grid()
{
}
