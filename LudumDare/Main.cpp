#include <stdio.h>

#include "Render.h"
#include "Scene.h"

#include <SFML/Graphics.hpp>

int main(){
	printf("Hello world");

	sf::RenderWindow window(sf::VideoMode(800,600), "Ludum");

	Scene *scene = new Scene();
	Render *render = new Render(&window,scene);

	while( window.isOpen() )
	{
		sf::Event event;

		while(window.pollEvent(event))
		{
			if(event.type == sf::Event::Closed)
				window.close();

			//Keys that are input
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
				scene->getPlayer()->rotateRight();

			if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
				scene->getPlayer()->rotateRight();

			if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
				scene->getPlayer()->accelerate();
		}

		scene->update();

		window.clear();

		render->update();

		window.display();

	}

	return 0;
}