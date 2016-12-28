#include "game.h"
#include "grid.h"
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

Game::Game(Grid grid, std::string windowTitle)
	: grid(grid), window(sf::VideoMode(grid.getWidthHeight().at(0), grid.getWidthHeight().at(1)), windowTitle) {}

void Game::run()
{
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::MouseMoved)
			{
				cursorPos = sf::Mouse::getPosition(window);
				//std::cout << "Position of cursor: " << cursorPos.x << "," << cursorPos.y << std::endl;
			}

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				changeSquareLife(grid.getMatrix(), cursorPos, grid.getSquareSize(), grid.getOffset());
			}
		}
		//mouseHover(grid.getMatrix(), cursorPos, grid.getSquareSize(), grid.getOffset());
		window.clear(sf::Color::Black);
		drawGrid(window, grid.getMatrix());
		window.display();
	}
}

void  Game::changeSquareLife(std::vector<std::vector<Cell>> &matrix, const sf::Vector2i &cursorPos, const int &squareSize, const int &offset)
{
	int colIndex = floor((cursorPos.x - (offset * floor(cursorPos.x / squareSize))) / squareSize);
	int rowIndex = floor((cursorPos.y - (offset * floor(cursorPos.y / squareSize))) / squareSize);
	std::cout << "cell positiion [" << rowIndex << "][" << colIndex << "]" << std::endl;
	std::cout << "cell status: " << matrix[rowIndex][colIndex].getIsAlive() << std::endl;
	matrix[rowIndex][colIndex].getIsAlive() ? matrix[rowIndex][colIndex].setIsAlive(false) : matrix[rowIndex][colIndex].setIsAlive(true);
}

void Game::drawGrid(sf::RenderWindow &window, const std::vector<std::vector<Cell>> &matrix)
{
	for (const auto &vector : matrix)
	{
		for (const auto &square : vector)
		{
			window.draw(square);
		}
	}
}

Game::Game()
{
}

Game::~Game()
{
}
