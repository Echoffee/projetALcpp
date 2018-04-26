#ifndef VECTOR2_HPP
#define VECTOR2_HPP

class Vector2 {
public:
	Vector2(float x, float y);
	~Vector2();
	Vector2* copy();
	float x;
	float y;

	static Vector2* Lerp(Vector2* a, Vector2* b, Vector2* f);
};

#endif // !VECTOR2_HPP
