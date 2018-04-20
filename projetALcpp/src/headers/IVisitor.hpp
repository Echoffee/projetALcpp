#pragma once
#ifndef IVISITOR_HPP
#define IVISITOR_HPP

#include "IShape.hpp"
#include "absShape.hpp"
//#include "compositeShape.hpp"

class IVisitor {
public:
	virtual void visit(AbsShape* shape) = 0;
	//virtual void visit(CompositeShape* shapes) = 0;
};




#endif
