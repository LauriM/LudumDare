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

	int points;
	int fuel;

	int isZooming;

	Player()
		:position(Vector(10,10))
		,velocity(Vector(1,1))
		,direction(Vector(-0.5,-0.1))
		,hp(PLAYER_START_HP)
		,isZooming(false)
		,fuel(PLAYER_START_FUEL)
		,points(0)
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