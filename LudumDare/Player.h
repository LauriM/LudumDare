#ifndef PLAYER_H
#define PLAYER_H

#include "precompiled.h"

class Player
{
public:
	Vector position;
	Vector velocity;
	Vector direction;

	Player()
		:position(Vector(10,10))
		,velocity(Vector(1,1))
		,direction(Vector(0.5,0.1))
	{}

	void update();

	// controls
	void rotateLeft();
	void rotateRight();
	void accelerate();
};

#endif