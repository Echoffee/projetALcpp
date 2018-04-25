#include <Visitor/VisitorTranslate.hpp>
#include <Shapes/AbstractShape.hpp>
#include <Shapes/CompositeShape.hpp>

VisitorTranslate::VisitorTranslate(Vector2* direction) {
	this->direction = direction;
}

VisitorTranslate::~VisitorTranslate() {
	delete direction;
}

void VisitorTranslate::visit(AbstractShape* shape) {
	std::vector<Vector2*> points(shape->getPoints());
	for (auto point : points) {
		point->x += direction->x;
		point->y += direction->y;
	}
}

void VisitorTranslate::visit(CompositeShape* shapes) {

}
