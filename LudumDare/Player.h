#ifndef PLAYER_H
#define PLAYER_H

#include "precompiled.h"

#define PLAYER_ROTATION_SPEED 3.f
#define PLAYER_ACCEL 0.15

class Player
{
public:
	Vector position;
	Vector velocity;
	Vector direction;
	int hp;

	Player()
		:position(Vector(10,10))
		,velocity(Vector(1,1))
		,direction(Vector(-0.5,-0.1))
		,hp(100)
	{}

	void update();

	// controls
	void rotateLeft();
	void rotateRight();
	void accelerate();
	void halt();
	// controls

	void impulse(Vector direction, float force);

private:
};

#endif