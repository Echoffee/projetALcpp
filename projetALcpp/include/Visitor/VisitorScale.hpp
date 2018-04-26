#ifndef VISITORSCALE_HPP
#define VISITORSCALE_HPP

#include <Visitor/Visitor.hpp>

class VisitorScale : public Visitor {
private:
	Vector2 * scale;
	bool hasVisitedGroup;
public:
	// Visitor
	VisitorScale(Vector2* scale);
	~VisitorScale();

	void visit(AbstractShape* shape) override;

	void visit(CompositeShape* shapes) override;

};

#endif // !VISITORSCALE_HPP
