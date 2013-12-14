#ifndef PLANET_H
#define PLANET_H

#include "precompiled.h"

struct Planet
{
	Planet(Vector position, int size)
		:position(position)
		,size(size)
	{ } 

	int size;
	Vector position;
};

#endif