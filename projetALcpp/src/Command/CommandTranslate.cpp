#include <Command/CommandTranslate.hpp>
#include <Visitor/VisitorTranslate.hpp>

CommandTranslate::CommandTranslate(float x, float y, Shape* shape) {
	this->shape = shape;
	direction = new Vector2(x, y);
}

CommandTranslate::~CommandTranslate() {
	delete direction;
	delete savedState;
}

void CommandTranslate::execute() {
	savedState = shape->createMemento();
	VisitorTranslate* visitor = new VisitorTranslate(new Vector2(direction->x, direction->y));
	shape->accept(visitor);
	delete visitor;
}

void CommandTranslate::unexecute() {
	shape->setMemento(savedState);
}
