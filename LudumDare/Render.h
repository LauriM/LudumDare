#ifndef RENDER_H
#define RENDER_H

#include "precompiled.h"

#include <SFML/Graphics.hpp>

#include "Scene.h"
#include "ParticleSystem.h"

#define STARSTATUS_PRECACHE_SIZE 1024

class Render 
{
public:
	Render(sf::RenderWindow *window,Scene *scene)
		:window(window)
		,scene(scene)
		,zoomStatus(false)
	{
		view = sf::View(sf::FloatRect(0,0,SCREEN_WIDTH,SCREEN_HEIGHT));
		window->setView(view);

		for(int i = 0; i < STARSTATUS_PRECACHE_SIZE; ++i)
		{
			if(randomRange(0,1)) {
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

	sf::View *getView()
	{
		return &view;
	}

	void toggleZoom()
	{
		if(zoomStatus == false)
		{
			getView()->zoom(2.0);
			zoomStatus = true;
		}
		if(zoomStatus == false)
		{
			getView()->zoom(0.5);
			zoomStatus = true;
		}
	}

private:
	bool zoomStatus;
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