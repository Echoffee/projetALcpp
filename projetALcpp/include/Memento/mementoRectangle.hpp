#ifndef MEMENTO_RECTANGLE_HPP
#define MEMENTO_RECTANGLE_HPP

#include <Memento/Memento.hpp>
#include <Maths/Vector2.hpp>
#include <vector>

class MementoRectangle : public Memento {
	//friend <classe qui a acces aux privates>
	friend class Rectangle;

private:
	MementoRectangle(std::vector<Vector2*> points, int color);
	~MementoRectangle();
	std::vector<Vector2*> points;
	int color;

};

#endif
