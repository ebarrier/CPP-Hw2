#include "game.h"
#include "grid.h"
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

Game::Game(Grid grid, std::string windowTitle)
	: width(grid.getWidthHeight().at(0)), height(grid.getWidthHeight().at(1)), grid(grid), window(sf::VideoMode(width, height), windowTitle) {}

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

			//if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			//{
			//	changeSquareLife(matrix, cursorPos, squareSize, offset);
			//}
		}
		//mouseHover(matrix, cursorPos, squareSize, offset);
		window.clear(sf::Color::Black);
		drawGrid(window, grid.getMatrix());
		window.display();
	}
}

void Game::drawGrid(sf::RenderWindow &window, const std::vector<std::vector<Cell>> &matrix)
{
	for (const auto &vector : matrix)
	{
		for (const auto &square : vector)
		{
			window.draw(square);
			std::cout << "Square position x:" << square.getPosition().x << " y:" << square.getPosition().y << std::endl;
		}
	}
}

Game::Game()
{
}


Game::~Game()
{
}
