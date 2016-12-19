#include <SFML/Graphics.hpp>

void initializeGridValues(unsigned int &width, unsigned int &height, unsigned int &nuberSquareWidth, unsigned int &nuberSquareHeight, unsigned int &squareSize, unsigned int &offset);
void drawGrid(unsigned int &width, unsigned int &height, unsigned int &squareSize, unsigned int &offset, sf::RenderWindow &window, sf::VertexArray &square);

int main()
{
	unsigned int width;
	unsigned int height;
	unsigned int nuberSquareWidth = 50;
	unsigned int nuberSquareHeight = 30;
	unsigned int squareSize = 20;
	unsigned int offset = 1;

	initializeGridValues(width, height, nuberSquareWidth, nuberSquareHeight, squareSize, offset);

	sf::RenderWindow window(sf::VideoMode(width, height), "Etienne's Game Of Life!");
	sf::VertexArray square(sf::Quads, 4);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();
		
		drawGrid(width, height, squareSize, offset, window, square);
		
		window.display();
	}

	return 0;
}



void initializeGridValues(unsigned int &width, unsigned int &height, unsigned int &nuberSquareWidth, unsigned int &nuberSquareHeight, unsigned int &squareSize, unsigned int &offset)
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

void drawGrid(unsigned int &width, unsigned int &height, unsigned int &squareSize, unsigned int &offset, sf::RenderWindow &window, sf::VertexArray &square)
{

	float previousY = 0;
	for (size_t j = 0; j < height; j += squareSize)
	{
		unsigned int offsetv;
		if (j == 0)
		{
			offsetv = 0;
		}
		else
		{
			offsetv = offset;
		}
		float previousX = 0;

		for (size_t i = 0; i < width; i += squareSize)
		{
			unsigned int offseth;
			if (i == 0)
			{
				offseth = 0;
			}
			else
			{
				offseth = offset;
			}

			square[0].position = sf::Vector2f(previousX + offseth, previousY + offsetv);
			square[0].color = sf::Color::White;
			square[1].position = sf::Vector2f(previousX + squareSize + offseth, previousY + offsetv);
			square[1].color = sf::Color::White;
			square[2].position = sf::Vector2f(previousX + squareSize + offseth, previousY + squareSize + offsetv);
			square[2].color = sf::Color::White;
			square[3].position = sf::Vector2f(previousX + offseth, previousY + squareSize + offsetv);
			//square[3].color = sf::Color::Black;
			previousX = previousX + squareSize + offseth;
			window.draw(square);
		}
		previousY = previousY + squareSize + offsetv;
	}
}