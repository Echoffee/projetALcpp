#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <Memento/Memento.hpp>
#include <Maths/Vector2.hpp>
#include <Maths/Color.hpp>
#include <vector>

class Visitor;

class Shape {
protected:
	Vector2* rotationCenter;

public:
	//Generic draw method (as an entity)
	virtual Vector2* getPosition() = 0;
	virtual Vector2* getOrigin() = 0;
	virtual Color* getColorFill() = 0;
	virtual void setColorFill(Color* c) = 0;
	virtual Color* getColorLine() = 0;
	virtual void setColorLine(Color* c) = 0;
	//Methods for memento pattern 
	virtual void setMemento(Memento* m) = 0;
	virtual Memento* createMemento() = 0;

	//Specific method for group of Shape for Composite pattern
	virtual void addShape(Shape* shape) = 0;

	//Common methods between groups and shapes
	virtual void draw() = 0;
	virtual Shape* clone() = 0;

	//method for visitors
	virtual void accept(Visitor* visitor) = 0;
};

#endif //SHAPE