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

Color * AbstractShape::getColorFill()
{
	return colorFill;
}

Color * AbstractShape::getColorLine()
{
	return colorLine;
}

std::vector<Vector2*> AbstractShape::getBounds()
{
	std::vector<Vector2*> result = std::vector<Vector2*>();
	Vector2* tl = new Vector2(points.at(0)->x, points.at(0)->y);
	Vector2* br = new Vector2(points.at(0)->x, points.at(0)->y);
	for (auto p : points) {
		tl->x = (p->x < tl->x ? p->x : tl->x);
		tl->y = (p->y < tl->y ? p->y : tl->y);
		br->x = (p->x > br->x ? p->x : br->x);
		br->y = (p->y > br->y ? p->y : br->y);
	}
	
	result.push_back(tl);
	result.push_back(br);
	return result;
}

void AbstractShape::accept(Visitor* visitor) {
	visitor->visit(this);
}