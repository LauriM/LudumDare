#ifndef PLAYER_H
#define PLAYER_H

#include "precompiled.h"

class Player
{
public:
	Vector position;
	Vector velocity;
	Vector direction;
	int hp;

	int isZooming;

	Player()
		:position(Vector(10,10))
		,velocity(Vector(1,1))
		,direction(Vector(-0.5,-0.1))
		,hp(100)
		,isZooming(false)
	{}

	void update();

	// controls
	void rotateLeft();
	void rotateRight();
	void accelerate();
	void halt();
	void zoom();
	// controls

	void impulse(Vector direction, float force);

private:
};

#endif