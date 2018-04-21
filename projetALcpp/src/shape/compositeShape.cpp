#include <Shapes/CompositeShape.hpp>
#include <Visitor/VisitorGetPosition.hpp>

CompositeShape::CompositeShape() {
	rotationCenter = new Vector2(0, 0);
}

CompositeShape::CompositeShape(std::vector<IShape*> shapes) {
	this->shapes = shapes;
}

CompositeShape::~CompositeShape() {
	for (auto shape : shapes)
		delete shape;
}

void CompositeShape::setMemento(IMemento * m){
	MementoComposite* savedState = (MementoComposite*)m;
	this->shapes = savedState->savedShapes;
}

IMemento * CompositeShape::createMemento(){
	std::vector<IShape*> newShapes;
	for (auto shape : shapes)
		newShapes.push_back(shape->clone());

	MementoComposite* state = new MementoComposite(newShapes);
	return state;
}

void CompositeShape::addShape(IShape* shape){
	shapes.push_back(shape);
	std::vector<Vector2*> rotationCenters;
	for (auto shape : shapes) {
		rotationCenters.push_back(shape->getOrigin());
	}

	rotationCenter->x = 0;
	rotationCenter->y = 0;

	for (auto origin : rotationCenters) {
		rotationCenter->x += origin->x;
		rotationCenter->y += origin->y;
	}

	rotationCenter->x = rotationCenter->x / rotationCenters.size();
	rotationCenter->y = rotationCenter->y / rotationCenters.size();
}

void CompositeShape::draw(){

}

//TODO: Maybe use a visitor or an iterator to do this operation on Composite (need to count each Shape)
// so this solution is temp
Vector2* CompositeShape::getPosition() {
	VisitorGetPosition* visitor = new VisitorGetPosition();
	this->accept(visitor);

	Vector2* position = new Vector2(visitor->getPosition()->x, visitor->getPosition()->y);
	delete visitor;
	return position;
}

Vector2* CompositeShape::getOrigin() {
	return rotationCenter;
}

IShape* CompositeShape::clone(){
	std::vector<IShape*> newShapes;
	for (auto shape : shapes) {
		newShapes.push_back(shape->clone());
	}

	return new CompositeShape(newShapes);
}

std::vector<IShape*> CompositeShape::getShapes() {
	return shapes;
}

void CompositeShape::accept(IVisitor* visitor) {
	visitor->visit(this);
}
