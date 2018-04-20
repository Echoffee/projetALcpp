#pragma once
#ifndef COMPOSITE_SHAPE_HPP
#define COMPOSITE_SHAPE_HPP

#include "IShape.hpp"

class compositeShape : public IShape {
private:
	std::vector<IShape>* shapes;

public:
	// H�rit� via Shape
	virtual void setMemento(IMemento * m) override;

	virtual IMemento * createMemento() override;

	virtual void addShape(IShape * shape) override;

	virtual void draw() override;

	virtual IShape * clone() override;
};


#endif