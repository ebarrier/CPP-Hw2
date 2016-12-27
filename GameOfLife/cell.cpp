#include "cell.h"
#include <SFML/Graphics.hpp>

Cell::Cell(int squareSize) : RectangleShape(sf::Vector2f(squareSize, squareSize)), isAlive(false)
	{
	}

Cell::Cell()
{
}

void Cell::setSquareColor()
{
	if (!this->getIsAlive())
	{
		this->setFillColor(sf::Color::Blue);
	}
}

void Cell::setIsAlive(bool value) 
{ 
	isAlive = value;
	value ? this->setFillColor(sf::Color::Black) : this->setFillColor(sf::Color::White);
}

Cell::~Cell()
{
}
