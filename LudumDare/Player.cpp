#include "Player.h"

#include <SFML/System/Vector2.hpp>

#include "vectorHelpers.h"

void Player::update()
{
	position += velocity;
}

void Player::accelerate()
{
	velocity += (direction * 10);
}

void Player::rotateLeft()
{
}

void Player::rotateRight()
{
}