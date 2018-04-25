#ifndef MEMENTO_RECTANGLE_HPP
#define MEMENTO_RECTANGLE_HPP

#include <Memento/Memento.hpp>
#include <Maths/Vector2.hpp>
#include <Maths/Color.hpp>
#include <vector>

class MementoRectangle : public Memento {
	//friend <classe qui a acces aux privates>
	friend class Rectangle;

private:
	MementoRectangle(std::vector<Vector2*> points, Color* colorFill, Color* colorLine);
	~MementoRectangle();
	std::vector<Vector2*> points;
	Color* colorFill;
	Color* colorLine;

};

#endif
