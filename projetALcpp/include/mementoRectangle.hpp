#ifndef MEMENTO_RECTANGLE_HPP
#define MEMENTO_RECTANGLE_HPP

#include <IMemento.hpp>
#include <vector>

class MementoRectangle : public IMemento {
	//friend <classe qui a acces aux privates>
	friend class Rectangle;


private:
	MementoRectangle(std::vector<int> points, int color);
	std::vector<int> points;
	int color;

};

#endif
