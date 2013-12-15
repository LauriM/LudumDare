#ifndef ENTITY_H
#define ENTITY_H

#include "precompiled.h"

#include "Vec2.h"

enum EntityType
{
	ENTITYTYPE_PICKUP = 0,
	ENTITYTYPE_FUEL,
};

//represents a single object in the space. Pickup, fuel or something
class Entity
{
public:
	Entity()
		:position(Vector(0,0))
		,type(ENTITYTYPE_PICKUP)
	{}

	Entity(Vector position, EntityType type)
		:position(position)
		,type(type)
	{}

	Vector position;
	EntityType type;
};

#endif