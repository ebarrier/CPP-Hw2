#include "square.h"
#include <SFML/Graphics.hpp>

Square::Square(int squareSize) : RectangleShape(sf::Vector2f(squareSize, squareSize)), isAlive(false)
	{
	}

Square::Square()
{
}

void Square::setSquareColor()
{
	if (!this->getIsAlive())
	{
		this->setFillColor(sf::Color::Blue);
	}
}

void Square::setIsAlive(bool value) 
{ 
	isAlive = value;
	value ? this->setFillColor(sf::Color::Black) : this->setFillColor(sf::Color::White);
}

//void Square::draw(sf::RenderTarget& target, sf::RenderStates states) const
//{
//	states.transform *= getTransform();
//	target.draw(states);
//}

Square::~Square()
{
}
