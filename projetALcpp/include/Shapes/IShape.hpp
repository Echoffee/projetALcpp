#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <Memento/IMemento.hpp>
#include <Maths/Vector2.hpp>
#include <vector>

class IVisitor;

class IShape {
protected:
	Vector2* rotationCenter;

public:
	//Generic draw method (as an entity)
	virtual Vector2* getPosition() = 0;
	virtual Vector2* getOrigin() = 0;

	//Methods for memento pattern 
	virtual void setMemento(IMemento* m) = 0;
	virtual IMemento* createMemento() = 0;

	//Specific method for group of Shape for Composite pattern
	virtual void addShape(IShape* shape) = 0;

	//Common methods between groups and shapes
	virtual void draw() = 0;
	virtual IShape* clone() = 0;

	//method for visitors
	virtual void accept(IVisitor* visitor) = 0;
};

#endif //SHAPE