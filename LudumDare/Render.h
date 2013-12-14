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
	{}

	bool init();

	void update();

private:
	sf::RenderWindow *window;
	Scene *scene;

	// Draw the parlax effect to the background
	void background();

	// Files to be loaded

	sf::Texture texturePlayer;
	sf::Sprite spritePlayer;
};

#endif