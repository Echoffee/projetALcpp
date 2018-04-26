#ifndef VISITOR_COUNT_SHAPE_HPP
#define VISITOR_COUNT_SHAPE_HPP

#include <Visitor\Visitor.hpp>

class VisitorGetPosition : public Visitor {
private :
	Vector2* center;
	int nbShapes;
	bool computed = false;

public :
	VisitorGetPosition();
	~VisitorGetPosition();
	virtual void visit(AbstractShape* shape) override;
	virtual void visit(CompositeShape* shapes) override;

	Vector2* getPosition();

};

#endif // !VISITOR_COUNT_SHAPE_HPP
