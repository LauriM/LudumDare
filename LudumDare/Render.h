#ifndef RENDER_H
#define RENDER_H

#include "precompiled.h"

#include <SFML/Graphics.hpp>

#include "Scene.h"
#include "ParticleSystem.h"

class Render 
{
public:
	Render(sf::RenderWindow *window,Scene *scene)
		:window(window)
		,scene(scene)
	{
		view = sf::View(sf::FloatRect(0,0,SCREEN_WIDTH,SCREEN_HEIGHT));
		window->setView(view);
	}

	bool init();

	void update();

private:
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