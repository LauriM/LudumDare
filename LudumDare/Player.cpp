#include "precompiled.h"

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
	angle -= PLAYER_ROTATION_SPEED;
	updateDirection();
}

void Player::rotateRight()
{
	angle += PLAYER_ROTATION_SPEED;
	updateDirection();
}

void Player::updateDirection()
{
}