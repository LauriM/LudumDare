#ifndef SCENE_H
#define SCENE_H

#include "Player.h"

class Scene 
{
private:
	Player player;

public:
	Scene() {}

	/* Getters & setters */

	Player* getPlayer()
	{
		return &player;
	}
};

#endif