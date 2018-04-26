#include <Visitor/VisitorPoint.hpp>
#include <Shapes/AbstractShape.hpp>
VisitorPoint::VisitorPoint(Vector2* point) {
	this->point = point;
	result = false;
}

VisitorPoint::~VisitorPoint() {

}

void VisitorPoint::visit(AbstractShape* shape) {
	Vector2* c = shape->getPosition();
	std::vector<Vector2*> points = shape->getPoints();
	for (int i = 0; i < points.size() && !result; ++i) {
		Vector2* p = points.at(i);
		float minx = (c->x < p->x ? c->x : p->x);
		float maxx = (c->x > p->x ? c->x : p->x);
		float miny = (c->y < p->y ? c->y : p->y);
		float maxy = (c->y > p->y ? c->y : p->y);
		if (minx < point->x && point->x < maxx && miny < point->y && point->y < maxy)
			result = shape->isPointable();

	}
	delete c;
}

bool VisitorPoint::isContained() {
	return result;
}

void VisitorPoint::visit(CompositeShape* shapes) {
	//TODO
}

