#include <Visitor/VisitorTranslate.hpp>
#include <Shapes/AbsShape.hpp>
#include <Shapes/CompositeShape.hpp>

VisitorTranslate::VisitorTranslate(Vector2* direction) {
	this->direction = direction;
}

void VisitorTranslate::visit(AbsShape* shape) {
	std::vector<Vector2*> points(shape->getPoints());
	for (auto point : points) {
		point->x += direction->x;
		point->y += direction->y;
	}
}

void VisitorTranslate::visit(CompositeShape* shapes) {
	std::vector<IShape*> group(shapes->getShapes);
	for (auto shape : group) {
		shape->accept(this);
	}
}
