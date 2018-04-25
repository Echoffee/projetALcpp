#ifndef VISITOR_ROTATE_HPP
#define VISITOR_ROTATE_HPP

#include <Visitor/Visitor.hpp>

class VisitorRotate : public Visitor {
private:
	double angle;
	Vector2* rotationPoint;

public:
	VisitorRotate(Vector2* point, double angle);
	~VisitorRotate();

	void visit(AbstractShape* shape) override;
	void visit(CompositeShape* shapes) override;
};

#endif // !VISITOR_ROTATE_HPP
