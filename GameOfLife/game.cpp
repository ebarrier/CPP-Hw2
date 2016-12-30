#include "game.h"
#include "grid.h"
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

Game::Game(Grid &grid, std::string windowTitle)
	: grid(grid), window(sf::VideoMode(grid.getWidthHeight().at(0), grid.getWidthHeight().at(1)), windowTitle) {}

void Game::run()
{
	//bool animationLaunched = false;
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
				grid.changeSquareLife(cursorPos, grid.getSquareSize(), grid.getOffset());
			}

			if (window.hasFocus())
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
				{
					startAnimation(window, grid);
					break;
				}
			}
		}
		window.clear(sf::Color::Black);
		drawGrid(window, grid.getMatrix());
		window.display();
	}
}

void Game::startAnimation(sf::RenderWindow &window, Grid &grid)
{
	std::cout << "Start animation" << std::endl;
	static sf::Clock s_clock;
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		sf::Time elapsed = s_clock.getElapsedTime();
		if (elapsed.asSeconds() > 0.50f)
		{
			static bool count = false;
			for (auto &vector : grid.getMatrix())
			{
				for (auto &square : vector)
				{
					if (square.getIsAlive() && count)
					{
						square.setFillColor(sf::Color::Blue);
					}
					if (square.getIsAlive() && !count)
					{
						square.setFillColor(sf::Color::Yellow);
					}
				}
			}
			count = !count;
			s_clock.restart();
		}
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
		}
	}
}

Game::Game()
{
}

Game::~Game()
{
}
