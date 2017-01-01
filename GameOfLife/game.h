#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include <string>
#include "grid.h"

class Game
{
private:
	Grid grid;
	sf::RenderWindow window;
	sf::Vector2i cursorPos;

public:
	Game(Grid &grid, std::string windowTitle);
	void init();
	void startAnimation(sf::RenderWindow &window, Grid &grid);

	Game();
	~Game();
};

#endif