#include <mementoRectangle.hpp>

MementoRectangle::MementoRectangle(std::vector<int> points, int color) {
	std::vector<int> savedPoints(points);
	this->points = savedPoints;
	this->color = color;
}