#ifndef RENDER_H
#define RENDER_H

#include <SFML/Graphics.hpp>

#include "Scene.h"

class Render 
{
public:
	Render(sf::RenderWindow *window,Scene *scene)
		:window(window)
		,scene(scene)
	{
		view = sf::View(sf::FloatRect(0,0,800,600));
		window->setView(view);
	}

	bool init();

	void update();

private:
	sf::View view;
	sf::RenderWindow *window;
	Scene *scene;

	// Draw the parlax effect to the background
	void background();

	// Files to be loaded

	sf::Texture texturePlayer;
	sf::Sprite spritePlayer;
};

#endif