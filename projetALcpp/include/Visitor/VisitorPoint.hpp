#ifndef VISITORPOINT_HPP
#define VISITORPOINT_HPP

#include <Visitor/Visitor.hpp>
#include <Maths/Vector2.hpp>

class VisitorPoint : public Visitor {
private :
	Vector2* point;
	bool result = false;

public:
	VisitorPoint(Vector2* point);
	~VisitorPoint();
	virtual void visit(AbstractShape* shape) override;
	virtual void visit(CompositeShape* shapes) override;

	bool isContained();
};

#endif // !VISITORPOINT_HPP
