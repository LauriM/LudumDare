#ifndef RENDER_H
#define RENDER_H

#include "precompiled.h"

#include <SFML/Graphics.hpp>

#include "Scene.h"
#include "ParticleSystem.h"

#define STARSTATUS_PRECACHE_SIZE 1000

class Render 
{
public:
	Render(sf::RenderWindow *window,Scene *scene)
		:window(window)
		,scene(scene)
	{
		view = sf::View(sf::FloatRect(0,0,SCREEN_WIDTH,SCREEN_HEIGHT));
		window->setView(view);

		for(int i = 0; i < STARSTATUS_PRECACHE_SIZE; ++i)
		{
			if(randomRange(0,1)){
				starStatus[i] = true;
			}
			else
			{
				starStatus[i] = false;
			}
		}

		starStatusTick = 0;
	}

	bool init();

	void update();

private:
	bool starStatus[STARSTATUS_PRECACHE_SIZE];
	int starStatusTick;

	bool getNextStarStatus();

	sf::View view;
	sf::RenderWindow *window;

	Scene *scene;

	// Draw the parlax effect to the background
	void bounds();
	void background();

	// Files to be loaded

	sf::Texture texturePlayer;
	sf::Sprite spritePlayer;
};

#endif