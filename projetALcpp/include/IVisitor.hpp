#ifndef IVISITOR_HPP
#define IVISITOR_HPP

#include <absShape.hpp>

class IVisitor {
public:
	virtual void visit(AbsShape* shape) = 0;
	//virtual void visit(CompositeShape* shapes) = 0;
};




#endif
