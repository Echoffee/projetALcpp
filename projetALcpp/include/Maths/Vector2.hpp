#ifndef VECTOR2_HPP
#define VECTOR2_HPP

class Vector2 {
public:
	Vector2(float x, float y);
	~Vector2();
	Vector2* copy();
	float x;
	float y;
};

#endif // !VECTOR2_HPP
