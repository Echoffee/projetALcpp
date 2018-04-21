#ifndef IVISITOR_HPP
#define IVISITOR_HPP

#include <Shapes/IShape.hpp>

class AbsShape;
class CompositeShape;

class IVisitor {
public:
	virtual void visit(AbsShape* shape) = 0;
	virtual void visit(CompositeShape* shapes) = 0;
};




#endif
