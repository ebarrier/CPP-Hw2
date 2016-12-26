#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "square.h"

void initializeGridValues(int &width, int &height, int &nuberSquareWidth, int &nuberSquareHeight, int &squareSize, int &offset);
void drawGrid2(int &width, int &height, int &numberSquareWidth, int &numberSquareHeight, int &squareSize, int &offset, sf::RenderWindow &window, std::vector<std::vector<Square>> &matrix);

int main()
{
	int width;
	int height;
	int numberSquareWidth = 15;
	int numberSquareHeight = 15;
	int squareSize = 20;
	int offset = 1;
	initializeGridValues(width, height, numberSquareWidth, numberSquareHeight, squareSize, offset);

	sf::RenderWindow window(sf::VideoMode(width, height), "Etienne's Game Of Life!");
	std::vector<std::vector<Square>> matrix(numberSquareWidth, std::vector<Square>(numberSquareHeight));
	
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			//if (event.type == sf::Event::MouseMoved)
			//{
			//	sf::Vector2i localPosition = sf::Mouse::getPosition(window); //get position of cursor


			//}
		}
		window.clear(sf::Color::Black);
		drawGrid2(width, height, numberSquareWidth, numberSquareHeight, squareSize, offset, window, matrix);
		window.display();
	}
	return 0;
}



void initializeGridValues(int &width, int &height, int &nuberSquareWidth, int &nuberSquareHeight, int &squareSize, int &offset)
{
	if (nuberSquareWidth * squareSize + offset * (nuberSquareWidth - 1) > 1800 || nuberSquareHeight * squareSize + offset * (nuberSquareHeight - 1) > 900)
	{
		nuberSquareWidth = floor(1600 / squareSize);
		nuberSquareHeight = floor(900 / squareSize);
		width = ceil(nuberSquareWidth * squareSize + offset * (nuberSquareWidth - 1));
		height = ceil(nuberSquareHeight * squareSize + offset * (nuberSquareHeight - 1));
	}
	else if (nuberSquareWidth < 5 || nuberSquareHeight < 5)
	{
		nuberSquareWidth = 5;
		nuberSquareHeight = 5;
		width = ceil(nuberSquareWidth * squareSize + offset * (nuberSquareWidth - 1));
		height = ceil(nuberSquareHeight * squareSize + offset * (nuberSquareHeight - 1));
	}
	else
	{
		width = ceil(nuberSquareWidth * squareSize + offset * (nuberSquareWidth - 1));
		height = ceil(nuberSquareHeight * squareSize + offset * (nuberSquareHeight - 1));
	}
}

void drawGrid2(int &width, int &height, int &numberSquareWidth, int &numberSquareHeight, int &squareSize, int &offset, sf::RenderWindow &window, std::vector<std::vector<Square>> &matrix)
{
	int previousY = 0;
	for (size_t row = 0; row < numberSquareWidth; row++)
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
		for (size_t col = 0; col < numberSquareHeight; col++)
		{
			Square square(squareSize);
			matrix[row][col] = square;

			int offseth;
			if (col == 0)
			{
				offseth = 0;
			}
			else
			{
				offseth = offset;
			}

			square.setPosition(previousX + offseth, previousY + offsetv);
			window.draw(square);
			previousX = previousX + squareSize + offseth;
		}
		previousY = previousY + squareSize + offsetv;
		std::cout << std::endl;
	}
}

