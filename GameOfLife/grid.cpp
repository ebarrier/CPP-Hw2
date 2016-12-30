#include "grid.h"
#include "cell.h"
#include <vector>
#include <array>
#include <SFML/Graphics.hpp>
#include <iostream>

Grid::Grid(int numberSquareWidth, int numberSquareHeight, int squareSize, int offset)
	: numberSquareWidth(numberSquareWidth), numberSquareHeight(numberSquareHeight), squareSize(squareSize), offset(offset)
{
	matrix.resize(numberSquareHeight, std::vector<Cell>(numberSquareWidth));
	int previousY = 0;
	for (size_t row = 0; row < numberSquareHeight; row++)
	{
		int offsetv;
		if (row == 0)
		{
			offsetv = 0;
		}
		else
		{
			offsetv = offset;
		}
		int previousX = 0;
		for (size_t col = 0; col < numberSquareWidth; col++)
		{
			int offseth;
			if (col == 0)
			{
				offseth = 0;
			}
			else
			{
				offseth = offset;
			}
			Cell square(squareSize);
			square.setPosition(previousX + offseth, previousY + offsetv);
			square.col = col;
			square.row = row;
			matrix[row][col] = square;
			//std::cout << "Square position:" << row << "," << col << " x:" << square.getPosition().x << " y:" << square.getPosition().y << std::endl;
			previousX = previousX + squareSize + offseth;
		}
		previousY = previousY + squareSize + offsetv;
		//std::cout << std::endl;
	}
}

void Grid::checkLiveNeighbours()
{
	int count = 0;
	for (size_t row = 0; row < numberSquareHeight; row++)
	{
		for (size_t col = 0; col < numberSquareWidth; col++)
		{
			if (row > 0 && row < numberSquareHeight-1 && col > 0 && col < numberSquareWidth-1)
			{
				for (int i = -1; i <= 1; i++)
				{
					for (int j = -1; j <= 1; j++)
					{
						if (i==0 && j == 0)
						{
							break;
						}
						if (matrix[row+i][col+j].getIsAlive())
						{
							count++;
						}
					}
				}
				matrix[row][col].setNumAliveNeighbours(count);
				std::cout << "cell position [" << row << "][" << col << "]: " << count << std::endl;
				count = 0;
			}
		}
	}
}

void Grid::changeSquareLife(const sf::Vector2i &cursorPos, const int &squareSize, const int &offset)
{
	int colIndex = floor((cursorPos.x - (offset * floor(cursorPos.x / squareSize))) / squareSize);
	int rowIndex = floor((cursorPos.y - (offset * floor(cursorPos.y / squareSize))) / squareSize);
	//std::cout << "cell position [" << rowIndex << "][" << colIndex << "]" << std::endl;
	//std::cout << "cell status: " << matrix[rowIndex][colIndex].getIsAlive() << std::endl;
	matrix[rowIndex][colIndex].getIsAlive() ? matrix[rowIndex][colIndex].setIsAlive(false) : matrix[rowIndex][colIndex].setIsAlive(true);
}

std::array<int, 2> Grid::getWidthHeight()
{
	std::array<int, 2> widthHeight;
	int width;
	int height;
	if (numberSquareWidth * squareSize + offset * (numberSquareWidth - 1) > 1800 || numberSquareHeight * squareSize + offset * (numberSquareHeight - 1) > 900)
	{
		numberSquareWidth = floor(1600 / squareSize);
		numberSquareHeight = floor(900 / squareSize);
		width = ceil(numberSquareHeight * squareSize + offset * (numberSquareHeight - 1));
		height = ceil(numberSquareHeight * squareSize + offset * (numberSquareHeight - 1));
	}
	else if (numberSquareWidth < 5 || numberSquareHeight < 5)
	{
		numberSquareHeight = 5;
		numberSquareHeight = 5;
		width = ceil(numberSquareHeight * squareSize + offset * (numberSquareHeight - 1));
		height = ceil(numberSquareHeight * squareSize + offset * (numberSquareHeight - 1));
	}
	else
	{
		width = ceil(numberSquareWidth * squareSize + offset * (numberSquareWidth - 1));
		height = ceil(numberSquareHeight * squareSize + offset * (numberSquareHeight - 1));
	}
	widthHeight[0] = width;
	widthHeight[1] = height;
	return widthHeight;
}

Grid::Grid()
{
}


Grid::~Grid()
{
}
