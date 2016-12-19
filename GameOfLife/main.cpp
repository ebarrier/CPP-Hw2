#include <SFML/Graphics.hpp>

int main()
{
	unsigned int width = 1600;
	unsigned int height = 1000;
	unsigned int squareSize = 20;
	unsigned int offset = 1;

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
		
		float previousY = 0;
		for (size_t j = 0; j < height; j += squareSize)
		{
			unsigned int offsetv;
			if (j == 0)
			{
				offsetv = 0;
			}
			else
			{
				offsetv = offset;
			}
			float previousX = 0;

			for (size_t i = 0; i < width; i += squareSize)
			{
				unsigned int offseth;
				if (i == 0)
				{
					offseth = 0;
				}
				else
				{
					offseth = offset;
				}

				square[0].position = sf::Vector2f(previousX + offseth, previousY + offsetv);
				square[0].color = sf::Color::White;
				square[1].position = sf::Vector2f(previousX + squareSize + offseth, previousY + offsetv);
				square[1].color = sf::Color::White;
				square[2].position = sf::Vector2f(previousX + squareSize + offseth, previousY + squareSize + offsetv);
				square[2].color = sf::Color::White;
				square[3].position = sf::Vector2f(previousX + offseth, previousY + squareSize + offsetv);
				//square[3].color = sf::Color::Black;
				previousX = previousX + squareSize + offseth;
				window.draw(square);
			}
			previousY = previousY + squareSize + offsetv;
		}
		window.display();
	}

	return 0;
}