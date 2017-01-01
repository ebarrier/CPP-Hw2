#include "game.h"
#include "grid.h"
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

Game::Game(Grid &grid, std::string windowTitle)
	: grid(grid), window(sf::VideoMode(grid.getWidthHeight().at(0), grid.getWidthHeight().at(1)), windowTitle) {}

/*
Init mode displays the grid and user can change the life status of cells by clicking on them
*/
void Game::init()
{
	std::cout << "Init mode" << std::endl; //we know from the console that we are in init mode
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (window.hasFocus()) //when the window is on focus
			{
				if (event.type == sf::Event::MouseMoved)
				{
					cursorPos = sf::Mouse::getPosition(window); //when mouse mouves, we record its position
				}
				if (event.type == sf::Event::MouseButtonReleased)
				{
					if (event.mouseButton.button == sf::Mouse::Left)
					{
						//when left-click, change lifesatus of the cell under the cursor
						grid.changeSquareLife(cursorPos, grid.getSquareSize(), grid.getOffset());
					}
				}
				
				if (event.type == sf::Event::KeyReleased)
				{
					if (event.key.code == sf::Keyboard::Space)
					{
						//when space bar is pressed, start animation mode of the GOL
						startAnimation(window, grid);
					}
				}
			}
		}
		window.clear(sf::Color(220,220,220,255)); //window has grey background
		window.draw(grid);
		window.display();
	}
}

void Game::startAnimation(sf::RenderWindow &window, Grid &grid)
{
	std::cout << "Animation mode" << std::endl; //we know from the console that we are in animation mode
	static sf::Clock s_clock; //Start clock
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
					init(); //when space bar is pressed, return to init mode
				}
			}
		}

		sf::Time elapsed = s_clock.getElapsedTime();
		if (elapsed.asSeconds() > 0.50f) 
		{
			//if more than half-second has passed since clock started..
			grid.checkLiveNeighbours(); //..check all the live neighbours of each cell..
			grid.nextGeneration(); //..chand life status of each cell according to the live neighbours count
			s_clock.restart();
		}
		
		window.clear(sf::Color(220, 220, 220, 255));
		window.draw(grid);
		window.display();
	}
}

Game::Game()
{
}

Game::~Game()
{
}
