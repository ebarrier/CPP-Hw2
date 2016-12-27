#ifndef CELL_H
#define CELL_H
#include <SFML/Graphics.hpp>

class Cell : public sf::RectangleShape
{
private:
	bool isAlive;

public:
	Cell(int squareSize);
	bool getIsAlive() { return isAlive; }
	void setIsAlive(bool value);
	void setSquareColor();

	Cell();
	~Cell();
};

#endif