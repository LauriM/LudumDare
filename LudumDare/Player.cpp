#include "precompiled.h"

#include <stdio.h>
#include <math.h>

#include "Player.h"

void Player::update()
{
	position += velocity;
}

void Player::accelerate()
{
	velocity += (direction * PLAYER_ACCEL);
}

void Player::rotateLeft()
{
}

void Player::rotateRight()
{
}