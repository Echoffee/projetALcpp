#include <Maths/Vector2.hpp>

Vector2::Vector2(float x, float y)
{
	this->x = x;
	this->y = y;
}

Vector2::~Vector2() {

}

float lerp(float a, float b, float f)
{
	return (a * (1.0 - f)) + (b * f);
}

Vector2 * Vector2::Lerp(Vector2 * a, Vector2 * b, Vector2* f)
{
	Vector2* result = new Vector2(a->x, a->y);
	result->x = lerp(a->x, b->x, f->x);
	result->y = lerp(a->y, b->y, f->y);
	
	return result;
}

Vector2* Vector2::copy() {
	return new Vector2(this->x, this->y);
}

