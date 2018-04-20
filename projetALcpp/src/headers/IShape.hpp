#pragma once
#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "IMemento.hpp"
#include <vector>


class IShape {
protected:
	std::vector<int>* rotationCenter;

public:
	//Methods for memento pattern 
	virtual void setMemento(IMemento* m) = 0;
	virtual IMemento* createMemento() = 0;

	//Specific method for group of Shape for Composite pattern
	virtual void addShape(IShape* shape) = 0;

	//Common methods between groups and shapes
	virtual void draw() = 0;
	virtual IShape* clone() = 0;
};

#endif //SHAPE