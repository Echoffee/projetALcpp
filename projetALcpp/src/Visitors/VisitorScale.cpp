#include <Visitor/VisitorScale.hpp>
#include <Visitor/VisitorTranslate.hpp>
#include <Shapes/AbstractShape.hpp>
#include <Shapes/CompositeShape.hpp>


VisitorScale::VisitorScale(Vector2* scale) {
	this->scale = scale;
	this->hasVisitedGroup = false;
}

VisitorScale::~VisitorScale() {
	delete scale;
}

void VisitorScale::visit(AbstractShape* shape) {
	std::vector<Vector2*> points(shape->getPoints());
	Vector2* pos = shape->getPosition();
	for (auto point : points) {
		Vector2* n = Vector2::Lerp(pos, point, scale);
		point->x = n->x;
		point->y = n->y;
	}
}

void VisitorScale::visit(CompositeShape* shapes) {
	if (!hasVisitedGroup) {
		hasVisitedGroup = true;
		float shapesCount = shapes->getShapes().size();
		Vector2* pos_o = shapes->getPosition();
		for (int i = 0; i < shapesCount; ++i) {
			Shape* s = shapes->getShape(i);
			Vector2* goal = Vector2::Lerp(pos_o, s->getPosition(), scale);
			Vector2* t = new Vector2(goal->x - s->getPosition()->x, goal->y - s->getPosition()->y);
			Visitor* v = new VisitorTranslate(t);
			s->accept(v);
			delete v;
			delete goal;
			delete t;
		}

		hasVisitedGroup = false;
	}
}
