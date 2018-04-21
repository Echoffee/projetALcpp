#ifndef Visitor_HPP
#define Visitor_HPP

#include <Shapes/Shape.hpp>

class AbstractShape;
class CompositeShape;

class Visitor {
public:
	virtual void visit(AbstractShape* shape) = 0;
	virtual void visit(CompositeShape* shapes) = 0;
};




#endif
