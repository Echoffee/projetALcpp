#include <Shapes/AbsShape.hpp>

void AbsShape::addShape(IShape * shape) {
	//Throw exception if we can ?
	return;
}


Vector2* AbsShape::getOrigin() {
	return rotationCenter;
}

std::vector<Vector2*> AbsShape::getPoints() {
	return points;
}

void AbsShape::accept(IVisitor* visitor) {
	visitor->visit(this);
}