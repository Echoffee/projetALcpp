#include <Memento/mementoRectangle.hpp>

MementoRectangle::MementoRectangle(std::vector<Vector2*> points, Color* colorFill, Color* colorLine) {
	this->points = points;
	this->colorFill = colorFill;
	this->colorLine = colorLine;
}

MementoRectangle::~MementoRectangle() {
	for (auto point : points)
		delete point;
}