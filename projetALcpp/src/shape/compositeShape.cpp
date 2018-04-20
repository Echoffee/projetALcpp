#include <compositeShape.hpp>

CompositeShape::CompositeShape() {

}

CompositeShape::CompositeShape(std::vector<IShape*> shapes) {
	this->shapes = shapes;
}

void CompositeShape::setMemento(IMemento * m){
	MementoComposite* savedState = (MementoComposite*)m;
	this->shapes = savedState->savedShapes;
}

IMemento * CompositeShape::createMemento(){
	std::vector<IShape*> newShapes;
	for (auto shape : shapes) {
		newShapes.push_back(shape->clone);
	}
	MementoComposite* state = new MementoComposite(newShapes);
	return state;
}

void CompositeShape::addShape(IShape* shape){
	shapes.push_back(shape);
}

void CompositeShape::draw(){

}

IShape* CompositeShape::clone(){
	std::vector<IShape*> newShapes;
	for (auto shape : shapes) {
		newShapes.push_back(&shape->clone);
	}

	return new CompositeShape(newShapes);
}
