#include "cell.h"
#include <SFML/Graphics.hpp>

Cell::Cell(int squareSize) : RectangleShape(sf::Vector2f(squareSize, squareSize)), isAlive(false) {}

Cell::Cell() {}

void Cell::setIsAlive(bool value) 
{ 
	isAlive = value;
	value ? setFillColor(sf::Color::Black) : setFillColor(sf::Color::White);
}

void Cell::setNumAliveNeighbours(int count)
{
	numAliveNeighbours = count;
}

Cell::~Cell() {}
