#include <SFML/Graphics.hpp>

int main()
{
	unsigned int width = 1000;
	unsigned int height = 1000;
	unsigned int squareSize = 10;
	sf::RenderWindow window(sf::VideoMode(width, height), "Etienne's Game Of Life!");
	sf::VertexArray square(sf::Quads, 4);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		for (size_t j = 0; j < height; j += squareSize)
		{
			for (size_t i = 0; i < width; i += squareSize)
			{
				square[0].position = sf::Vector2f(i, j);
				square[0].color = sf::Color::Cyan;
				square[1].position = sf::Vector2f(i+ squareSize, j);
				square[2].position = sf::Vector2f(i+ squareSize, j+ squareSize);
				square[3].position = sf::Vector2f(i, j+ squareSize);
				window.draw(square);
			}
		}
		window.display();
	}

	return 0;
}