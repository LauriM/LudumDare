#include <stdio.h>

#include <SFML/Graphics.hpp>

int main(){
	printf("Hello world");

	sf::RenderWindow window(sf::VideoMode(800,600), "Ludum");

	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::White);

	while( window.isOpen() )
	{
		sf::Event event;

		while(window.pollEvent(event))
		{
			if(event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(shape);
		window.display();

	}

	return 0;
}