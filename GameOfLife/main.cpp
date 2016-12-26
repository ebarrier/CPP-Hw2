#include <SFML/Graphics.hpp>
#include "square.h"

void initializeGridValues(int &width, int &height, int &nuberSquareWidth, int &nuberSquareHeight, int &squareSize, int &offset);
void drawGrid(int &width, int &height, int &squareSize, int &offset, sf::RenderWindow &window, Square &square);

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
	//sf::RectangleShape square(sf::Vector2f(squareSize, squareSize));
	Square square(squareSize);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear(sf::Color::Black);
		drawGrid(width, height, squareSize, offset, window, square);
		//window.draw(square);
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

void drawGrid(int &width, int &height, int &squareSize, int &offset, sf::RenderWindow &window, Square &square)
{
	int previousY = 0;
	for (size_t j = 0; j < height; j += squareSize)
	{
		int offsetv;
		if (j == 0)
		{
			offsetv = 0;
		}
		else
		{
			offsetv = offset;
		}

		int previousX = 0;
		for (size_t i = 0; i < width; i += squareSize)
		{
			int offseth;
			if (i == 0)
			{
				offseth = 0;
			}
			else
			{
				offseth = offset;
			}

			square.setPosition(previousX + offseth, previousY + offsetv);
			//square.setFillColor(sf::Color::White);
			previousX = previousX + squareSize + offseth;
			window.draw(square);
		}
		previousY = previousY + squareSize + offsetv;
	}
}
