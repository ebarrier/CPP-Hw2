#ifndef CELL_H
#define CELL_H
#include <SFML/Graphics.hpp>

class Cell : public sf::RectangleShape
{
private:
	bool isAlive;
	int numAliveNeighbours;

public:
	Cell(int squareSize);

	bool getIsAlive() { return isAlive; }
	void setIsAlive(bool value);
	int getNumAliveNeighbours() { return numAliveNeighbours; }
	void setNumAliveNeighbours(int count);

	Cell();
	~Cell();
};

#endif