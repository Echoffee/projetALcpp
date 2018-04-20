#include <Maths/Vector2.hpp>

Vector2::Vector2(float x, float y)
{
	this->x = x;
	this->y = y;
}

void Vector2::setX(float x)
{
	this->x = x;
}

void Vector2::setY(float y)
{
	this->y = y;
}

float Vector2::getX()
{
	return x;
}

float Vector2::getY()
{
	return y;
}


