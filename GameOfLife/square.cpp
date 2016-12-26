#include "square.h"
#include <SFML/Graphics.hpp>

Square::Square(int squareSize) : square(sf::Vector2f(squareSize, squareSize)), isAlive(false)
	{
	this->setSquareColor();
	}

void Square::setSquareColor()
{
	if (!this->getIsAlive())
	{
		this->setFillColor(sf::Color::Blue);
	}
}

void Square::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	target.draw(square, states);
}

Square::~Square()
{
}
