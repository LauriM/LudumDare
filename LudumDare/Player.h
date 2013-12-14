#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/System/Vector2.hpp>

class Player
{
public:
	sf::Vector2f position;
	sf::Vector2f velocity;
	sf::Vector2f orient;

	Player()
		:position(sf::Vector2f(0,0))
		,velocity(sf::Vector2f(0,0))
		,orient(sf::Vector2f(0,0))
	{}

	Player(sf::Vector2f position)
		:position(position)
		,velocity(sf::Vector2f(0,0))
		,orient(sf::Vector2f(0,0))
	{}


	void rotateLeft();
	void rotateRight();
	void accelerate();
};

#endif