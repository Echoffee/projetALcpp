#include <Shapes/CompositeShape.hpp>
#include <Visitor/VisitorGetPosition.hpp>
#include <algorithm>

CompositeShape::CompositeShape() {
	rotationCenter = new Vector2(0, 0);
}

CompositeShape::CompositeShape(std::vector<Shape*> shapes) {
	this->shapes = shapes;
}

CompositeShape::~CompositeShape() {
	for (auto shape : shapes)
		delete shape;
	delete rotationCenter;
	std::vector<Shape*>().swap(shapes);
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
	delete rotationCenter;
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
	CompositeShape* cloneShape = new CompositeShape();
	for (auto shape : shapes)
		cloneShape->addShape(shape->clone());

	return cloneShape;
}

std::vector<Shape*> CompositeShape::getShapes() {
	return shapes;
}

Shape * CompositeShape::getShape(int index)
{
	return shapes.at(index);
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
	return shapes.at(0)->getColorFill();
}

Color * CompositeShape::getColorLine()
{
	return shapes.at(0)->getColorLine();
}

std::vector<Vector2*> CompositeShape::getBounds()
{
	std::vector<Vector2*> result = std::vector<Vector2*>();
	std::vector<Vector2*> points = shapes.at(0)->getBounds();
	Vector2* tl = new Vector2(points.at(0)->x, points.at(0)->y);
	Vector2* br = new Vector2(points.at(0)->x, points.at(0)->y);
	for (auto s : shapes) {
		std::vector<Vector2*> tmpoints = s->getBounds();
		Vector2* p1 = tmpoints.at(0);
		Vector2* p2 = tmpoints.at(1);
		tl->x = (p1->x < tl->x ? p1->x : tl->x);
		tl->y = (p1->y < tl->y ? p1->y : tl->y);
		br->x = (p2->x > br->x ? p2->x : br->x);
		br->y = (p2->y > br->y ? p2->y : br->y);
	}

	result.push_back(tl);
	result.push_back(br);
	return result;
}

void CompositeShape::accept(Visitor* visitor) {
	visitor->visit(this);
	std::vector<Shape*> newShapes;

	for (auto shape : shapes)
		newShapes.push_back(shape->clone());

	for (auto shape : newShapes)
		shape->accept(visitor);

	for (auto shape : shapes)
		delete shape;
	std::vector<Shape*>().swap(shapes);
	//shapes.erase(shapes.begin(), shapes.end());

	this->shapes = newShapes;
}