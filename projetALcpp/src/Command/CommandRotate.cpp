#include <Command/CommandRotate.hpp>
#include <Visitor/VisitorRotate.hpp>

CommandRotate::CommandRotate(Shape* shape, double angle) {
	this->shape = shape;
	this->angle = angle;
}

CommandRotate::~CommandRotate(){
	if (savedState != nullptr)
		delete savedState;
}

void CommandRotate::execute() {
	savedState = shape->createMemento();
	VisitorRotate* visitor = new VisitorRotate(shape->getOrigin(), angle);
	shape->accept(visitor);
	delete visitor;
}

void CommandRotate::unexecute() {
	shape->setMemento(savedState);
}

