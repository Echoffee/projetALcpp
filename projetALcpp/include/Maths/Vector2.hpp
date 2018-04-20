#ifndef VECTOR2_HPP
#define VECTOR2_HPP

class Vector2 {
public:
	Vector2(float x, float y);
	void setX(float x);
	void setY(float y);
	float getX();
	float getY();

private:
	float x;
	float y;
};

#endif // !VECTOR2_HPP
