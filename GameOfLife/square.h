#ifndef SQUARE_H
#define SQUARE_H
#include <SFML/Graphics.hpp>

class Square : public sf::RectangleShape
{
private:
	sf::RectangleShape square;
	bool isAlive;

public:
	Square(int squareSize);
	bool getIsAlive() { return isAlive; }
	void setIsAlive(bool value) { isAlive = value; }
	void setSquareColor();
	void Square::draw(sf::RenderTarget& target, sf::RenderStates states) const;

	~Square();
};

#endif