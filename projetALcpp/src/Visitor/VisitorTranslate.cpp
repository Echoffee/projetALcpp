#include <Visitor/VisitorTranslate.hpp>

VisitorTranslate::VisitorTranslate(Vector2* direction) {
	this->direction = direction;
}

void VisitorTranslate::visit(AbsShape* shape) {
	//std::vector<Vector2*> points(shape->getPoints());
}

void VisitorTranslate::visit(CompositeShape* shapes) {
	//shapes.

}
