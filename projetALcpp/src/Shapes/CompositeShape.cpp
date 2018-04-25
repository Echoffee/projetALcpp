#include <Shapes/CompositeShape.hpp>
#include <Visitor/VisitorGetPosition.hpp>

CompositeShape::CompositeShape() {
	rotationCenter = new Vector2(0, 0);
}

CompositeShape::CompositeShape(std::vector<Shape*> shapes) {
	this->shapes = shapes;
}

CompositeShape::~CompositeShape() {
	for (auto shape : shapes)
		delete shape;
}

void CompositeShape::setMemento(Memento * m){
	MementoComposite* savedState = (MementoComposite*)m;
	this->shapes = savedState->savedShapes;
}

Memento * CompositeShape::createMemento(){
	std::vector<Shape*> newShapes;
	for (auto shape : shapes)
		newShapes.push_back(shape->clone());

	MementoComposite* state = new MementoComposite(newShapes);
	return state;
}

void CompositeShape::addShape(Shape* shape){
	shapes.push_back(shape);
	rotationCenter = this->getPosition();
}

void CompositeShape::draw(){
	for (auto s : shapes)
		s->draw();
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

Shape* CompositeShape::clone(){
	std::vector<Shape*> newShapes;
	for (auto shape : shapes) {
		newShapes.push_back(shape->clone());
	}

	return new CompositeShape(newShapes);
}

std::vector<Shape*> CompositeShape::getShapes() {
	return shapes;
}

void CompositeShape::setColorFill(Color * color)
{
	for (auto shape : shapes)
		shape->setColorFill(color);
}

void CompositeShape::setColorLine(Color * color)
{
	for (auto shape : shapes)
		shape->setColorLine(color);
}

Color * CompositeShape::getColorFill()
{
	return new Color(255, 255, 255, 0);
}

Color * CompositeShape::getColorLine()
{
	return new Color(0, 255, 255, 128);
}

void CompositeShape::accept(Visitor* visitor) {
	visitor->visit(this);
	std::vector<Shape*> newShapes;

	for (auto shape : shapes)
		newShapes.push_back(shape->clone());

	for (auto shape : newShapes)
		shape->accept(visitor);
	this->shapes = newShapes;
}
