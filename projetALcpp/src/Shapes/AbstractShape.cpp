#include <Shapes/AbstractShape.hpp>

void AbstractShape::addShape(Shape * shape) {
	//Throw exception if we can ?
	return;
}


Vector2* AbstractShape::getOrigin() {
	return rotationCenter;
}

std::vector<Vector2*> AbstractShape::getPoints() {
	return points;
}

void AbstractShape::setColorFill(Color * color)
{
	this->colorFill = color;
}

void AbstractShape::setColorLine(Color * color)
{
	this->colorLine = color;
}

void AbstractShape::accept(Visitor* visitor) {
	visitor->visit(this);
}