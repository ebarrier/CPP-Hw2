#include "game.h"
#include "grid.h"
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

Game::Game(Grid &grid, std::string windowTitle)
	: grid(grid), window(sf::VideoMode(grid.getWidthHeight().at(0), grid.getWidthHeight().at(1)), windowTitle) {}

void Game::init()
{
	std::cout << "Init mode" << std::endl;
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (window.hasFocus())
			{
				if (event.type == sf::Event::MouseMoved)
				{
					cursorPos = sf::Mouse::getPosition(window);
				}
				if (event.type == sf::Event::MouseButtonReleased)
				{
					if (event.mouseButton.button == sf::Mouse::Left)
					{
						grid.changeSquareLife(cursorPos, grid.getSquareSize(), grid.getOffset());
					}
				}
				
				if (event.type == sf::Event::KeyReleased)
				{
					if (event.key.code == sf::Keyboard::Space)
					{
						startAnimation(window, grid);
					}
				}
			}
		}
		window.clear(sf::Color(220,220,220,255));
		drawGrid(window, grid.getMatrix());
		window.display();
	}
}

void Game::startAnimation(sf::RenderWindow &window, Grid &grid)
{
	std::cout << "Animation mode" << std::endl;
	static sf::Clock s_clock;
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::KeyReleased)
			{
				if (event.key.code == sf::Keyboard::Space)
				{
					init();
				}
			}
		}

		sf::Time elapsed = s_clock.getElapsedTime();
		if (elapsed.asSeconds() > 0.50f)
		{
			grid.checkLiveNeighbours();
			grid.nextGeneration();
			s_clock.restart();
		}
		
		window.clear(sf::Color(220, 220, 220, 255));
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
