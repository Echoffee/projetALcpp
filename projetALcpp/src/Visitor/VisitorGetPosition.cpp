#include <Visitor\VisitorGetPosition.hpp>

#include <Shapes\AbsShape.hpp>
#include <Shapes\CompositeShape.hpp>

VisitorGetPosition::VisitorGetPosition() {
	nbShapes = 0;
	center = new Vector2(0, 0);
}

VisitorGetPosition::~VisitorGetPosition() {
	delete center;
}

void VisitorGetPosition::visit(AbsShape* shape) {
	++nbShapes;
	Vector2* point = shape->getPosition();
	center->x += point->x;
	center->y += point->y;
}

void VisitorGetPosition::visit(CompositeShape* shapes) {
	for (auto shape : shapes->getShapes())
		shape->accept(this);
}

Vector2* VisitorGetPosition::getPosition() {
	center->x = center->x / nbShapes;
	center->y = center->y / nbShapes;
	return center;
}
