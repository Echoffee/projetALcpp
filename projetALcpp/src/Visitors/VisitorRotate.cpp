#include <Visitor/VisitorRotate.hpp>
#include <Shapes/AbstractShape.hpp>
#include <Shapes/CompositeShape.hpp>
#include <math.h>

VisitorRotate::VisitorRotate(Vector2* point, double angle) {
	this->angle = angle;
	rotationPoint = point;
}

VisitorRotate::~VisitorRotate() {

}

/*
function rotate(M, O, angle) {
	var xM, yM, x, y;
	angle *= Math.PI / 180;
	xM = M.x - O.x;
	yM = M.y - O.y;
	x = xM * Math.cos(angle) + yM * Math.sin(angle) + O.x;
	y = -xM * Math.sin(angle) + yM * Math.cos(angle) + O.y;
	return ({ x:Math.round(x), y : Math.round(y) });
*/

void VisitorRotate::visit(AbstractShape* shape) {
	std::vector<Vector2*> points(shape->getPoints());
	for (auto point : points) {
		float dX = point->x - rotationPoint->x;
		float dY = point->y - rotationPoint->y;

		float x = dX * cos(angle) + dY * sin(angle) + rotationPoint->x;
		float y = -dX * sin(angle) + dY * cos(angle) + rotationPoint->y;
		point->x = x;
		point->y = y;
	}
}

void VisitorRotate::visit(CompositeShape* shapes) {

}