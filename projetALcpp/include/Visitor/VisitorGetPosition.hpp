#ifndef VISITOR_COUNT_SHAPE_HPP
#define VISITOR_COUNT_SHAPE_HPP

#include <Visitor\IVisitor.hpp>

class VisitorGetPosition : public IVisitor {
private :
	Vector2* center;
	int nbShapes;

public :
	VisitorGetPosition();
	~VisitorGetPosition();
	virtual void visit(AbsShape* shape) override;
	virtual void visit(CompositeShape* shapes) override;

	Vector2* getPosition();

};

#endif // !VISITOR_COUNT_SHAPE_HPP
