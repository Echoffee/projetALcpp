#include <mementoRectangle.hpp>

MementoRectangle::MementoRectangle(std::vector<Vector2*> points, int color) {
	std::vector<Vector2*> savedPoints(points);
	this->points = savedPoints;
	this->color = color;
}