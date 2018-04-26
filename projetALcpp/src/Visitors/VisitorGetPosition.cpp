#include <Visitor\VisitorGetPosition.hpp>

#include <Shapes\AbstractShape.hpp>
#include <Shapes\CompositeShape.hpp>

VisitorGetPosition::VisitorGetPosition() {
	nbShapes = 0;
	center = new Vector2(0, 0);
}

VisitorGetPosition::~VisitorGetPosition() {
	delete center;
}

void VisitorGetPosition::visit(AbstractShape* shape) {
	++nbShapes;
	Vector2* point = shape->getPosition();
	center->x += point->x;
	center->y += point->y;
	delete point;
}

void VisitorGetPosition::visit(CompositeShape* shapes) {

}

Vector2* VisitorGetPosition::getPosition() {
	center->x = center->x / nbShapes;
	center->y = center->y / nbShapes;
	return center;
}
