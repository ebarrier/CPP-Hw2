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
	void drawGrid(sf::RenderWindow &window, const std::vector<std::vector<Cell>> &matrix);
	void changeSquareLife(std::vector<std::vector<Cell>> &matrix, const sf::Vector2i &cursorPos, const int &squareSize, const int &offset);
	//void mouseHover(std::vector<std::vector<Cell>> &matrix, const sf::Vector2i &cursorPos, const int &squareSize, const int &offset);

public:
	Game(Grid grid, std::string windowTitle);
	void run();

	Game();
	~Game();
};

#endif