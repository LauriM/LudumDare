#include "Render.h"

#include <SFML/Graphics.hpp>

#define LOADTEXTURE(p_var, p_sprite, p_file) if(! p_var.loadFromFile( p_file ) ){ printf("Failed to load texture %s",p_file); return false; } p_sprite.setTexture(p_var);

bool Render::init()
{
	printf("loading resources...");

	LOADTEXTURE(texturePlayer, spritePlayer, "../gfx/player.png");
}

void Render::update()
{
	background();

	//Draw the player
}

void Render::background()
{
	sf::CircleShape shape(1.f);
	shape.setFillColor(sf::Color::White);

	//get reference coordinate
	sf::Vector2f pos(scene->getPlayer()->position.x,scene->getPlayer()->position.y);

	for(int x = 0; x < 100; ++x)
	{
		for(int y = 0; y < 100; ++y)
		{
			shape.setPosition(100*x + pos.x ,100*y + pos.y);
			window->draw(shape);
		}
	}
}