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
		Vector2* origin = shapes->getPosition();
		for (int i = 0; i < shapesCount; ++i) {
			Shape* shape = shapes->getShape(i);
			Vector2* goal = Vector2::Lerp(origin, shape->getPosition(), scale);

			Vector2* direction = new Vector2(goal->x - shape->getPosition()->x, goal->y - shape->getPosition()->y);
			Visitor* visitor = new VisitorTranslate(direction);

			shape->accept(visitor);

			delete visitor;
			delete goal;
			delete direction;
		}

		hasVisitedGroup = false;
	}
}
