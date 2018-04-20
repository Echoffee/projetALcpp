#pragma once
#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "absShape.hpp"

class Rectangle : public AbsShape {

	Rectangle(int x, int y, int width, int height);

	// Hérité via AbsShape
	virtual void setMemento(IMemento * m) override;
	virtual IMemento * createMemento() override;
	virtual void draw() override;
	virtual IShape * clone() override;
};

#endif