#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "square.h"

void initializeWindowGridValues(int &width, int &height, int &numberSquareWidth, int &numberSquareHeight, int &squareSize, const int &offset);
void initiatlizeGrid(const int &numberSquareWidth, const int &numberSquareHeight, const int &squareSize, const int &offset, std::vector<std::vector<Square>> &matrix);
void drawGrid(sf::RenderWindow &window, const std::vector<std::vector<Square>> &matrix);

int main()
{
	int width;
	int height;
	int numberSquareWidth = 15;
	int numberSquareHeight = 15;
	int squareSize = 20;
	int offset = 1;
	initializeWindowGridValues(width, height, numberSquareWidth, numberSquareHeight, squareSize, offset);

	sf::RenderWindow window(sf::VideoMode(width, height), "Stephan's Game Of Life!");
	std::vector<std::vector<Square>> matrix(numberSquareWidth, std::vector<Square>(numberSquareHeight));
	initiatlizeGrid(numberSquareWidth, numberSquareHeight, squareSize, offset, matrix);
	
	while (window.isOpen())
	{
		sf::Event event;
		sf::Vector2i cursorPos;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			//if (event.type == sf::Event::MouseMoved)
			//{
			//	cursorPos = sf::Mouse::getPosition(window);
			//}

			//if (event.type == sf::Event::MouseEntered)
			//{
			//	for (auto &vector : matrix)
			//	{
			//		for (auto &square : vector)
			//		{
			//			std::cout << "Position of cursor: " << cursorPos.x << "," << cursorPos.y << std::endl;
			//			if (square.getGlobalBounds().contains(static_cast<sf::Vector2f>(cursorPos))) //does square contain position of cursor?
			//			{	
			//				square.setFillColor(sf::Color::Yellow);
			//			}
			//		}
			//	}
			//}
		}
		window.clear(sf::Color::Black);
		drawGrid(window, matrix);
		window.display();
	}
	return 0;
}



void initializeWindowGridValues(int &width, int &height, int &nuberSquareWidth, int &nuberSquareHeight, int &squareSize, const int &offset)
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

void initiatlizeGrid(const int &numberSquareWidth, const int &numberSquareHeight, const int &squareSize, const int &offset, std::vector<std::vector<Square>> &matrix)
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
			int offseth;
			if (col == 0)
			{
				offseth = 0;
			}
			else
			{
				offseth = offset;
			}
			Square square(squareSize);
			square.setPosition(previousX + offseth, previousY + offsetv);
			matrix[row][col] = square;
			//std::cout << "Square position:" << row << "," << col << " x:" << square.getPosition().x << " y:" << square.getPosition().y << std::endl;
			previousX = previousX + squareSize + offseth;
		}
		previousY = previousY + squareSize + offsetv;
		std::cout << std::endl;
	}
}

void drawGrid(sf::RenderWindow &window, const std::vector<std::vector<Square>> &matrix)
{
	for (const auto &vector : matrix)
	{
		for (const auto &square : vector)
		{
			window.draw(square);
			//std::cout << "Square pos: " << square.getPosition().x << "," << square.getPosition().y << std::endl;
		}
	}
}

