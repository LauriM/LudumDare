#include "precompiled.h"

#include <stdio.h>

#include "Render.h"
#include "Scene.h"

#include <SFML/Graphics.hpp>

#include <SFML/Window/Keyboard.hpp>

USE_PARTICLESYSTEM;

int main(){
	printf("Hello world");
	srand(time(NULL));

	sf::RenderWindow window(sf::VideoMode(800,600,32), "Ludum");

	Scene *scene = new Scene();

	Render *render = new Render(&window, scene);

	window.setKeyRepeatEnabled(false);

	if(!render->init())
		return 1;

	//Ugly way to get around the SFML
	bool controlW = false;
	bool controlA = false;
	bool controlD = false;

	while( window.isOpen() )
	{
		sf::Event event;

		while(window.pollEvent(event))
		{
			if(event.type == sf::Event::Closed)
				window.close();
		}

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			scene->getPlayer()->accelerate();

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			scene->getPlayer()->rotateLeft();

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			scene->getPlayer()->rotateRight();

		scene->update();

		window.clear();

		render->update();

		particleSystem.render(&window);

		window.display();

	}

	return 0;
}