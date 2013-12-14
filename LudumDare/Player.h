#ifndef PLAYER_H
#define PLAYER_H

#include "precompiled.h"

#define PLAYER_ROTATION_SPEED 2
#define PLAYER_ACCEL 2

class Player
{
public:
	Vector position;
	Vector velocity;
	Vector direction;

	float angle; //stores the angle, is converted to direction

	Player()
		:position(Vector(10,10))
		,velocity(Vector(1,1))
		,direction(Vector(-0.5,-0.1))
	{}

	void update();

	// controls
	void rotateLeft();
	void rotateRight();
	void accelerate();

private:
	void updateDirection();
};

#endif