#include "precompiled.h"

#include <stdio.h>

#include "Render.h"
#include "Scene.h"

#include <SFML/Window/Keyboard.hpp>

#include <SFML/Graphics.hpp>

USE_PARTICLESYSTEM;

int main(){
	printf("Hello world");
	srand(time(NULL));

	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH ,SCREEN_HEIGHT ,32), "Ludum");

	Scene *scene = new Scene();

	Render *render = new Render(&window, scene);

	window.setKeyRepeatEnabled(false);

	if(!render->init())
		return 1;

	//Ugly way to get around the SFML
	bool controlW = false;
	bool controlA = false;
	bool controlD = false;

	window.setFramerateLimit(60);

	bool zoomStatus = false;

	while( window.isOpen() )
	{
		sf::Event event;

		while(window.pollEvent(event))
		{
			if(event.type == sf::Event::Closed)
				window.close();
		}

		if (scene->getPlayer()->hp > 0)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
				scene->getPlayer()->accelerate();

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
				scene->getPlayer()->rotateLeft();

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
				scene->getPlayer()->rotateRight();

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
				scene->getPlayer()->halt();

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
				scene->resetScene();

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			{
				if (zoomStatus == false)
				{
					//zoom
					render->getView()->zoom(2.0);
					zoomStatus = true;
				}
			}
			else
			{
				if (zoomStatus == true)
				{
					//unzoom
					render->getView()->zoom(0.5);
					zoomStatus = false;
				}
			}
		}//is player alive check end

		scene->update();

		window.clear();

		render->update();

		particleSystem.render(&window);

		window.display();

	}

	return 0;
}