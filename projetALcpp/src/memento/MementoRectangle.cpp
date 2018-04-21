#include <Memento/mementoRectangle.hpp>

MementoRectangle::MementoRectangle(std::vector<Vector2*> points, int color) {
	this->points = points;
	this->color = color;
}

MementoRectangle::~MementoRectangle() {
	for (auto point : points)
		delete point;
}